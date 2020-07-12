#ifndef DATA_PROCESSOR_H
#define DATA_PROCESSOR_H

#include <QByteArray>
#include <QString>
#include <QDebug>
#include <QObject>
#include "JQChecksum.h"
typedef struct ParseData
{    QByteArray id;
     QByteArray valid_data;
}ParsedResult ;

class data_processor : public QObject
{
    Q_OBJECT
public:
    explicit data_processor(QObject *parent = nullptr);
    QByteArray packer(QByteArray data2send, QByteArray id);
    void unpacker(QByteArray recv_data);
    QByteArray data_pool;
signals:
    void ValidDataReady(QByteArray data);

private:
    QByteArray  head;
    QByteArray  id;
    int min_frame;


    void Init();


};
#endif // DATA_PROCESSOR_H

