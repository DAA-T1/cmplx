//===-- cmplx/quicksort/quicksort.h - quicksort Definition --------------===//
///
/// \file
/// This file contains the declaration for the quicksort algorithm.
///
//===-----------------------------------------------------------------===//

#pragma once
#include <cmplx/utils/utils.h>

namespace cmplx::quicksort {

int ComparisonCount = 0;

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
	ComparisonCount++;

	while (Arr[I] <= Pivot && I < Right) {
	  ComparisonCount += 2;
	  I++;
	}
	while (Arr[J] > Pivot && J > Left) {
	  ComparisonCount += 2;
	  J--;
	}
	ComparisonCount++;
	if (I < J) {
	  swap(Arr[I], Arr[J]);
	}
  }
  swap(Arr[J], Arr[Left]);
  return J;
}

template<typename T>
void qSort(T *Arr, int Left, int Right) {
  ComparisonCount++;
  if (Left >= Right) {
	return;
  }
  int Middle = partition(Arr, Left, Right);
  qSort(Arr, Left, Middle - 1);
  qSort(Arr, Middle + 1, Right);
}

template<typename T>
int sort(T *Arr, int Len) {
  ComparisonCount = 0;

  qSort(Arr, 0, Len - 1);

  return ComparisonCount;
}
}// namespace cmplx::quicksort
