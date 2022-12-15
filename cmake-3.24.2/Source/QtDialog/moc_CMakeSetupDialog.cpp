/****************************************************************************
** Meta object code from reading C++ file 'CMakeSetupDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CMakeSetupDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CMakeSetupDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMakeSetupDialog_t {
    QByteArrayData data[72];
    char stringdata0[1088];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMakeSetupDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMakeSetupDialog_t qt_meta_stringdata_CMakeSetupDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CMakeSetupDialog"
QT_MOC_LITERAL(1, 17, 18), // "setBinaryDirectory"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 3), // "dir"
QT_MOC_LITERAL(4, 41, 18), // "setSourceDirectory"
QT_MOC_LITERAL(5, 60, 17), // "setDeferredPreset"
QT_MOC_LITERAL(6, 78, 6), // "preset"
QT_MOC_LITERAL(7, 85, 25), // "setStartupBinaryDirectory"
QT_MOC_LITERAL(8, 111, 7), // "startup"
QT_MOC_LITERAL(9, 119, 10), // "initialize"
QT_MOC_LITERAL(10, 130, 11), // "doConfigure"
QT_MOC_LITERAL(11, 142, 10), // "doGenerate"
QT_MOC_LITERAL(12, 153, 13), // "doOpenProject"
QT_MOC_LITERAL(13, 167, 23), // "doInstallForCommandLine"
QT_MOC_LITERAL(14, 191, 6), // "doHelp"
QT_MOC_LITERAL(15, 198, 7), // "doAbout"
QT_MOC_LITERAL(16, 206, 11), // "doInterrupt"
QT_MOC_LITERAL(17, 218, 5), // "error"
QT_MOC_LITERAL(18, 224, 7), // "message"
QT_MOC_LITERAL(19, 232, 14), // "doSourceBrowse"
QT_MOC_LITERAL(20, 247, 14), // "doBinaryBrowse"
QT_MOC_LITERAL(21, 262, 13), // "doReloadCache"
QT_MOC_LITERAL(22, 276, 13), // "doDeleteCache"
QT_MOC_LITERAL(23, 290, 21), // "updateSourceDirectory"
QT_MOC_LITERAL(24, 312, 21), // "updateBinaryDirectory"
QT_MOC_LITERAL(25, 334, 13), // "updatePresets"
QT_MOC_LITERAL(26, 348, 21), // "QVector<QCMakePreset>"
QT_MOC_LITERAL(27, 370, 7), // "presets"
QT_MOC_LITERAL(28, 378, 12), // "updatePreset"
QT_MOC_LITERAL(29, 391, 4), // "name"
QT_MOC_LITERAL(30, 396, 19), // "showPresetLoadError"
QT_MOC_LITERAL(31, 416, 35), // "cmCMakePresetsGraph::ReadFile..."
QT_MOC_LITERAL(32, 452, 6), // "result"
QT_MOC_LITERAL(33, 459, 12), // "showProgress"
QT_MOC_LITERAL(34, 472, 3), // "msg"
QT_MOC_LITERAL(35, 476, 7), // "percent"
QT_MOC_LITERAL(36, 484, 15), // "setEnabledState"
QT_MOC_LITERAL(37, 500, 19), // "setupFirstConfigure"
QT_MOC_LITERAL(38, 520, 20), // "updateGeneratorLabel"
QT_MOC_LITERAL(39, 541, 3), // "gen"
QT_MOC_LITERAL(40, 545, 20), // "setExitAfterGenerate"
QT_MOC_LITERAL(41, 566, 13), // "addBinaryPath"
QT_MOC_LITERAL(42, 580, 14), // "loadBuildPaths"
QT_MOC_LITERAL(43, 595, 14), // "saveBuildPaths"
QT_MOC_LITERAL(44, 610, 24), // "onBinaryDirectoryChanged"
QT_MOC_LITERAL(45, 635, 24), // "onSourceDirectoryChanged"
QT_MOC_LITERAL(46, 660, 20), // "onBuildPresetChanged"
QT_MOC_LITERAL(47, 681, 16), // "setCacheModified"
QT_MOC_LITERAL(48, 698, 26), // "removeSelectedCacheEntries"
QT_MOC_LITERAL(49, 725, 16), // "selectionChanged"
QT_MOC_LITERAL(50, 742, 15), // "editEnvironment"
QT_MOC_LITERAL(51, 758, 13), // "addCacheEntry"
QT_MOC_LITERAL(52, 772, 11), // "startSearch"
QT_MOC_LITERAL(53, 784, 14), // "setDebugOutput"
QT_MOC_LITERAL(54, 799, 15), // "setAdvancedView"
QT_MOC_LITERAL(55, 815, 14), // "setGroupedView"
QT_MOC_LITERAL(56, 830, 15), // "showUserChanges"
QT_MOC_LITERAL(57, 846, 15), // "setSearchFilter"
QT_MOC_LITERAL(58, 862, 3), // "str"
QT_MOC_LITERAL(59, 866, 16), // "prepareConfigure"
QT_MOC_LITERAL(60, 883, 19), // "doConfigureInternal"
QT_MOC_LITERAL(61, 903, 18), // "doGenerateInternal"
QT_MOC_LITERAL(62, 922, 8), // "exitLoop"
QT_MOC_LITERAL(63, 931, 19), // "doOutputContextMenu"
QT_MOC_LITERAL(64, 951, 2), // "pt"
QT_MOC_LITERAL(65, 954, 18), // "doOutputFindDialog"
QT_MOC_LITERAL(66, 973, 16), // "doOutputFindNext"
QT_MOC_LITERAL(67, 990, 16), // "directionForward"
QT_MOC_LITERAL(68, 1007, 16), // "doOutputFindPrev"
QT_MOC_LITERAL(69, 1024, 17), // "doOutputErrorNext"
QT_MOC_LITERAL(70, 1042, 21), // "doRegexExplorerDialog"
QT_MOC_LITERAL(71, 1064, 23) // "doWarningMessagesDialog"

    },
    "CMakeSetupDialog\0setBinaryDirectory\0"
    "\0dir\0setSourceDirectory\0setDeferredPreset\0"
    "preset\0setStartupBinaryDirectory\0"
    "startup\0initialize\0doConfigure\0"
    "doGenerate\0doOpenProject\0"
    "doInstallForCommandLine\0doHelp\0doAbout\0"
    "doInterrupt\0error\0message\0doSourceBrowse\0"
    "doBinaryBrowse\0doReloadCache\0doDeleteCache\0"
    "updateSourceDirectory\0updateBinaryDirectory\0"
    "updatePresets\0QVector<QCMakePreset>\0"
    "presets\0updatePreset\0name\0showPresetLoadError\0"
    "cmCMakePresetsGraph::ReadFileResult\0"
    "result\0showProgress\0msg\0percent\0"
    "setEnabledState\0setupFirstConfigure\0"
    "updateGeneratorLabel\0gen\0setExitAfterGenerate\0"
    "addBinaryPath\0loadBuildPaths\0"
    "saveBuildPaths\0onBinaryDirectoryChanged\0"
    "onSourceDirectoryChanged\0onBuildPresetChanged\0"
    "setCacheModified\0removeSelectedCacheEntries\0"
    "selectionChanged\0editEnvironment\0"
    "addCacheEntry\0startSearch\0setDebugOutput\0"
    "setAdvancedView\0setGroupedView\0"
    "showUserChanges\0setSearchFilter\0str\0"
    "prepareConfigure\0doConfigureInternal\0"
    "doGenerateInternal\0exitLoop\0"
    "doOutputContextMenu\0pt\0doOutputFindDialog\0"
    "doOutputFindNext\0directionForward\0"
    "doOutputFindPrev\0doOutputErrorNext\0"
    "doRegexExplorerDialog\0doWarningMessagesDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMakeSetupDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      57,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  299,    2, 0x0a /* Public */,
       4,    1,  302,    2, 0x0a /* Public */,
       5,    1,  305,    2, 0x0a /* Public */,
       7,    1,  308,    2, 0x0a /* Public */,
       9,    0,  311,    2, 0x09 /* Protected */,
      10,    0,  312,    2, 0x09 /* Protected */,
      11,    0,  313,    2, 0x09 /* Protected */,
      12,    0,  314,    2, 0x09 /* Protected */,
      13,    0,  315,    2, 0x09 /* Protected */,
      14,    0,  316,    2, 0x09 /* Protected */,
      15,    0,  317,    2, 0x09 /* Protected */,
      16,    0,  318,    2, 0x09 /* Protected */,
      17,    1,  319,    2, 0x09 /* Protected */,
      18,    1,  322,    2, 0x09 /* Protected */,
      19,    0,  325,    2, 0x09 /* Protected */,
      20,    0,  326,    2, 0x09 /* Protected */,
      21,    0,  327,    2, 0x09 /* Protected */,
      22,    0,  328,    2, 0x09 /* Protected */,
      23,    1,  329,    2, 0x09 /* Protected */,
      24,    1,  332,    2, 0x09 /* Protected */,
      25,    1,  335,    2, 0x09 /* Protected */,
      28,    1,  338,    2, 0x09 /* Protected */,
      30,    2,  341,    2, 0x09 /* Protected */,
      33,    2,  346,    2, 0x09 /* Protected */,
      36,    1,  351,    2, 0x09 /* Protected */,
      37,    0,  354,    2, 0x09 /* Protected */,
      38,    1,  355,    2, 0x09 /* Protected */,
      40,    1,  358,    2, 0x09 /* Protected */,
      41,    1,  361,    2, 0x09 /* Protected */,
      42,    0,  364,    2, 0x09 /* Protected */,
      43,    1,  365,    2, 0x09 /* Protected */,
      44,    1,  368,    2, 0x09 /* Protected */,
      45,    1,  371,    2, 0x09 /* Protected */,
      46,    1,  374,    2, 0x09 /* Protected */,
      47,    0,  377,    2, 0x09 /* Protected */,
      48,    0,  378,    2, 0x09 /* Protected */,
      49,    0,  379,    2, 0x09 /* Protected */,
      50,    0,  380,    2, 0x09 /* Protected */,
      51,    0,  381,    2, 0x09 /* Protected */,
      52,    0,  382,    2, 0x09 /* Protected */,
      53,    1,  383,    2, 0x09 /* Protected */,
      54,    1,  386,    2, 0x09 /* Protected */,
      55,    1,  389,    2, 0x09 /* Protected */,
      56,    0,  392,    2, 0x09 /* Protected */,
      57,    1,  393,    2, 0x09 /* Protected */,
      59,    0,  396,    2, 0x09 /* Protected */,
      60,    0,  397,    2, 0x09 /* Protected */,
      61,    0,  398,    2, 0x09 /* Protected */,
      62,    1,  399,    2, 0x09 /* Protected */,
      63,    1,  402,    2, 0x09 /* Protected */,
      65,    0,  405,    2, 0x09 /* Protected */,
      66,    1,  406,    2, 0x09 /* Protected */,
      66,    0,  409,    2, 0x29 /* Protected | MethodCloned */,
      68,    0,  410,    2, 0x09 /* Protected */,
      69,    0,  411,    2, 0x09 /* Protected */,
      70,    0,  412,    2, 0x09 /* Protected */,
      71,    0,  413,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 31,    3,   32,
    QMetaType::Void, QMetaType::QString, QMetaType::Float,   34,   35,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   58,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QPoint,   64,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   67,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CMakeSetupDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMakeSetupDialog *_t = static_cast<CMakeSetupDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setBinaryDirectory((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setSourceDirectory((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setDeferredPreset((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setStartupBinaryDirectory((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->initialize(); break;
        case 5: _t->doConfigure(); break;
        case 6: _t->doGenerate(); break;
        case 7: _t->doOpenProject(); break;
        case 8: _t->doInstallForCommandLine(); break;
        case 9: _t->doHelp(); break;
        case 10: _t->doAbout(); break;
        case 11: _t->doInterrupt(); break;
        case 12: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->message((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->doSourceBrowse(); break;
        case 15: _t->doBinaryBrowse(); break;
        case 16: _t->doReloadCache(); break;
        case 17: _t->doDeleteCache(); break;
        case 18: _t->updateSourceDirectory((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->updateBinaryDirectory((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->updatePresets((*reinterpret_cast< const QVector<QCMakePreset>(*)>(_a[1]))); break;
        case 21: _t->updatePreset((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->showPresetLoadError((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< cmCMakePresetsGraph::ReadFileResult(*)>(_a[2]))); break;
        case 23: _t->showProgress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 24: _t->setEnabledState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: { bool _r = _t->setupFirstConfigure();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->updateGeneratorLabel((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 27: _t->setExitAfterGenerate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->addBinaryPath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 29: { QStringList _r = _t->loadBuildPaths();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 30: _t->saveBuildPaths((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 31: _t->onBinaryDirectoryChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->onSourceDirectoryChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 33: _t->onBuildPresetChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->setCacheModified(); break;
        case 35: _t->removeSelectedCacheEntries(); break;
        case 36: _t->selectionChanged(); break;
        case 37: _t->editEnvironment(); break;
        case 38: _t->addCacheEntry(); break;
        case 39: _t->startSearch(); break;
        case 40: _t->setDebugOutput((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->setAdvancedView((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->setGroupedView((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->showUserChanges(); break;
        case 44: _t->setSearchFilter((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 45: { bool _r = _t->prepareConfigure();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 46: { bool _r = _t->doConfigureInternal();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 47: { bool _r = _t->doGenerateInternal();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 48: _t->exitLoop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->doOutputContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 50: _t->doOutputFindDialog(); break;
        case 51: _t->doOutputFindNext((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 52: _t->doOutputFindNext(); break;
        case 53: _t->doOutputFindPrev(); break;
        case 54: _t->doOutputErrorNext(); break;
        case 55: _t->doRegexExplorerDialog(); break;
        case 56: _t->doWarningMessagesDialog(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QCMakePreset> >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cmCMakePresetsGraph::ReadFileResult >(); break;
            }
            break;
        }
    }
}

const QMetaObject CMakeSetupDialog::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CMakeSetupDialog.data,
      qt_meta_data_CMakeSetupDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CMakeSetupDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMakeSetupDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMakeSetupDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::CMakeSetupDialog"))
        return static_cast< Ui::CMakeSetupDialog*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CMakeSetupDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 57)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 57;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 57)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 57;
    }
    return _id;
}
struct qt_meta_stringdata_QCMakeThread_t {
    QByteArrayData data[3];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QCMakeThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QCMakeThread_t qt_meta_stringdata_QCMakeThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QCMakeThread"
QT_MOC_LITERAL(1, 13, 16), // "cmakeInitialized"
QT_MOC_LITERAL(2, 30, 0) // ""

    },
    "QCMakeThread\0cmakeInitialized\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCMakeThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void QCMakeThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QCMakeThread *_t = static_cast<QCMakeThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cmakeInitialized(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QCMakeThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QCMakeThread::cmakeInitialized)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QCMakeThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_QCMakeThread.data,
      qt_meta_data_QCMakeThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QCMakeThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCMakeThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QCMakeThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int QCMakeThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QCMakeThread::cmakeInitialized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
