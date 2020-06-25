#ifndef CHARGEDOBJECT_H
#define CHARGEDOBJECT_H

#include <QTcpServer>
#include <QTcpSocket>

class ChargedObject : QTcpServer
{
    Q_OBJECT
public:
    ChargedObject();

    ~ChargedObject();

    void StartListen();

    QTcpSocket * serverSocket;

public slots:
    void AcceptConnection();
    void ReplyToClient();



};

#endif // CHARGEDOBJECT_H
