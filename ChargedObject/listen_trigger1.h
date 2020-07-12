#ifndef LISTEN_TRIGGER1_H
#define LISTEN_TRIGGER1_H

#include <QObject>
#include <QThread>
#include <QDebug>

class listen_trigger1 : public QObject
{
    Q_OBJECT
public:
    explicit listen_trigger1(QObject *parent = nullptr);

public slots:
    void ListenPort1(int port);

signals:
    void SigListenPort1(int port);


};

#endif // LISTEN_TRIGGER1_H
