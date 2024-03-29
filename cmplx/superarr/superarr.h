//===-- cmplx/superarr/superarr.h - Super Array Definition --------------===//
///
/// \file
/// This file contains the declaration of the Super Array data structure.
///
//===-----------------------------------------------------------------===//

#pragma once
#include <initializer_list>
#include <iosfwd>

namespace cmplx::superarr {
template <typename T> class SuperArray {
  int n;
  T *arr;

public:
  SuperArray(std::initializer_list<T>);
  SuperArray(int, T);
  SuperArray(int);
  int size();
  T &operator[](int);
  ~SuperArray();
  friend std::ostream &operator<<(std::ostream &out, SuperArray<T> &c) {
    for (int i = 0; i < c.size(); i++) {
      out << c[i] << " ";
    }
    return out;
  }
};
} // namespace cmplx::superarr
