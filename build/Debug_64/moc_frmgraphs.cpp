/****************************************************************************
** Meta object code from reading C++ file 'frmgraphs.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../frmgraphs.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmgraphs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_frmGraphFS_t {
    QByteArrayData data[12];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmGraphFS_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmGraphFS_t qt_meta_stringdata_frmGraphFS = {
    {
QT_MOC_LITERAL(0, 0, 10), // "frmGraphFS"
QT_MOC_LITERAL(1, 11, 11), // "errorRaised"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "code"
QT_MOC_LITERAL(4, 29, 11), // "nodeCreated"
QT_MOC_LITERAL(5, 41, 6), // "GNode*"
QT_MOC_LITERAL(6, 48, 4), // "node"
QT_MOC_LITERAL(7, 53, 14), // "nodesConnected"
QT_MOC_LITERAL(8, 68, 7), // "nodeIni"
QT_MOC_LITERAL(9, 76, 7), // "nodeFin"
QT_MOC_LITERAL(10, 84, 6), // "GEdge*"
QT_MOC_LITERAL(11, 91, 4) // "edge"

    },
    "frmGraphFS\0errorRaised\0\0code\0nodeCreated\0"
    "GNode*\0node\0nodesConnected\0nodeIni\0"
    "nodeFin\0GEdge*\0edge"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmGraphFS[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       7,    3,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 10,    8,    9,   11,

       0        // eod
};

void frmGraphFS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        frmGraphFS *_t = static_cast<frmGraphFS *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->errorRaised((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->nodeCreated((*reinterpret_cast< GNode*(*)>(_a[1]))); break;
        case 2: _t->nodesConnected((*reinterpret_cast< GNode*(*)>(_a[1])),(*reinterpret_cast< GNode*(*)>(_a[2])),(*reinterpret_cast< GEdge*(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GNode* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GNode* >(); break;
            }
            break;
        }
    }
}

const QMetaObject frmGraphFS::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_frmGraphFS.data,
      qt_meta_data_frmGraphFS,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *frmGraphFS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmGraphFS::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_frmGraphFS.stringdata0))
        return static_cast<void*>(const_cast< frmGraphFS*>(this));
    return QWidget::qt_metacast(_clname);
}

int frmGraphFS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
