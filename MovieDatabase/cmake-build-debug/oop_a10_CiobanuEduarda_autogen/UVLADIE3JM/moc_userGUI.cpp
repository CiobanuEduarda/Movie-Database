/****************************************************************************
** Meta object code from reading C++ file 'userGUI.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/userGUI.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
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
struct qt_meta_stringdata_CLASSUserGUIENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSUserGUIENDCLASS = QtMocHelpers::stringData(
    "UserGUI",
    "searchMovies",
    "",
    "nextMovie",
    "addToWatchlist",
    "deleteFromWatchlist",
    "saveWatchlist",
    "viewWatchlistFile",
    "updateWatchlistDisplay",
    "refreshWatchlist",
    "updateTableView"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUserGUIENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    0,   73,    2, 0x08,    6 /* Private */,
       8,    0,   74,    2, 0x08,    7 /* Private */,
       9,    0,   75,    2, 0x08,    8 /* Private */,
      10,    0,   76,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
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

Q_CONSTINIT const QMetaObject UserGUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSUserGUIENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUserGUIENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUserGUIENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UserGUI, std::true_type>,
        // method 'searchMovies'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nextMovie'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addToWatchlist'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteFromWatchlist'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveWatchlist'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'viewWatchlistFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateWatchlistDisplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'refreshWatchlist'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateTableView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void UserGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserGUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->searchMovies(); break;
        case 1: _t->nextMovie(); break;
        case 2: _t->addToWatchlist(); break;
        case 3: _t->deleteFromWatchlist(); break;
        case 4: _t->saveWatchlist(); break;
        case 5: _t->viewWatchlistFile(); break;
        case 6: _t->updateWatchlistDisplay(); break;
        case 7: _t->refreshWatchlist(); break;
        case 8: _t->updateTableView(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *UserGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUserGUIENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UserGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
