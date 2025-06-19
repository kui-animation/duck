#include "inc/func.h"
#ifdef _WIN32
    #include "inc/helper.h"
#endif

static PyMethodDef methods[] = {
    {"quaks", duck3d, METH_VARARGS, "print's ducks"},
    {"eat", eat, METH_NOARGS, "clears the terminal"},
    {"winter", pose, METH_VARARGS, "sleep in miliseconds"},
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
    #ifdef _WIN32
        enable_ansi_escape_sequences();
    #endif
    return PyModule_Create(&module);
}

