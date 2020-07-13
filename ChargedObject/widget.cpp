 #include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);

    this->Init();


}

Widget::~Widget()
{
    delete data_proccessing_thread;
    delete sampling_thread;

    data_proccessing_thread->wait();
    data_proccessing_thread->quit();

    sampling_thread->wait();
    sampling_thread->quit();



    delete ui;

    delete server1;
    delete server2;

    delete msg_processor;

    delete socket_thread;
    delete data_proccessing_thread;
    delete sampling_thread;

    delete sampling_timer;

    delete yk_queue;

    delete tank_model1;

}


void Widget::Init()
{
    QString LogInfo;
    LogInfo.sprintf("%p", QThread::currentThread());
    qDebug() <<"MainthreadID : "<<LogInfo;

    server1 = new  ChargedObject;
    server2 = new  ChargedObject;

    msg_processor = new data_processor;

    data_proccessing_thread = new QThread;

    msg_processor->moveToThread(data_proccessing_thread);

    connect(this, SIGNAL(ProccessingCall(QByteArray)), msg_processor, SLOT(ProccessingTask(QByteArray)));

    connect(msg_processor, SIGNAL(ValidDataReady(QByteArray, QByteArray )), this, SLOT(GetValidData(QByteArray , QByteArray )));

    data_proccessing_thread->start();

    sampling_thread = new QThread;

    sampling_timer = new QTimer;

    sampling_timer->moveToThread(sampling_thread);

    yk_queue = new QQueue<QByteArray>;

    tank_model1 = new tank_model;

    current_yk = 0;

}

void Widget::on_startlistening_clicked()
{

    connect(server1,&ChargedObject::ClientConnected,this,&Widget::SlotConnect);
    connect(server2,&ChargedObject::ClientConnected,this,&Widget::SlotConnect);

    server1->listen(QHostAddress::Any, 9999);
    server2->listen(QHostAddress::Any, 9998);

}


void Widget::SlotConnect(int handle, QTcpSocket *socket)
{
    qDebug()<<"port";
    socket_map.insert(handle, socket);

    connect(socket_map.value(handle),SIGNAL(sig_disconnect(int)),this,SLOT(SlotDisconnect(int)));
    connect(socket_map.value(handle),SIGNAL(sig_readyRead(int, QByteArray)),this,SLOT(SlotReadData(int,QByteArray)));
}

void Widget::SlotDisconnect(int handle)
{
    socket_map.remove(handle);
    qDebug()<<handle<<" disconnect";
}

void Widget::SlotReadData(int handle, const QByteArray &data)
{
    qDebug()<<"handle "<<handle<<" data: "<<QString(data);

    emit ProccessingCall(data);
}

void Widget::GetValidData(QByteArray id, QByteArray proccessed_data)
{
    qDebug()<<"GetValidData id is :"<<id;

    if(id==msg_processor->id_list.at(2))
    {//处理命令帧
       qDebug()<<"开始调节";

       emit StartSampling(500);


    }
    else
    {//不是命令帧的话，就处理正常数据帧
    qDebug()<<"proccessed_data is : "<<proccessed_data;

    bool ok;

    int int_uk = proccessed_data.toInt(&ok, 16);

    double times = 1000;
    double double_uk = int_uk;

    double real_uk = double_uk / times;

    qDebug()<<"real_uk is :"<< real_uk;

    current_yk = tank_model1->output(real_uk);

    qDebug()<< "current_yk is : "<<current_yk;

    }
}

void Widget::on_send2client_clicked()
{
    int u2=14;

    QByteArray data2send2 = QByteArray::number(u2,16);

    int id=1;


    QByteArray  msg2 = msg_processor->packer(data2send2,id);

    server1->SendMsg(socket_map.first(),&msg2);
}

void Widget::on_sampling_clicked()
{
    QString LogInfo;
    LogInfo.sprintf("%p", QThread::currentThread());
    qDebug() <<"Main threadID : "<<LogInfo;

    connect(this , SIGNAL(StartSampling(int)),sampling_timer,SLOT(start(int)));

    connect(sampling_timer,SIGNAL(timeout()),this,SLOT(Sampling()));

    sampling_thread->start();

    emit StartSampling(500);


}

void Widget::Sampling()
{
 //发送当前yk给控制器
    int times = 1000;

    int int_current_yk = current_yk * times;

    QByteArray data2send = QByteArray::number(int_current_yk,16);

    int id=1;

    QByteArray  msg = msg_processor->packer(data2send,id);

    qDebug()<<"sending yk...";

    server1->SendMsg(socket_map.first(),&msg);

}
