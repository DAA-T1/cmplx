//===-- cmplx/quicksort/quicksort.h - quicksort Definition --------------===//
///
/// \file
/// This file contains the declaration for the quicksort algorithm.
///
//===-----------------------------------------------------------------===//

#pragma once
#include <cmplx/utils/utils.h>

namespace cmplx::quicksort {

template<typename T>
void swap(T &A, T &B) {
  T Temp = A;
  A = B;
  B = Temp;
}

template<typename T>
int partition(T *Arr, int Left, int Right) {
  T Pivot = Arr[Left];
  int I = Left;
  int J = Right;
  while (I < J) {
	while (Arr[I] <= Pivot && I < Right) {
	  I++;
	}
	while (Arr[J] > Pivot && J > Left) {
	  J--;
	}
	if (I < J) {
	  swap(Arr[I], Arr[J]);
	}
  }
  swap(Arr[J], Arr[Left]);
  return J;
}

template<typename T>
void qSort(T *Arr, int Left, int Right) {
  if (Left >= Right) {
	return;
  }
  int Middle = partition(Arr, Left, Right);
  qSort(Arr, Left, Middle - 1);
  qSort(Arr, Middle + 1, Right);
}

template<typename T>
int sort(T *Arr, int Len) {
  qSort(Arr, 0, Len - 1);

  return 0;
}
}// namespace cmplx::quicksort
