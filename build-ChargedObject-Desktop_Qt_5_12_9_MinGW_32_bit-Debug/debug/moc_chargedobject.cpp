/****************************************************************************
** Meta object code from reading C++ file 'chargedobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "C:/Users/andrew/Desktop/ChargedObj_DoubleTank-061393602fc7ed0dccd75a4bc6de038752ab16b7/ChargedObject/chargedobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chargedobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChargedObject_t {
    QByteArrayData data[13];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChargedObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChargedObject_t qt_meta_stringdata_ChargedObject = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ChargedObject"
QT_MOC_LITERAL(1, 14, 15), // "ClientConnected"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "QTcpSocket*"
QT_MOC_LITERAL(4, 43, 18), // "ClientDisconnected"
QT_MOC_LITERAL(5, 62, 9), // "DataReady"
QT_MOC_LITERAL(6, 72, 4), // "data"
QT_MOC_LITERAL(7, 77, 11), // "StartListen"
QT_MOC_LITERAL(8, 89, 4), // "port"
QT_MOC_LITERAL(9, 94, 7), // "SendMsg"
QT_MOC_LITERAL(10, 102, 6), // "sender"
QT_MOC_LITERAL(11, 109, 11), // "QByteArray*"
QT_MOC_LITERAL(12, 121, 9) // "data2send"

    },
    "ChargedObject\0ClientConnected\0\0"
    "QTcpSocket*\0ClientDisconnected\0DataReady\0"
    "data\0StartListen\0port\0SendMsg\0sender\0"
    "QByteArray*\0data2send"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChargedObject[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       4,    1,   44,    2, 0x06 /* Public */,
       5,    2,   47,    2, 0x06 /* Public */,
       7,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray,    2,    6,
    QMetaType::Void, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 11,   10,   12,

       0        // eod
};

void ChargedObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChargedObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ClientConnected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QTcpSocket*(*)>(_a[2]))); break;
        case 1: _t->ClientDisconnected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->DataReady((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 3: _t->StartListen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->SendMsg((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< QByteArray*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChargedObject::*)(int , QTcpSocket * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChargedObject::ClientConnected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ChargedObject::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChargedObject::ClientDisconnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ChargedObject::*)(int , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChargedObject::DataReady)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ChargedObject::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChargedObject::StartListen)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChargedObject::staticMetaObject = { {
    &QTcpServer::staticMetaObject,
    qt_meta_stringdata_ChargedObject.data,
    qt_meta_data_ChargedObject,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChargedObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChargedObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChargedObject.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int ChargedObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ChargedObject::ClientConnected(int _t1, QTcpSocket * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChargedObject::ClientDisconnected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChargedObject::DataReady(int _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChargedObject::StartListen(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
