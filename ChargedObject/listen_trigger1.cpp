#include "listen_trigger1.h"

listen_trigger1::listen_trigger1(QObject *parent) : QObject(parent)
{

}


void listen_trigger1::ListenPort1(int port)
{
    emit SigListenPort1(port);
    QString LogInfo;
    LogInfo.sprintf("%p", QThread::currentThread());
    qDebug() <<"threadID : "<<LogInfo;
}
