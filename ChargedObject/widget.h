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

    QTimer * sampling_timer;

    QThread * socket_thread;
    QThread * data_proccessing_thread;
    QThread * sampling_thread;

    ChargedObject * server1;
    ChargedObject * server2;

    QQueue<QByteArray> * yk_queue;

    tank_model * tank_model1;

    double current_yk;

signals:
    void StartSampling(int msec);

    void ProccessingCall(QByteArray data);

public slots:
    void SlotDisconnect(int handle);
    void SlotConnect(int handle, QTcpSocket *socket);
    void on_startlistening_clicked();
    void SlotReadData(int handle, const QByteArray &data);
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
