#include "listen_trigger2.h"

listen_trigger2::listen_trigger2(QObject *parent) : QObject(parent)
{

}

void listen_trigger2::ListenPort2(int port)
{
    emit SigListenPort2(port);
    QString LogInfo;
    LogInfo.sprintf("%p", QThread::currentThread());
    qDebug() <<"threadID : "<<LogInfo;
}
