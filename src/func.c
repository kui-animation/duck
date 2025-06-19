#include "inc/func.h"
#include "inc/helper.h"
#define MILISECOND 1000
#define PI 3.14159265359


PyObject* creatPoins(PyObject* self, PyObject* args) {
    char *name;
    int v_amount = 2;
    if (!PyArg_ParseTuple(args, "s", &name)) {
        return NULL;
    }
    char *line = malloc(255*sizeof(char));
    if (!line) {
        PyErr_SetString(PyExc_MemoryError, "Couldn't allocate memory for line");
        return NULL;
    }
    float *v = malloc(v_amount*3*sizeof(float));
    if (!v) {
        free(line);
        PyErr_SetString(PyExc_MemoryError, "Couldn't allocate memory for v");
        return NULL;
    }
    FILE *obj = fopen(name, "r");
    if (!obj) {
        free(v);
        free(line);
        PyErr_SetString(PyExc_FileExistsError, "Couldn't open file");
        return NULL;
    }


    int line_number = 0;
    while (fgets(line, 255, obj)) {
        if (line_number >= v_amount) {
            v_amount = line_number+2;
            float *tmp_v = realloc(v, v_amount*3*sizeof(float));
            if (!tmp_v) {
                free(v);
                free(line);
                fclose(obj);
                PyErr_SetString(PyExc_MemoryError, "Couldn't allocate memory for tmp_v");
                return NULL;
            }
            v = tmp_v;
        }
        float x, y, z;
        if (line[0] != 'v') {
            continue;
        }
        line[0] = ' ';
        if (sscanf(line, "%f %f %f", &x, &y, &z) != 3) {
            continue; // skip invalid lines
        }
        v[line_number * 3 + 0] = x;
        v[line_number * 3 + 1] = y;
        v[line_number * 3 + 2] = z;

        line_number ++;
    }

    PyObject* list = PyList_New(line_number*3);
    for (int i = 0; i < line_number*3; i++) {
        PyList_SetItem(list, i, PyLong_FromLong(v[i]));
    }

    free(v);
    free(line);
    fclose(obj);

    return list;
}


PyObject* duck3d(PyObject* self, PyObject* args) {

    PyObject* list;
    float angle = 43.5;
    if (!PyArg_ParseTuple(args, "O|f", &list, &angle)) {
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
    float r_angle = angle*(PI/180.0);
    for (int i = 0; i < len; i++) {
        int tmp_x = PyLong_AsLong(PyList_GetItem(list, i*3));
        int tmp_y = PyLong_AsLong(PyList_GetItem(list, i*3+1));
        int z = PyLong_AsLong(PyList_GetItem(list, i*3+2));
        x[i] = tmp_x + 1/2.0*z*cos(r_angle);
        y[i] = tmp_y + 1/2.0*z*sin(r_angle);
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