/****************************************************************************
** Meta object code from reading C++ file 'dialogo.h'
**
** Created: Sat Jul 12 23:44:18 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pinpong/dialogo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialogo[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      19,    8,    8,    8, 0x0a,
      32,    8,    8,    8, 0x0a,
      51,   47,    8,    8, 0x0a,
      73,    8,    8,    8, 0x0a,
      87,    8,    8,    8, 0x0a,
     102,  100,    8,    8, 0x0a,
     117,  100,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Dialogo[] = {
    "Dialogo\0\0empezar()\0mover_dona()\0"
    "mover_barra2()\0x,y\0mover_barra1(int,int)\0"
    "moverArriba()\0moverAbajo()\0n\0"
    "velocidad(int)\0ganar(int)\0"
};

void Dialogo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dialogo *_t = static_cast<Dialogo *>(_o);
        switch (_id) {
        case 0: _t->empezar(); break;
        case 1: _t->mover_dona(); break;
        case 2: _t->mover_barra2(); break;
        case 3: _t->mover_barra1((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->moverArriba(); break;
        case 5: _t->moverAbajo(); break;
        case 6: _t->velocidad((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->ganar((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Dialogo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dialogo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialogo,
      qt_meta_data_Dialogo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialogo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialogo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialogo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialogo))
        return static_cast<void*>(const_cast< Dialogo*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialogo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
