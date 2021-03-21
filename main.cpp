#include <pybind11/pybind11.h>

int f1(int y) { return y; }

PYBIND11_MODULE(gil, m) { m.def("f1", &f1); }
