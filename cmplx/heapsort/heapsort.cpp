//===-- cmplx/heapsort/heapsort.cpp - Dummy CMake Link File ----------===//
///
/// \file
/// This file exists to fix link language issues from CMake.
///
//===-----------------------------------------------------------------===//

#include <cmplx/heapsort/heapsort.h>
#include <iostream>

namespace cmplx::heapsort {
void printHello() {
  std::cout << "Hello!" << std::endl;
}
}// namespace cmplx::heapsort
