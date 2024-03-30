//===-- cmplx/superarr/superarr.h - Super Array Definition (and Implementation)--------------===//
///
/// \file
/// This file contains the declaration of the Super Array data structure.
///
//===-----------------------------------------------------------------===//

#pragma once
#include <iostream>

namespace cmplx::superarr {
template <typename T> class SuperArray {
  int N;
  T *Arr;

public:
  SuperArray(std::initializer_list<T> InitList) {
	Arr = new T[N];
	T *Ptr = Arr;
	for (auto &c : InitList) {
	  *Ptr++ = c;
	}
  }
  SuperArray(int Size, T Elem) {
	N = Size;
	Arr = new T[N];
	for (int i = 0; i < N; i++) {
	  Arr[i] = Elem;
	}
  }
  SuperArray(int Size) {
	N = Size;
	Arr = new T[N]();
  }
  int size() { return N; }

  T &operator[](int Ind) {
	if (Ind >= N) {
	  std::cout << "Out of bounds access." << std::endl;
	  exit(0);
	}
	return Arr[Ind];
  }

  ~SuperArray() { delete[] Arr; }
  friend std::ostream &operator<<(std::ostream &Out, SuperArray<T> &C) {
    for (int i = 0; i < C.size(); i++) {
      Out << C[i] << " ";
    }
    return Out;
  }
};
} // namespace cmplx::superarr
