/****************************************************************************
** Meta object code from reading C++ file 'testproject.h'
**
** Created: Tue 23. Apr 10:37:07 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../testproject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testproject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestProject[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      32,   12,   12,   12, 0x08,
      56,   12,   12,   12, 0x08,
      82,   12,   12,   12, 0x08,
     106,   12,   12,   12, 0x08,
     131,   12,   12,   12, 0x08,
     155,   12,   12,   12, 0x08,
     179,   12,   12,   12, 0x08,
     207,   12,   12,   12, 0x08,
     238,  233,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TestProject[] = {
    "TestProject\0\0UpdateDBFinished()\0"
    "on_pushButton_pressed()\0"
    "on_pushButton_2_pressed()\0"
    "on_ButtonStop_pressed()\0"
    "on_ButtonPause_pressed()\0"
    "on_ButtonNext_pressed()\0on_PlayButton_pressed()\0"
    "on_PreviousButton_pressed()\0"
    "on_videoPlayer_finished()\0arg1\0"
    "on_webView_loadFinished(bool)\0"
};

void TestProject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TestProject *_t = static_cast<TestProject *>(_o);
        switch (_id) {
        case 0: _t->UpdateDBFinished(); break;
        case 1: _t->on_pushButton_pressed(); break;
        case 2: _t->on_pushButton_2_pressed(); break;
        case 3: _t->on_ButtonStop_pressed(); break;
        case 4: _t->on_ButtonPause_pressed(); break;
        case 5: _t->on_ButtonNext_pressed(); break;
        case 6: _t->on_PlayButton_pressed(); break;
        case 7: _t->on_PreviousButton_pressed(); break;
        case 8: _t->on_videoPlayer_finished(); break;
        case 9: _t->on_webView_loadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TestProject::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TestProject::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestProject,
      qt_meta_data_TestProject, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestProject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestProject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestProject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestProject))
        return static_cast<void*>(const_cast< TestProject*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TestProject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
static const uint qt_meta_data_DBUpdateWorker[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DBUpdateWorker[] = {
    "DBUpdateWorker\0\0wUpdateDBFinished()\0"
    "doWork()\0"
};

void DBUpdateWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DBUpdateWorker *_t = static_cast<DBUpdateWorker *>(_o);
        switch (_id) {
        case 0: _t->wUpdateDBFinished(); break;
        case 1: _t->doWork(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DBUpdateWorker::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DBUpdateWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DBUpdateWorker,
      qt_meta_data_DBUpdateWorker, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DBUpdateWorker::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DBUpdateWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DBUpdateWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DBUpdateWorker))
        return static_cast<void*>(const_cast< DBUpdateWorker*>(this));
    return QObject::qt_metacast(_clname);
}

int DBUpdateWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DBUpdateWorker::wUpdateDBFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
