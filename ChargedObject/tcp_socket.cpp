#include "tcp_socket.h"

tcp_socket::tcp_socket(const int handle) : m_handle(handle)
{
    this->setSocketDescriptor(m_handle);
    connect(this,&tcp_socket::disconnected,this,&tcp_socket::slot_disconnect);
    connect(this,&tcp_socket::readyRead,this,&tcp_socket::slot_readData);
}

void tcp_socket::slot_disconnect()
{
    emit sig_disconnect(m_handle);
}

void tcp_socket::slot_readData()
{
    qDebug()<<"you have a msg";
    QByteArray data = readAll();
    emit sig_readyRead(m_handle, data);
}
