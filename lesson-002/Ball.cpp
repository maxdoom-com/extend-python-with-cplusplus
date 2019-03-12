#include <Python.h>
#include "structmember.h"

#include "common.hpp"

#include "Ball.hpp"


// this is the data structure for our new python type
PyTypeObject Ball::_type =
{
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name        = "Ball",                                           // the name of our new type
    .tp_basicsize   = sizeof(CObject),                                  // the size of our object that holds the class pointer
    .tp_itemsize    = 0,
    .tp_dealloc     = (destructor) Ball::_dealloc,                      // the destructor called from python
    .tp_flags       = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_doc         = "a ball...",                                      // a piece of documentation
    .tp_base        = NULL,                                             // no base type means pythons <Object>
    .tp_init        = (initproc) Ball::_init,                           // pythons init function of this class
    .tp_new         = Ball::_new,                                       // pythons constructor
};



// this is the c++ constructor
// - we initialize the _self pointer to the python object here
Ball::Ball(PyObject *self): _self(self)
{
}

// the c++ destructor
// - it just clears the class pointer
// - and decreases the reference count of _self, while blanking it
Ball::~Ball()
{
    ((CObject *)_self)->cptr = NULL;
    Py_CLEAR(_self);
}

// python calls this method to create a new instance of this class
PyObject *Ball::_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    CObject *self;
    self = (CObject *) type->tp_alloc(type, 0);
    if( self != NULL )
    {
        initialize_cobject(self);
    }
    return (PyObject *) self;
}

// python calls this like it would call class::__init__(self, ...)
int Ball::_init(CObject *self, PyObject *args, PyObject *kwds)
{
    self->cptr = new Ball( (PyObject*)self );

    return 0;
}

// and this is the destructor
void Ball::_dealloc(CObject *self)
{
    self->cptr = NULL;
}

