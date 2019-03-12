#include <Python.h>
#include "structmember.h"

#include "common.hpp"

// the reason for initializing the self pointer from this function is,
// that you may want to add (maybe) more data to the cobject.
// if you wish so, you can put this here, without changing every
// constructor of every class, you may write.

void initialize_cobject(CObject *self)
{
    self->cptr = NULL;
}
