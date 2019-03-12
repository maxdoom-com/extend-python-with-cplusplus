#ifndef COMMON_HPP
#define COMMON_HPP

// all our classes use this structure to store their data together with
// the python objects, you create from them

typedef struct CObject {
    PyObject_HEAD
    void *cptr; // the c pointer is the pointer to the c++ class instance
} CObject;

// a helper function to initialize the CObject
void initialize_cobject(CObject *self);

#endif
