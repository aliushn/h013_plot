/****************************************************************************
** Meta object code from reading C++ file 'jwserial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../jwserial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jwserial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_jwSerial_t {
    QByteArrayData data[8];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_jwSerial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_jwSerial_t qt_meta_stringdata_jwSerial = {
    {
QT_MOC_LITERAL(0, 0, 8), // "jwSerial"
QT_MOC_LITERAL(1, 9, 23), // "serial_signals_sendData"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 3), // "str"
QT_MOC_LITERAL(4, 38, 16), // "slot_startThread"
QT_MOC_LITERAL(5, 55, 15), // "slot_OpenSerial"
QT_MOC_LITERAL(6, 71, 19), // "slot_ReadSerialData"
QT_MOC_LITERAL(7, 91, 16) // "slot_CloseThread"

    },
    "jwSerial\0serial_signals_sendData\0\0str\0"
    "slot_startThread\0slot_OpenSerial\0"
    "slot_ReadSerialData\0slot_CloseThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_jwSerial[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void jwSerial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        jwSerial *_t = static_cast<jwSerial *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->serial_signals_sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slot_startThread(); break;
        case 2: _t->slot_OpenSerial(); break;
        case 3: _t->slot_ReadSerialData(); break;
        case 4: _t->slot_CloseThread(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (jwSerial::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&jwSerial::serial_signals_sendData)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject jwSerial::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_jwSerial.data,
      qt_meta_data_jwSerial,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *jwSerial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *jwSerial::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_jwSerial.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int jwSerial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void jwSerial::serial_signals_sendData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
