#include "chargedobject.h"

ChargedObject::ChargedObject()
{

    this->Init();

}

ChargedObject::~ChargedObject()
{


}

void ChargedObject::Init()
{

}

//void ChargedObject::StartListen(int port)
//{
//    this->listen(QHostAddress::Any,port);
//        //连接信号与槽，若有连接过来则接收连接
////    connect(this,SIGNAL(newConnection()),this,SLOT(AcceptConnection()));
//}


void ChargedObject::incomingConnection(qintptr handle)
{
    tcp_socket *socket = new tcp_socket(handle);

    emit ClientConnected(handle, socket);
}


void ChargedObject::SendMsg(QTcpSocket *sender, QByteArray * data2send)
{
    if(sender != nullptr && !data2send->isEmpty()) //确保有客户端连接，并且发送内容不为空
        {
            sender->write(* data2send);   //发送消息到客户端
    }

}
