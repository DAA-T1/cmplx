//===-- cmplx/quicksort/quicksort.h - quicksort Definition --------------===//
///
/// \file
/// This file contains the declaration for the quicksort algorithm.
///
//===-----------------------------------------------------------------===//

#pragma once

namespace cmplx::quicksort {
template<typename T>
void swap(T *A, T *B) {
  auto Temp = *A;
  *A = *B;
  *B = Temp;
}

template<typename T>
int partition(T *Arr, int Left, int Right) {
  T Pivot = Arr[Left];
  int I = Left - 1;
  int J = Right + 1;

  while (true) {
	do {
	  I++;
	} while (Arr[I] < Pivot);

	do {
	  J--;
	} while (Arr[J] > Pivot);

	if (I >= J) {
	  return J;
	}
	swap(&Arr[I], &Arr[J]);
  }
  // unreachable
}

template<typename T>
void qSort(T *Arr, int Left, int Right) {
  if (Left >= Right) {
	return;
  }
  int Middle = partition(Arr, Left, Right);
  qSort(Arr, Left, Middle);
  qSort(Arr, Middle + 1, Right);
}

template<typename T>
void sort(T *Arr, int Len) {
  qSort(Arr, 0, Len - 1);
}
}// namespace cmplx::quicksort
