#ifndef FUNC_H
#define FUNC_H

#ifndef _WIN32
    #include <python3.12/Python.h>
#else
    #include <python3.11/Python.h>
#endif
#include <stdlib.h>
#include <stdio.h>

PyObject* duck3d(PyObject* self, PyObject* args);
PyObject* eat (PyObject* self, PyObject* noargs);
PyObject* pose (PyObject* self, PyObject* args);
PyObject* creatPoins(PyObject* self, PyObject* args);

#endif
