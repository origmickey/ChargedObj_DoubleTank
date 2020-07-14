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

#include "tank_model.h"


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



    QThread * socket_thread;
    QThread * data_proccessing_thread;

    QList<QThread*>  * sampling_thread;

    ChargedObject * server;

    QList<QTimer*> * sampling_timer;

    QList<tank_model*> * tank;

    QList<double> * current_yk;

    QMap<int, QThread*> socket_thread_map;



signals:
    void StartSampling0(int msec);
    void StartSampling1(int msec);

    void ProccessingCall(QByteArray data);

public slots:
    void SlotDisconnect(int handle);
    void SlotConnect(int handle, QTcpSocket *socket);
    void on_startlistening_clicked();
    void SlotReadData(int handle, const QByteArray &data);
    void Sampling0();
    void Sampling1();

    void GetValidData(QByteArray id , QByteArray proccessed_data);


private slots:
    void on_send2client_clicked();

private:
    Ui::Widget *ui;

    QMap<int, QTcpSocket*> socket_map;




};
#endif // WIDGET_H
