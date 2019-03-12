#include <Python.h>
#include "structmember.h"
#include "common.hpp"
#include "Ball.hpp"

// some informations for our module
static PyModuleDef lesson2 = {
    PyModuleDef_HEAD_INIT,
    .m_name = "lesson2",
    .m_doc = "Lesson 2",
    .m_size = -1,
};

// a procedure to register a type
int lesson2_register_type(PyObject *m, const char *name, PyTypeObject& type)
{
    if (PyType_Ready(& type) < 0) return 0;

    Py_INCREF(& type);
    PyModule_AddObject(m, name, (PyObject *) & type);

    return 1;
}

// initialize our module
extern "C" PyMODINIT_FUNC PyInit_lesson2(void)
{
    PyObject *m;

    m = PyModule_Create(&lesson2);
    if (m == NULL) return NULL;

    // this is the point, we add our ball to python as new type
    if( ! lesson2_register_type(m, "Ball", Ball::_type ) ) return NULL;

    return m;
}
