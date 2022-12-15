/****************************************************************************
** Meta object code from reading C++ file 'EnvironmentDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "EnvironmentDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EnvironmentDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EnvironmentItemModel_t {
    QByteArrayData data[7];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EnvironmentItemModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EnvironmentItemModel_t qt_meta_stringdata_EnvironmentItemModel = {
    {
QT_MOC_LITERAL(0, 0, 20), // "EnvironmentItemModel"
QT_MOC_LITERAL(1, 21, 14), // "appendVariable"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 3), // "key"
QT_MOC_LITERAL(4, 41, 5), // "value"
QT_MOC_LITERAL(5, 47, 14), // "insertVariable"
QT_MOC_LITERAL(6, 62, 3) // "row"

    },
    "EnvironmentItemModel\0appendVariable\0"
    "\0key\0value\0insertVariable\0row"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EnvironmentItemModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x0a /* Public */,
       5,    3,   29,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    6,    3,    4,

       0        // eod
};

void EnvironmentItemModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EnvironmentItemModel *_t = static_cast<EnvironmentItemModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->appendVariable((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->insertVariable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject EnvironmentItemModel::staticMetaObject = {
    { &QStandardItemModel::staticMetaObject, qt_meta_stringdata_EnvironmentItemModel.data,
      qt_meta_data_EnvironmentItemModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EnvironmentItemModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EnvironmentItemModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EnvironmentItemModel.stringdata0))
        return static_cast<void*>(this);
    return QStandardItemModel::qt_metacast(_clname);
}

int EnvironmentItemModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_EnvironmentSearchFilter_t {
    QByteArrayData data[1];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EnvironmentSearchFilter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EnvironmentSearchFilter_t qt_meta_stringdata_EnvironmentSearchFilter = {
    {
QT_MOC_LITERAL(0, 0, 23) // "EnvironmentSearchFilter"

    },
    "EnvironmentSearchFilter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EnvironmentSearchFilter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void EnvironmentSearchFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject EnvironmentSearchFilter::staticMetaObject = {
    { &QSortFilterProxyModel::staticMetaObject, qt_meta_stringdata_EnvironmentSearchFilter.data,
      qt_meta_data_EnvironmentSearchFilter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EnvironmentSearchFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EnvironmentSearchFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EnvironmentSearchFilter.stringdata0))
        return static_cast<void*>(this);
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int EnvironmentSearchFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_EnvironmentDialog_t {
    QByteArrayData data[5];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EnvironmentDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EnvironmentDialog_t qt_meta_stringdata_EnvironmentDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "EnvironmentDialog"
QT_MOC_LITERAL(1, 18, 8), // "addEntry"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 21), // "removeSelectedEntries"
QT_MOC_LITERAL(4, 50, 16) // "selectionChanged"

    },
    "EnvironmentDialog\0addEntry\0\0"
    "removeSelectedEntries\0selectionChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EnvironmentDialog[] = {

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
       1,    0,   29,    2, 0x09 /* Protected */,
       3,    0,   30,    2, 0x09 /* Protected */,
       4,    0,   31,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EnvironmentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EnvironmentDialog *_t = static_cast<EnvironmentDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addEntry(); break;
        case 1: _t->removeSelectedEntries(); break;
        case 2: _t->selectionChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject EnvironmentDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EnvironmentDialog.data,
      qt_meta_data_EnvironmentDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EnvironmentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EnvironmentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EnvironmentDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::EnvironmentDialog"))
        return static_cast< Ui::EnvironmentDialog*>(this);
    return QDialog::qt_metacast(_clname);
}

int EnvironmentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
