#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->Init();

}

Widget::~Widget()
{
    delete ui;

    delete server;
}


void Widget::Init()
{
    server = new  ChargedObject;
}

void Widget::on_startlistening_clicked()
{
    server->StartListen();
}
