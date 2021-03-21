#include <pybind11/pybind11.h>

int greatest_common_divisor(int x, int y) {
  int r, tmp;
  if (x < y) {
    tmp = x;
    x = y;
    y = tmp;
  }

  r = x % y;
  while (r != 0) {
    x = y;
    y = r;
    r = x % y;
  }
  return y;
}

// int least_common_multiple(int x, int y) {
//   return x * y / greatest_common_divisor(x, y);
// }

PYBIND11_MODULE(gil, m) {
  // m.doc() = "pybind11 example";
  m.def("greatest_common_divisor", &greatest_common_divisor,
        "A function which calculate greatest common divisor");
  // m.def("least_common_multiple", &least_common_multiple, "");
}
