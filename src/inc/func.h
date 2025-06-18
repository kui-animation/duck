#ifndef FUNC_H
#define FUNC_H

#include <python3.12/Python.h>
#include <stdlib.h>
#include <stdio.h>

PyObject* say(PyObject* self, PyObject* noargs);
PyObject* duck(PyObject* self, PyObject* args);
PyObject* eat(PyObject* self, PyObject* noargs);

#endif
