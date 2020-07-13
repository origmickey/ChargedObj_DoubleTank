#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QList>
#include <QThread>
#include <QTimer>
#include <QQueue>

#include "chargedobject.h"

#include "data_processor.h"

#include "listen_trigger1.h"
#include "listen_trigger2.h"



QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void Init();

    data_processor * msg_processor;

//    listen_trigger1 * trigger1;
//    listen_trigger2 * trigger2;

//    QThread * listen_thread1;
//    QThread * listen_thread2;

    QTimer * sampling_timer;

    QThread * socket_thread;
    QThread * data_proccessing_thread;
    QThread * sampling_thread;

    ChargedObject * server1;
    ChargedObject * server2;

    QQueue<QByteArray> * yk_queue;

signals:
//    void start_listen1(int port);
//    void start_listen2(int port);

    void StartSampling(int msec);

    void ProccessingCall(QByteArray data);

public slots:
    void SlotDisconnect(int handle);
    void SlotConnect(int handle, QTcpSocket *socket);
    void on_startlistening_clicked();
    void SlotReadData(int handle, const QByteArray &data);
//    void server_listen1(int port);
//    void server_listen2(int port);
    void Sampling();

    void GetValidData(QByteArray id , QByteArray proccessed_data);


private slots:
    void on_send2client_clicked();

    void on_sampling_clicked();

private:
    Ui::Widget *ui;

    QMap<int, QTcpSocket*> socket_map;



};
#endif // WIDGET_H
