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
//    listen_thread1->wait();
//    listen_thread1->quit();
//    listen_thread2->wait();
//    listen_thread2->quit();


    delete ui;

    delete server1;
    delete server2;

    delete msg_processor;

//    delete trigger1;
//    delete trigger2;

//    delete listen_thread1;
//    delete listen_thread2;


}


void Widget::Init()
{
    server1 = new  ChargedObject;
    server2 = new  ChargedObject;

    msg_processor = new data_processor;




//    trigger1 = new listen_trigger1;
//    trigger2 = new listen_trigger2;

//    listen_thread1 = new QThread(this);
//    listen_thread2 = new QThread(this);

//    trigger1->moveToThread(listen_thread1);
//    trigger2->moveToThread(listen_thread2);

//    listen_thread1->setObjectName("thread1");
//    listen_thread2->setObjectName("thread2");

//    connect(this,SIGNAL(start_listen1(int)),trigger1,SLOT(ListenPort1(int )));
//    connect(this,SIGNAL(start_listen2(int)),trigger2,SLOT(ListenPort2(int )));

//    listen_thread1->start();
//    listen_thread2->start();


}

void Widget::on_startlistening_clicked()
{

    connect(server1,&ChargedObject::ClientConnected,this,&Widget::SlotConnect);
    connect(server2,&ChargedObject::ClientConnected,this,&Widget::SlotConnect);



//    connect(trigger1,SIGNAL(SigListenPort1(int )),this, SLOT(server_listen1(int )));
//    connect(trigger2,SIGNAL(SigListenPort2(int )),this, SLOT(server_listen2(int )));


    server1->listen(QHostAddress::Any, 9999);
    server2->listen(QHostAddress::Any, 9998);
//    emit start_listen1(9999);
//    emit start_listen1(9998);



}



//void Widget::server_listen1(int port)
//{

//    server->listen(QHostAddress::Any, port);
//}

//void Widget::server_listen2(int port)
//{

//    server->listen(QHostAddress::Any, port);
//}


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



    msg_processor->unpacker(data);
}
