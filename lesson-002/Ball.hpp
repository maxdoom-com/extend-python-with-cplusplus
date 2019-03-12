#ifndef BALL_HPP
#define BALL_HPP

// we want to create a ball class
class Ball
{
    private:
        // the c++ class instance will have a pointer to the pythons object
        PyObject *_self;

    public:
        // this is a datastructure describing our class
        static PyTypeObject _type;

        // this is the memory allocation "method"
        static PyObject *_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

        // the c++ class has a __init__(self, ...) function:
        static int _init(CObject *self, PyObject *args, PyObject *kwds);

        // and this is pythons destructor for this object
        static void _dealloc(CObject *self);

    public:
        // c++ needs a destructor as well. it gets a self pointer and stores this in _self (see above).
        Ball(PyObject *self);

        // and a c++ destructor
        ~Ball();
};

#endif
