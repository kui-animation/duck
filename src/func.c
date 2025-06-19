#include "inc/func.h"
#include "inc/helper.h"
#define MILISECOND 1000
#define PI 3.14159265359

PyObject* duck3d(PyObject* self, PyObject* args) {

    PyObject* list;

    if (!PyArg_ParseTuple(args, "O", &list)) {
        return NULL;
    }

    if (!PyList_Check(list)) {
        PyErr_SetString(PyExc_TypeError, "Expected a list of integers");
        return NULL;
    }

    Py_ssize_t true_len = PyList_Size(list);
    if (true_len % 3 != 0) {
        PyErr_SetString(PyExc_ValueError, "List must be divadeble by 2");
        return NULL;
    }

    int len = true_len/3;
    int *x = malloc(len * sizeof(int));
    if (!x) {
        PyErr_SetString(PyExc_MemoryError, "Couldn't allocate memory for x");
        return NULL;
    }
    int *y = malloc(len * sizeof(int));
    if (!y) {
        PyErr_SetString(PyExc_MemoryError, "Couldn't allocate memory for y");
        free(x);
        return NULL;
    }
    float angle = 43.5*(PI/180.0);
    for (int i = 0; i < len; i++) {
        int tmp_x = PyLong_AsLong(PyList_GetItem(list, i*3));
        int tmp_y = PyLong_AsLong(PyList_GetItem(list, i*3+1));
        int z = PyLong_AsLong(PyList_GetItem(list, i*3+2));
        x[i] = tmp_x + 1/2.0*z*cos(angle);
        y[i] = tmp_y + 1/2.0*z*sin(angle);
    }

    
    draw (x, y, len);
    free(x);
    free(y);
    Py_RETURN_NONE;
}

PyObject* eat (PyObject* self, PyObject* noargs) {
    #ifndef _WIN32
        int _ = system("clear");
    #else
        int _ = system("cls");
    #endif
    (void) _;
    Py_RETURN_NONE;
}

PyObject* pose (PyObject* self, PyObject* args) {

    int seconds;
    if(PyArg_ParseTuple(args, "i", &seconds))

    usleep(MILISECOND*seconds);
    Py_RETURN_NONE;
}