//===-- cmplx/superarr/superarr.h - Super Array Definition --------------===//
///
/// \file
/// This file contains the declaration of the Super Array data structure.
///
//===-----------------------------------------------------------------===//

#pragma once
#include <iostream>

namespace cmplx::superarr {
template <typename T> class SuperArray {
  int n;
  T *arr;

public:
  SuperArray(std::initializer_list<T> init_list) {
	arr = new T[n];
	T *ptr = arr;
	for (auto &c : init_list) {
	  *ptr++ = c;
	}
  }
  SuperArray(int size, T elem) {
	n = size;
	arr = new T[n];
	for (int i = 0; i < n; i++) {
	  arr[i] = elem;
	}
  }
  SuperArray(int size) {
	n = size;
	arr = new T[n]();
  }
  int size() { return n; }

  T &operator[](int ind) {
	if (ind >= n) {
	  std::cout << "Out of bounds access." << std::endl;
	  exit(0);
	}
	return arr[ind];
  }

  ~SuperArray() { delete[] arr; }
  friend std::ostream &operator<<(std::ostream &out, SuperArray<T> &c) {
    for (int i = 0; i < c.size(); i++) {
      out << c[i] << " ";
    }
    return out;
  }
};
} // namespace cmplx::superarr
