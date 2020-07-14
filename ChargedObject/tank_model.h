#ifndef TANK_MODEL_H
#define TANK_MODEL_H

#include <QObject>

typedef struct Paras//对象已知参数
{
    double yk_1;
    double yk_2;
    double uk_1;
    double uk_2;
    double uk_3;
    double uk_4;
}paras;

class tank_model : public QObject
{
    Q_OBJECT
public:
    explicit tank_model(QObject *parent = nullptr);
    paras tank_paras;
    double output(double uk, double yk);

signals:

};

#endif // TANK_MODEL_H
