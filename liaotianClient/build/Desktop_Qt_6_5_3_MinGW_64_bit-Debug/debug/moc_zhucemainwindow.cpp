/****************************************************************************
** Meta object code from reading C++ file 'zhucemainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../zhucemainwindow.h"
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
    "on_btnExit_clicked",
    "",
    "on_btnSignup_clicked",
    "on_editUsername_selectionChanged",
    "on_editEmail_selectionChanged",
    "on_editPassword_selectionChanged",
    "on_editPasswordYes_selectionChanged",
    "on_editCode_selectionChanged"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSzhuceMainWindowENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[16];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[33];
    char stringdata5[30];
    char stringdata6[33];
    char stringdata7[36];
    char stringdata8[29];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSzhuceMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSzhuceMainWindowENDCLASS_t qt_meta_stringdata_CLASSzhuceMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "zhuceMainWindow"
        QT_MOC_LITERAL(16, 18),  // "on_btnExit_clicked"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 20),  // "on_btnSignup_clicked"
        QT_MOC_LITERAL(57, 32),  // "on_editUsername_selectionChanged"
        QT_MOC_LITERAL(90, 29),  // "on_editEmail_selectionChanged"
        QT_MOC_LITERAL(120, 32),  // "on_editPassword_selectionChanged"
        QT_MOC_LITERAL(153, 35),  // "on_editPasswordYes_selectionC..."
        QT_MOC_LITERAL(189, 28)   // "on_editCode_selectionChanged"
    },
    "zhuceMainWindow",
    "on_btnExit_clicked",
    "",
    "on_btnSignup_clicked",
    "on_editUsername_selectionChanged",
    "on_editEmail_selectionChanged",
    "on_editPassword_selectionChanged",
    "on_editPasswordYes_selectionChanged",
    "on_editCode_selectionChanged"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSzhuceMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
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
        case 0: _t->on_btnExit_clicked(); break;
        case 1: _t->on_btnSignup_clicked(); break;
        case 2: _t->on_editUsername_selectionChanged(); break;
        case 3: _t->on_editEmail_selectionChanged(); break;
        case 4: _t->on_editPassword_selectionChanged(); break;
        case 5: _t->on_editPasswordYes_selectionChanged(); break;
        case 6: _t->on_editCode_selectionChanged(); break;
        default: ;
        }
    }
    (void)_a;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
