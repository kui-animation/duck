#include "inc/func.h"

static PyMethodDef methods[] = {
    {"say", say, METH_NOARGS, "print a ducks mesige"},
    {"list", duck, METH_VARARGS, "print the duck"},
    {"eat", eat, METH_NOARGS, "print the duck"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "duck",
    NULL,
    -1,
    methods
};

PyMODINIT_FUNC PyInit_duck(void) {
    return PyModule_Create(&module);
}

