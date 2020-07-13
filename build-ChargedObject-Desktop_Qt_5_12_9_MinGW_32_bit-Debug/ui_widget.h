/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *startlistening;
    QPushButton *send2client;
    QPushButton *sampling;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        startlistening = new QPushButton(Widget);
        startlistening->setObjectName(QString::fromUtf8("startlistening"));
        startlistening->setGeometry(QRect(110, 110, 93, 28));
        send2client = new QPushButton(Widget);
        send2client->setObjectName(QString::fromUtf8("send2client"));
        send2client->setGeometry(QRect(380, 310, 93, 28));
        sampling = new QPushButton(Widget);
        sampling->setObjectName(QString::fromUtf8("sampling"));
        sampling->setGeometry(QRect(130, 230, 93, 28));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        startlistening->setText(QApplication::translate("Widget", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
        send2client->setText(QApplication::translate("Widget", "send2client", nullptr));
        sampling->setText(QApplication::translate("Widget", "sampling", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
