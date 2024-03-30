//===-- cmplx/quicksort/quicksort.cpp - quicksort Implementation -----------===//
///
/// \file
/// This file contains the implementation of the quicksort algorithm.
///
//===--------------------------------------------------------------------===//

#include <cmplx/quicksort/quicksort.hpp>

namespace cmplx::quicksort {
int partition(std::vector<int> &Vec, int Left, int Right) {
  int Pivot = Vec[Right];
  int I = Left - 1;

  for (int J = Left; J < Right; J++) {
	if (Vec[J] <= Pivot) {
	  I++;
	  std::swap(Vec[I], Vec[J]);
	}
  }
  std::swap(Vec[I + 1], Vec[Right]);

  return I + 1;
}

void qSort(std::vector<int> &Vec, int Left, int Right) {
  if (Left >= Right) {
	return;
  }
  int Middle = partition(Vec, Left, Right);
  qSort(Vec, Left, Middle - 1);
  qSort(Vec, Middle + 1, Right);
}

void sort(std::vector<int> &Vec) {
  qSort(Vec, 0, Vec.size() - 1);
}
}// namespace cmplx::quicksort
