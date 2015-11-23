/****************************************************************************
** Meta object code from reading C++ file 'armcontrolgui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ArmGui/armcontrolgui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'armcontrolgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ArmControlGui_t {
    QByteArrayData data[9];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArmControlGui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArmControlGui_t qt_meta_stringdata_ArmControlGui = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ArmControlGui"
QT_MOC_LITERAL(1, 14, 12), // "jointsSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "value"
QT_MOC_LITERAL(4, 34, 14), // "listShapeClick"
QT_MOC_LITERAL(5, 49, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 66, 12), // "btnSaveShape"
QT_MOC_LITERAL(7, 79, 12), // "btnLoadShape"
QT_MOC_LITERAL(8, 92, 14) // "btnDeleteShape"

    },
    "ArmControlGui\0jointsSignal\0\0value\0"
    "listShapeClick\0QListWidgetItem*\0"
    "btnSaveShape\0btnLoadShape\0btnDeleteShape"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArmControlGui[] = {

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
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       6,    0,   45,    2, 0x08 /* Private */,
       7,    0,   46,    2, 0x08 /* Private */,
       8,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ArmControlGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ArmControlGui *_t = static_cast<ArmControlGui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->jointsSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->listShapeClick((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->btnSaveShape(); break;
        case 3: _t->btnLoadShape(); break;
        case 4: _t->btnDeleteShape(); break;
        default: ;
        }
    }
}

const QMetaObject ArmControlGui::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ArmControlGui.data,
      qt_meta_data_ArmControlGui,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ArmControlGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArmControlGui::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ArmControlGui.stringdata0))
        return static_cast<void*>(const_cast< ArmControlGui*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ArmControlGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
