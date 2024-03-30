//===-- cmplx/utils/utils.cpp - Utils File ----------===//
///
/// \file
/// This file exists to add code for utilities.
///
//===-----------------------------------------------------------------===//

#include <iostream>

namespace cmplx::utils {

  template <typename T>
  void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
  }
  
}// namespace cmplx::heapsort
