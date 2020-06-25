#include "chargedobject.h"

ChargedObject::ChargedObject()
{
    serverSocket = new QTcpSocket;
}

ChargedObject::~ChargedObject()
{
    delete serverSocket;
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
    connect(serverSocket,SIGNAL(readyRead()),this,SLOT(ReplyToClient()));
}

void ChargedObject::ReplyToClient()
{
    //接收客户端信息
    QString msg=QString(serverSocket->readAll());
    //打印客户端来信
    qDebug()<<msg;
    //构造回复字符串
    const char * replyMsg="server:I am server,I got your message.";
    //将回复字符串发送给客户端
    serverSocket->write(replyMsg);
}
