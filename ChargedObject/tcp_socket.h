#ifndef TCP_SOCKET_H
#define TCP_SOCKET_H


#include <QObject>
#include <QTcpSocket>

class tcp_socket : public QTcpSocket
{
    Q_OBJECT
public:
    tcp_socket(const int handle);

    void slot_readData();
signals:
    void sig_disconnect(int);
    void sig_readyRead(int, const QByteArray&);

private slots:
    void slot_disconnect();

private:
    int m_handle;

};

#endif // TCP_SOCKET_H
