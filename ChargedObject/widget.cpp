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

    sampling_thread->at(0)->wait();
    sampling_thread->at(1)->quit();

    delete tank;
    delete current_yk;

    delete ui;

    delete server;


    delete msg_processor;

    delete socket_thread;
    delete data_proccessing_thread;
    delete sampling_thread;

    delete sampling_timer;


}


void Widget::Init()
{
//    QString LogInfo;
//    LogInfo.sprintf("%p", QThread::currentThread());
//    qDebug() <<"MainthreadID : "<<LogInfo;

    server = new  ChargedObject;


    msg_processor = new data_processor;

    data_proccessing_thread = new QThread;

    msg_processor->moveToThread(data_proccessing_thread);

    connect(this, SIGNAL(ProccessingCall(QByteArray)), msg_processor, SLOT(ProccessingTask(QByteArray)));

    connect(msg_processor, SIGNAL(ValidDataReady(QByteArray, QByteArray )), this, SLOT(GetValidData(QByteArray , QByteArray )));

    data_proccessing_thread->start();

    QThread * sampling_thread0 = new QThread;

    QThread * sampling_thread1 = new QThread;

    sampling_thread = new QList<QThread*>;

    sampling_thread->append(sampling_thread0);
    sampling_thread->append(sampling_thread1);

    QTimer  * sampling_timer0 = new QTimer;
    QTimer  * sampling_timer1 = new QTimer;

    sampling_timer = new QList<QTimer*>;

    sampling_timer->append(sampling_timer0);
    sampling_timer->append(sampling_timer1);

    sampling_timer->at(0)->moveToThread(sampling_thread->at(0));
    sampling_timer->at(1)->moveToThread(sampling_thread->at(1));

    tank =  new QList<tank_model*>();

    tank_model  * tank0 = new tank_model;
    tank_model * tank1 = new tank_model;

    tank->append(tank0);
    tank->append(tank1);

    current_yk =  new QList<double>();
    double current_yk0 = 0;
    double current_yk1 = 0;
    current_yk->append(current_yk0);
    current_yk->append(current_yk1);



}

void Widget::on_startlistening_clicked()
{

    connect(server,&ChargedObject::ClientConnected,this,&Widget::SlotConnect);


    server->listen(QHostAddress::Any, 9999);

}


void Widget::SlotConnect(int handle, QTcpSocket *socket)
{

    socket_map.insert(handle, socket);

    connect(socket_map.value(handle),SIGNAL(sig_disconnect(int)),this,SLOT(SlotDisconnect(int)));
    connect(socket_map.value(handle),SIGNAL(sig_readyRead(int, QByteArray)),this,SLOT(SlotReadData(int,QByteArray)));

    QThread * new_socket_thread = new QThread;

    socket_thread_map.insert(handle,new_socket_thread);

    socket_map.value(handle)->moveToThread(socket_thread_map.value(handle));

    socket_thread_map.value(handle)->start();
}

void Widget::SlotDisconnect(int handle)
{
    socket_map.remove(handle);
    qDebug()<<handle<<" disconnect";
}

void Widget::SlotReadData(int handle, const QByteArray &data)
{
//    qDebug()<<"handle "<<handle<<" data: "<<QString(data);

    emit ProccessingCall(data);
}

void Widget::GetValidData(QByteArray id, QByteArray proccessed_data)
{
    int index = msg_processor->id_list.indexOf(id);
    switch (index) {
    case 0: {
        qDebug()<<"got uk0";
        bool ok;

        int int_uk = proccessed_data.toInt(&ok, 16);

        double times = 1000;
        double double_uk = int_uk;

        double real_uk = double_uk / times;

        qDebug()<<"real_uk0 is !!!!!!!!!!!!!!!!!:"<< real_uk;

        current_yk->replace(0, tank->at(0)->output(real_uk,current_yk->at(0)));

        qDebug()<< "current_yk0 is : "<<current_yk->at(0);

    }
    case 1: {
        qDebug()<<"got yk1";
    }
    case 2: {
        qDebug()<<"got start_adjustment order for tank0";
        //处理命令帧
               qDebug()<<"开始调节";
               connect(this , SIGNAL(StartSampling0(int)),sampling_timer->at(0),SLOT(start(int)));

               connect(sampling_timer->at(0),SIGNAL(timeout()),this,SLOT(Sampling0()));

               sampling_thread->at(0)->start();

               emit StartSampling0(500);
    }
    case 3: {
        qDebug()<<"got uk1";
        bool ok;

        int int_uk = proccessed_data.toInt(&ok, 16);

        double times = 1000;
        double double_uk = int_uk;

        double real_uk = double_uk / times;

        qDebug()<<"real_uk1 is !!!!!!!!!!!!!!!!!:"<< real_uk;

        current_yk->replace(1, tank->at(1)->output(real_uk,current_yk->at(1)));

        qDebug()<< "current_yk1 is : "<<current_yk->at(1);
    }
    case 4: {
        qDebug()<<"got yk2";
    }
    case 5: {
        qDebug()<<"got start_adjustment order for tank1";

        //处理命令帧
               qDebug()<<"开始调节";
               connect(this , SIGNAL(StartSampling1(int)),sampling_timer->at(1),SLOT(start(int)));

               connect(sampling_timer->at(1),SIGNAL(timeout()),this,SLOT(Sampling1()));

               sampling_thread->at(1)->start();

               emit StartSampling1(500);
    }

    }


    qDebug()<<"GetValidData id is :"<<id;

}

void Widget::on_send2client_clicked()
{
    int u2=14;

    QByteArray data2send2 = QByteArray::number(u2,16);

    int id=1;


    QByteArray  msg2 = msg_processor->packer(data2send2,id);

    server->SendMsg(socket_map.first(),&msg2);
}



void Widget::Sampling0()
{
 //发送当前yk给控制器
    int times = 1000;

    int int_current_yk0 = current_yk->at(0) * times;

    qDebug()<<"int_current_yk0 is : "<<current_yk->at(0);

    QByteArray data2send = QByteArray::number(int_current_yk0,16);

    qDebug()<<"yk0 data2send is :"<<data2send;

    int id=1;

    QByteArray  msg = msg_processor->packer(data2send,id);

    qDebug()<<"sending yk0... is : "<<current_yk->at(0);

    server->SendMsg(socket_map.first(),&msg);

}

void Widget::Sampling1()
{
 //发送当前yk给控制器
    int times = 1000;

    int int_current_yk1 = current_yk->at(1) * times;

    qDebug()<<"int_current_yk1 is : "<<current_yk->at(1);

    QByteArray data2send = QByteArray::number(int_current_yk1,16);

    qDebug()<<"yk1 data2send is :"<<data2send;

    int id=4;

    QByteArray  msg = msg_processor->packer(data2send,id);

    qDebug()<<"sending yk1... is : "<<current_yk->at(1);

    server->SendMsg(socket_map.first(),&msg);

}

