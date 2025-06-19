#ifndef FUNC_H
#define FUNC_H

#ifndef _WIN32
    #include <python3.12/Python.h>
#else
    #include <python3.11/Python.h>
#endif
#include <stdlib.h>
#include <stdio.h>

PyObject* say (PyObject* self, PyObject* noargs);
PyObject* duck2d (PyObject* self, PyObject* args);
PyObject* duck3d(PyObject* self, PyObject* args);
PyObject* eat (PyObject* self, PyObject* noargs);
PyObject* pose (PyObject* self, PyObject* args);

#endif
