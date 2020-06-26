#ifndef CHARGEDOBJECT_H
#define CHARGEDOBJECT_H

#include <QTcpServer>
#include <QTcpSocket>

#include "data_processor.h"

class ChargedObject : QTcpServer
{
    Q_OBJECT
public:
    ChargedObject();

    ~ChargedObject();

    void StartListen();

    void Init();

    QTcpSocket * serverSocket;

    data_processor * msg_processor;


public slots:
    void AcceptConnection();
    void ReadMsg();

    void SendMsg(QByteArray *data2send);



};

#endif // CHARGEDOBJECT_H
