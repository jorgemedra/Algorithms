/****************************************************************************
** Meta object code from reading C++ file 'graphwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../graphwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphWidget_t {
    QByteArrayData data[13];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphWidget_t qt_meta_stringdata_GraphWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GraphWidget"
QT_MOC_LITERAL(1, 12, 11), // "errorRaised"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "code"
QT_MOC_LITERAL(4, 30, 11), // "nodeCreated"
QT_MOC_LITERAL(5, 42, 6), // "GNode*"
QT_MOC_LITERAL(6, 49, 4), // "node"
QT_MOC_LITERAL(7, 54, 14), // "nodesConnected"
QT_MOC_LITERAL(8, 69, 7), // "nodeIni"
QT_MOC_LITERAL(9, 77, 7), // "nodeFin"
QT_MOC_LITERAL(10, 85, 6), // "GEdge*"
QT_MOC_LITERAL(11, 92, 4), // "edge"
QT_MOC_LITERAL(12, 97, 11) // "nodePressed"

    },
    "GraphWidget\0errorRaised\0\0code\0nodeCreated\0"
    "GNode*\0node\0nodesConnected\0nodeIni\0"
    "nodeFin\0GEdge*\0edge\0nodePressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       7,    3,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 10,    8,    9,   11,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void GraphWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphWidget *_t = static_cast<GraphWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->errorRaised((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->nodeCreated((*reinterpret_cast< GNode*(*)>(_a[1]))); break;
        case 2: _t->nodesConnected((*reinterpret_cast< GNode*(*)>(_a[1])),(*reinterpret_cast< GNode*(*)>(_a[2])),(*reinterpret_cast< GEdge*(*)>(_a[3]))); break;
        case 3: _t->nodePressed((*reinterpret_cast< GNode*(*)>(_a[1]))); break;
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
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GNode* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GraphWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphWidget::errorRaised)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GraphWidget::*_t)(GNode * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphWidget::nodeCreated)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GraphWidget::*_t)(GNode * , GNode * , GEdge * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphWidget::nodesConnected)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject GraphWidget::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_GraphWidget.data,
      qt_meta_data_GraphWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GraphWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GraphWidget.stringdata0))
        return static_cast<void*>(const_cast< GraphWidget*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int GraphWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GraphWidget::errorRaised(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphWidget::nodeCreated(GNode * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GraphWidget::nodesConnected(GNode * _t1, GNode * _t2, GEdge * _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
