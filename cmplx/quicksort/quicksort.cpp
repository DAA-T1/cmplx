//===-- cmplx/quicksort/quicksort.cpp - quicksort Implementation -----------===//
///
/// \file
/// This file contains the implementation of the quicksort algorithm.
///
//===--------------------------------------------------------------------===//

#include <cmplx/quicksort/quicksort.h>

using namespace cmplx::quicksort;

template<typename T>
void swap(T *A, T *B) {
  auto Temp = *A;
  *A = *B;
  *B = Temp;
}

int partition(std::vector<int> &Vec, int Left, int Right) {
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

void qSort(std::vector<int> &Vec, int Left, int Right) {
  if (Left >= Right) {
	return;
  }
  int Middle = partition(Vec, Left, Right);
  qSort(Vec, Left, Middle);
  qSort(Vec, Middle + 1, Right);
}

void cmplx::quicksort::sort(std::vector<int> &Vec) {
  qSort(Vec, 0, Vec.size() - 1);
}
