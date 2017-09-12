/****************************************************************************
** Meta object code from reading C++ file 'frmpriorityqueue.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../frmpriorityqueue.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmpriorityqueue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_frmPriorityQueue_t {
    QByteArrayData data[8];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmPriorityQueue_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmPriorityQueue_t qt_meta_stringdata_frmPriorityQueue = {
    {
QT_MOC_LITERAL(0, 0, 16), // "frmPriorityQueue"
QT_MOC_LITERAL(1, 17, 21), // "on_cmdAddItem_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 18), // "on_tblHeap_clicked"
QT_MOC_LITERAL(4, 59, 5), // "index"
QT_MOC_LITERAL(5, 65, 20), // "on_cmdDelete_clicked"
QT_MOC_LITERAL(6, 86, 19), // "on_cmdClear_clicked"
QT_MOC_LITERAL(7, 106, 24) // "on_cmdPurgeQueue_clicked"

    },
    "frmPriorityQueue\0on_cmdAddItem_clicked\0"
    "\0on_tblHeap_clicked\0index\0"
    "on_cmdDelete_clicked\0on_cmdClear_clicked\0"
    "on_cmdPurgeQueue_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmPriorityQueue[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    1,   40,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmPriorityQueue::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        frmPriorityQueue *_t = static_cast<frmPriorityQueue *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_cmdAddItem_clicked(); break;
        case 1: _t->on_tblHeap_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_cmdDelete_clicked(); break;
        case 3: _t->on_cmdClear_clicked(); break;
        case 4: _t->on_cmdPurgeQueue_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject frmPriorityQueue::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_frmPriorityQueue.data,
      qt_meta_data_frmPriorityQueue,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *frmPriorityQueue::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmPriorityQueue::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_frmPriorityQueue.stringdata0))
        return static_cast<void*>(const_cast< frmPriorityQueue*>(this));
    return QWidget::qt_metacast(_clname);
}

int frmPriorityQueue::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
