/****************************************************************************
** Meta object code from reading C++ file 'jwserialthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../jwserialthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jwserialthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_jwSerialThread_t {
    QByteArrayData data[9];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_jwSerialThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_jwSerialThread_t qt_meta_stringdata_jwSerialThread = {
    {
QT_MOC_LITERAL(0, 0, 14), // "jwSerialThread"
QT_MOC_LITERAL(1, 15, 15), // "sendResulttoGUI"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "Data"
QT_MOC_LITERAL(4, 37, 10), // "doDataSend"
QT_MOC_LITERAL(5, 48, 4), // "data"
QT_MOC_LITERAL(6, 53, 13), // "doDataReceive"
QT_MOC_LITERAL(7, 67, 14), // "jwSerialConfig"
QT_MOC_LITERAL(8, 82, 8) // "portname"

    },
    "jwSerialThread\0sendResulttoGUI\0\0Data\0"
    "doDataSend\0data\0doDataReceive\0"
    "jwSerialConfig\0portname"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_jwSerialThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x0a /* Public */,
       6,    0,   40,    2, 0x0a /* Public */,
       7,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void jwSerialThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        jwSerialThread *_t = static_cast<jwSerialThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendResulttoGUI((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->doDataSend((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->doDataReceive(); break;
        case 3: _t->jwSerialConfig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (jwSerialThread::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&jwSerialThread::sendResulttoGUI)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject jwSerialThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_jwSerialThread.data,
      qt_meta_data_jwSerialThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *jwSerialThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *jwSerialThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_jwSerialThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int jwSerialThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void jwSerialThread::sendResulttoGUI(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
