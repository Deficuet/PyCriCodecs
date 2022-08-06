#define PY_SSIZE_T_CLEAN
#pragma once
#include <Python.h>
#include "adx.cpp"
#include "crilayla.cpp"

static struct PyMethodDef Codec_methods[] = {
    { "AdxDecode", (PyCFunction)AdxDecode, METH_VARARGS, nullptr },
    { "AdxEncode", (PyCFunction)AdxEncode, METH_VARARGS, nullptr },
    { "CriLaylaDecompress", (PyCFunction)CriLaylaDecompress, METH_O, nullptr },
    { nullptr, nullptr, 0, nullptr }
};

static PyModuleDef CriCodecs_module = {
    PyModuleDef_HEAD_INIT,
    "CriCodecs",
    "Faster Decoding and Encoding with C++",
    0,
    Codec_methods
};

PyMODINIT_FUNC PyInit_CriCodecs() {
    return PyModule_Create(&CriCodecs_module);
}