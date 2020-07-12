#ifndef LISTEN_TRIGGER2_H
#define LISTEN_TRIGGER2_H

#include <QObject>
#include <QThread>
#include <QDebug>
class listen_trigger2 : public QObject
{
    Q_OBJECT
public:
    explicit listen_trigger2(QObject *parent = nullptr);
public slots:
    void ListenPort2(int port);

signals:
    void SigListenPort2(int port);
};

#endif // LISTEN_TRIGGER2_H
