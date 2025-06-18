#include "inc/func.h"
#include "inc/helper.h"

PyObject* say(PyObject* self, PyObject* noargs) {
    PySys_WriteStdout("quck\n");
    Py_RETURN_NONE;
}

PyObject* duck(PyObject* self, PyObject* args) {

    PyObject* list;
    int flag;

    if (!PyArg_ParseTuple(args, "Op", &list, &flag)) {
        return NULL;
    }

    if (!PyList_Check(list)) {
        PyErr_SetString(PyExc_TypeError, "Expected a list of integers");
        return NULL;
    }

    Py_ssize_t true_len = PyList_Size(list);
    if (true_len % 2 != 0) {
        PyErr_SetString(PyExc_ValueError, "List must be divadeble by 2");
        return NULL;
    }

    int len = true_len/2;
    int *x = malloc(len * sizeof(int));
    int *y = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        x[i] = PyLong_AsLong(PyList_GetItem(list, i*2));
        y[i] = PyLong_AsLong(PyList_GetItem(list, i*2+1));
    }

    for (int k = 0; k < len; k++) {
        int tmp_index = k;
        for (int l = k; l < len; l++) {
            if (y[l] < y[tmp_index]) {
                tmp_index = l;
            }
        }
        swop(&y[k], &y[tmp_index]);
        swop(&x[k], &x[tmp_index]);
    }


    int *d = malloc(len * sizeof(int));
    for (int j = 0; j < len; j++) {
        if (j > 0) {
            d[j] = abs(y[j-1] - y[j]);
        } else {
            d[j] = abs(y[j]+1);
        }
    }

    for (int o = 0; o < len; o++) {
        set_y(d[o]-1);
        if (flag) {
            draw_duck(x[o]);
        } else {
            set_x(x[o]);
            PySys_WriteStdout("#\n");
        }
    }
    PySys_WriteStdout("\n");
    free(x);
    free(y);
    free(d);
    Py_RETURN_NONE;
}

PyObject* eat(PyObject* self, PyObject* noargs) {
    #ifndef _WIN32
        int _ = system("clear");
    #else
        int _ = system("cls");
    #endif
    (void) _;
    Py_RETURN_NONE;
}

