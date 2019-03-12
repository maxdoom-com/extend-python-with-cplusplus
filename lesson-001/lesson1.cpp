#include <Python.h>

static PyModuleDef lesson1 = {
    PyModuleDef_HEAD_INIT,
    .m_name = "lesson1",
    .m_doc = "Lesson 1",
    .m_size = -1,
};

extern "C" PyMODINIT_FUNC PyInit_lesson1(void)
{
    PyObject *m;

    m = PyModule_Create(&lesson1);
    if (m == NULL) return NULL;

    return m;
}
