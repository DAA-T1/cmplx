//===-- cmplx/superarr/superarr.cpp - Super Array Implementation
//-----------===//
///
/// \file
/// This file contains the implementation of th Super Array data structure.
///
//===--------------------------------------------------------------------===//

#include <cmplx/superarr/superarr.h>
#include <iostream>
namespace cmplx::superarr {
template <typename T>
SuperArray<T>::SuperArray(std::initializer_list<T> init_list) {
  arr = new T[n];
  T *ptr = arr;
  for (auto &c : init_list) {
    *ptr++ = c;
  }
}

template <typename T> SuperArray<T>::SuperArray(int size, T elem) {
  n = size;
  arr = new T[n];
  for (int i = 0; i < n; i++) {
    arr[i] = elem;
  }
}

template <typename T> SuperArray<T>::SuperArray(int size) {
  n = size;
  arr = new T[n]();
}

template <typename T> int SuperArray<T>::size() { return n; }

template <typename T> T &SuperArray<T>::operator[](int ind) {
  if (ind >= n) {
    std::cout << "Out of bounds access." << std::endl;
    exit(0);
  }
  return arr[ind];
}

template <typename T> SuperArray<T>::~SuperArray() { delete[] arr; }

} // namespace cmplx::superarr
