#include "chargedobject.h"

ChargedObject::ChargedObject()
{
    serverSocket = new QTcpSocket;
}

ChargedObject::~ChargedObject()
{
    delete serverSocket;

    delete msg_processor;
}

void ChargedObject::Init()
{
    msg_processor = new data_processor;
}

void ChargedObject::StartListen()
{
    this->listen(QHostAddress::Any,9999);
        //连接信号与槽，若有连接过来则接收连接
    connect(this,SIGNAL(newConnection()),this,SLOT(AcceptConnection()));
}

void ChargedObject::AcceptConnection()
{
    serverSocket = this->nextPendingConnection();
        //为服务端socket建立信号与槽以响应客户端来信
    connect(serverSocket,SIGNAL(readyRead()),this,SLOT(ReadMsg()));
}

void ChargedObject::ReadMsg()
{
    //接收客户端信息
    QByteArray msg=QString(serverSocket->readAll()).toLatin1();
    //打印客户端来信
    qDebug()<<msg;

    msg_processor->unpacker(msg);

}

void ChargedObject::SendMsg(QByteArray * data2send)
{
    if(serverSocket != nullptr && !data2send->isEmpty()) //确保有客户端连接，并且发送内容不为空
        {
            serverSocket->write(* data2send);   //发送消息到客户端
    }

}
