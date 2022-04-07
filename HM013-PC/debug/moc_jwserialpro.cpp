/****************************************************************************
** Meta object code from reading C++ file 'jwserialpro.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../jwserialpro.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jwserialpro.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_jwSerialPro_t {
    QByteArrayData data[17];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_jwSerialPro_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_jwSerialPro_t qt_meta_stringdata_jwSerialPro = {
    {
QT_MOC_LITERAL(0, 0, 11), // "jwSerialPro"
QT_MOC_LITERAL(1, 12, 14), // "signal_message"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "str"
QT_MOC_LITERAL(4, 32, 23), // "signal_portstatuschange"
QT_MOC_LITERAL(5, 56, 4), // "flag"
QT_MOC_LITERAL(6, 61, 15), // "signal_byteRead"
QT_MOC_LITERAL(7, 77, 4), // "data"
QT_MOC_LITERAL(8, 82, 16), // "signal_byteWrite"
QT_MOC_LITERAL(9, 99, 23), // "signal_deleteportobject"
QT_MOC_LITERAL(10, 123, 14), // "slot_readBytes"
QT_MOC_LITERAL(11, 138, 15), // "slot_writeBytes"
QT_MOC_LITERAL(12, 154, 12), // "slot_process"
QT_MOC_LITERAL(13, 167, 4), // "open"
QT_MOC_LITERAL(14, 172, 6), // "string"
QT_MOC_LITERAL(15, 179, 8), // "baudrate"
QT_MOC_LITERAL(16, 188, 5) // "close"

    },
    "jwSerialPro\0signal_message\0\0str\0"
    "signal_portstatuschange\0flag\0"
    "signal_byteRead\0data\0signal_byteWrite\0"
    "signal_deleteportobject\0slot_readBytes\0"
    "slot_writeBytes\0slot_process\0open\0"
    "string\0baudrate\0close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_jwSerialPro[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,
       8,    1,   73,    2, 0x06 /* Public */,
       9,    0,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   77,    2, 0x0a /* Public */,
      11,    1,   78,    2, 0x0a /* Public */,
      12,    0,   81,    2, 0x0a /* Public */,
      13,    2,   82,    2, 0x0a /* Public */,
      16,    0,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   14,   15,
    QMetaType::Void,

       0        // eod
};

void jwSerialPro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        jwSerialPro *_t = static_cast<jwSerialPro *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->signal_portstatuschange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->signal_byteRead((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->signal_byteWrite((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->signal_deleteportobject(); break;
        case 5: _t->slot_readBytes(); break;
        case 6: _t->slot_writeBytes((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->slot_process(); break;
        case 8: _t->open((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< qint32(*)>(_a[2]))); break;
        case 9: _t->close(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (jwSerialPro::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&jwSerialPro::signal_message)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (jwSerialPro::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&jwSerialPro::signal_portstatuschange)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (jwSerialPro::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&jwSerialPro::signal_byteRead)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (jwSerialPro::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&jwSerialPro::signal_byteWrite)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (jwSerialPro::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&jwSerialPro::signal_deleteportobject)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject jwSerialPro::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_jwSerialPro.data,
      qt_meta_data_jwSerialPro,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *jwSerialPro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *jwSerialPro::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_jwSerialPro.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int jwSerialPro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void jwSerialPro::signal_message(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void jwSerialPro::signal_portstatuschange(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void jwSerialPro::signal_byteRead(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void jwSerialPro::signal_byteWrite(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void jwSerialPro::signal_deleteportobject()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
