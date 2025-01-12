/****************************************************************************
** Meta object code from reading C++ file 'zhucemainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../zhucemainwindow.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zhucemainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSzhuceMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSzhuceMainWindowENDCLASS = QtMocHelpers::stringData(
    "zhuceMainWindow",
    "slot_reg_mod_finish",
    "",
    "ReqId",
    "id",
    "res",
    "ErrorCodes",
    "err",
    "on_btnExit_clicked",
    "on_btnSignup_clicked",
    "on_editUsername_selectionChanged",
    "on_editEmail_selectionChanged",
    "on_editPassword_selectionChanged",
    "on_editPasswordYes_selectionChanged",
    "on_editCode_selectionChanged",
    "on_btnGetCode_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSzhuceMainWindowENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[16];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[3];
    char stringdata5[4];
    char stringdata6[11];
    char stringdata7[4];
    char stringdata8[19];
    char stringdata9[21];
    char stringdata10[33];
    char stringdata11[30];
    char stringdata12[33];
    char stringdata13[36];
    char stringdata14[29];
    char stringdata15[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSzhuceMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSzhuceMainWindowENDCLASS_t qt_meta_stringdata_CLASSzhuceMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "zhuceMainWindow"
        QT_MOC_LITERAL(16, 19),  // "slot_reg_mod_finish"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 5),  // "ReqId"
        QT_MOC_LITERAL(43, 2),  // "id"
        QT_MOC_LITERAL(46, 3),  // "res"
        QT_MOC_LITERAL(50, 10),  // "ErrorCodes"
        QT_MOC_LITERAL(61, 3),  // "err"
        QT_MOC_LITERAL(65, 18),  // "on_btnExit_clicked"
        QT_MOC_LITERAL(84, 20),  // "on_btnSignup_clicked"
        QT_MOC_LITERAL(105, 32),  // "on_editUsername_selectionChanged"
        QT_MOC_LITERAL(138, 29),  // "on_editEmail_selectionChanged"
        QT_MOC_LITERAL(168, 32),  // "on_editPassword_selectionChanged"
        QT_MOC_LITERAL(201, 35),  // "on_editPasswordYes_selectionC..."
        QT_MOC_LITERAL(237, 28),  // "on_editCode_selectionChanged"
        QT_MOC_LITERAL(266, 21)   // "on_btnGetCode_clicked"
    },
    "zhuceMainWindow",
    "slot_reg_mod_finish",
    "",
    "ReqId",
    "id",
    "res",
    "ErrorCodes",
    "err",
    "on_btnExit_clicked",
    "on_btnSignup_clicked",
    "on_editUsername_selectionChanged",
    "on_editEmail_selectionChanged",
    "on_editPassword_selectionChanged",
    "on_editPasswordYes_selectionChanged",
    "on_editCode_selectionChanged",
    "on_btnGetCode_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSzhuceMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   68,    2, 0x08,    1 /* Private */,
       8,    0,   75,    2, 0x08,    5 /* Private */,
       9,    0,   76,    2, 0x08,    6 /* Private */,
      10,    0,   77,    2, 0x08,    7 /* Private */,
      11,    0,   78,    2, 0x08,    8 /* Private */,
      12,    0,   79,    2, 0x08,    9 /* Private */,
      13,    0,   80,    2, 0x08,   10 /* Private */,
      14,    0,   81,    2, 0x08,   11 /* Private */,
      15,    0,   82,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject zhuceMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSzhuceMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSzhuceMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSzhuceMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<zhuceMainWindow, std::true_type>,
        // method 'slot_reg_mod_finish'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ReqId, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<ErrorCodes, std::false_type>,
        // method 'on_btnExit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnSignup_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_editUsername_selectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_editEmail_selectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_editPassword_selectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_editPasswordYes_selectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_editCode_selectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnGetCode_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void zhuceMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<zhuceMainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slot_reg_mod_finish((*reinterpret_cast< std::add_pointer_t<ReqId>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ErrorCodes>>(_a[3]))); break;
        case 1: _t->on_btnExit_clicked(); break;
        case 2: _t->on_btnSignup_clicked(); break;
        case 3: _t->on_editUsername_selectionChanged(); break;
        case 4: _t->on_editEmail_selectionChanged(); break;
        case 5: _t->on_editPassword_selectionChanged(); break;
        case 6: _t->on_editPasswordYes_selectionChanged(); break;
        case 7: _t->on_editCode_selectionChanged(); break;
        case 8: _t->on_btnGetCode_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *zhuceMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *zhuceMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSzhuceMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int zhuceMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
