/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChargedObject/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[24];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 14), // "StartSampling0"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "msec"
QT_MOC_LITERAL(4, 28, 14), // "StartSampling1"
QT_MOC_LITERAL(5, 43, 13), // "StopSampling0"
QT_MOC_LITERAL(6, 57, 13), // "StopSampling1"
QT_MOC_LITERAL(7, 71, 15), // "ProccessingCall"
QT_MOC_LITERAL(8, 87, 4), // "data"
QT_MOC_LITERAL(9, 92, 14), // "SlotDisconnect"
QT_MOC_LITERAL(10, 107, 6), // "handle"
QT_MOC_LITERAL(11, 114, 11), // "SlotConnect"
QT_MOC_LITERAL(12, 126, 11), // "QTcpSocket*"
QT_MOC_LITERAL(13, 138, 6), // "socket"
QT_MOC_LITERAL(14, 145, 25), // "on_startlistening_clicked"
QT_MOC_LITERAL(15, 171, 12), // "SlotReadData"
QT_MOC_LITERAL(16, 184, 9), // "Sampling0"
QT_MOC_LITERAL(17, 194, 9), // "Sampling1"
QT_MOC_LITERAL(18, 204, 12), // "GetValidData"
QT_MOC_LITERAL(19, 217, 2), // "id"
QT_MOC_LITERAL(20, 220, 15), // "proccessed_data"
QT_MOC_LITERAL(21, 236, 22), // "on_send2client_clicked"
QT_MOC_LITERAL(22, 259, 25), // "on_stop_sampling0_clicked"
QT_MOC_LITERAL(23, 285, 25) // "on_stop_sampling1_clicked"

    },
    "Widget\0StartSampling0\0\0msec\0StartSampling1\0"
    "StopSampling0\0StopSampling1\0ProccessingCall\0"
    "data\0SlotDisconnect\0handle\0SlotConnect\0"
    "QTcpSocket*\0socket\0on_startlistening_clicked\0"
    "SlotReadData\0Sampling0\0Sampling1\0"
    "GetValidData\0id\0proccessed_data\0"
    "on_send2client_clicked\0on_stop_sampling0_clicked\0"
    "on_stop_sampling1_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       5,    0,   95,    2, 0x06 /* Public */,
       6,    0,   96,    2, 0x06 /* Public */,
       7,    1,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,  100,    2, 0x0a /* Public */,
      11,    2,  103,    2, 0x0a /* Public */,
      14,    0,  108,    2, 0x0a /* Public */,
      15,    2,  109,    2, 0x0a /* Public */,
      16,    0,  114,    2, 0x0a /* Public */,
      17,    0,  115,    2, 0x0a /* Public */,
      18,    2,  116,    2, 0x0a /* Public */,
      21,    0,  121,    2, 0x08 /* Private */,
      22,    0,  122,    2, 0x08 /* Private */,
      23,    0,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 12,   10,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray,   10,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,   19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->StartSampling0((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->StartSampling1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->StopSampling0(); break;
        case 3: _t->StopSampling1(); break;
        case 4: _t->ProccessingCall((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->SlotDisconnect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->SlotConnect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QTcpSocket*(*)>(_a[2]))); break;
        case 7: _t->on_startlistening_clicked(); break;
        case 8: _t->SlotReadData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 9: _t->Sampling0(); break;
        case 10: _t->Sampling1(); break;
        case 11: _t->GetValidData((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 12: _t->on_send2client_clicked(); break;
        case 13: _t->on_stop_sampling0_clicked(); break;
        case 14: _t->on_stop_sampling1_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::StartSampling0)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Widget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::StartSampling1)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::StopSampling0)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::StopSampling1)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Widget::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::ProccessingCall)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Widget::StartSampling0(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget::StartSampling1(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Widget::StopSampling0()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Widget::StopSampling1()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Widget::ProccessingCall(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
