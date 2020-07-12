#ifndef CHARGEDOBJECT_H
#define CHARGEDOBJECT_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>

#include "tcp_socket.h"



class ChargedObject : public QTcpServer
{
    Q_OBJECT
public:
    ChargedObject();

    ~ChargedObject();

    virtual void incomingConnection(qintptr handle) override;



    void Init();


signals:
     void ClientConnected(int, QTcpSocket*);
     void ClientDisconnected(int);
     void DataReady(int, const QByteArray &data);

     void StartListen(int port);

public slots:

    void SendMsg(QTcpSocket * sender, QByteArray *data2send);




};

#endif // CHARGEDOBJECT_H
