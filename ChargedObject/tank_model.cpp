#include "tank_model.h"
#include <QDebug>

tank_model::tank_model(QObject *parent) : QObject(parent)
{
    tank_paras={0,0,0,0,0,0};
}


double tank_model::output(double uk,   double yk)
{


    qDebug()<<"yk_1 is : "<<tank_paras.yk_1;
    qDebug()<<"yk_2 is : "<<tank_paras.yk_2;
    qDebug()<<"uk_1 is : "<<tank_paras.uk_1;
    qDebug()<<"uk_2 is : "<<tank_paras.uk_2;
    qDebug()<<"uk_3 is : "<<tank_paras.uk_3;
    qDebug()<<"uk_4 is : "<<tank_paras.uk_4;

    yk=1.699*tank_paras.yk_1-0.7165*tank_paras.yk_2+0.1213*tank_paras.uk_3+0.1086*tank_paras.uk_4;
        //更新控制器结构体参数
    tank_paras.uk_4=tank_paras.uk_3;
    tank_paras.uk_3=tank_paras.uk_2;
    tank_paras.uk_2=tank_paras.uk_1;
    tank_paras.uk_1=uk;
    tank_paras.yk_2=tank_paras.yk_1;
    tank_paras.yk_1=yk;

    return yk;
}
