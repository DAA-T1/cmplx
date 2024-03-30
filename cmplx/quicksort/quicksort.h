//===-- cmplx/quicksort/quicksort.h - quicksort Definition --------------===//
///
/// \file
/// This file contains the declaration for the quicksort algorithm.
///
//===-----------------------------------------------------------------===//

#pragma once

#include <vector>

namespace cmplx::quicksort {
template<typename T>
void swap(T *A, T *B) {
  auto Temp = *A;
  *A = *B;
  *B = Temp;
}

template<typename T>
int partition(std::vector<T> &Vec, int Left, int Right) {
  int Pivot = Vec[Left];
  int I = Left - 1;
  int J = Right + 1;

  while (true) {
	do {
	  I++;
	} while (Vec[I] < Pivot);

	do {
	  J--;
	} while (Vec[J] > Pivot);

	if (I >= J) {
	  return J;
	}
	swap(&Vec[I], &Vec[J]);
  }
  // unreachable
}

template<typename T>
void qSort(std::vector<T> &Vec, int Left, int Right) {
  if (Left >= Right) {
	return;
  }
  int Middle = partition(Vec, Left, Right);
  qSort(Vec, Left, Middle);
  qSort(Vec, Middle + 1, Right);
}

template<typename T>
void sort(std::vector<T> &Vec) {
  qSort(Vec, 0, Vec.size() - 1);
}
}// namespace cmplx::quicksort
