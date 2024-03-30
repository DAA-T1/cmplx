//===-- cmplx/utils/utils.cpp - Utils File ----------===//
///
/// \file
/// This file exists to add code for utilities.
///
//===-----------------------------------------------------------------===//

#include <iostream>

namespace cmplx::utils {

  template <typename T>
  void printArray(T *arr, int size) {
    for (int i = 0; i < size; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }
}// namespace cmplx::heapsort
