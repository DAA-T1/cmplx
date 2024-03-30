#pragma once
#include <iostream>

namespace cmplx::utils {
template <typename T>
void swap(T &A, T &B) {
  T Temp = A;
  A = B;
  B = Temp;
}
template <typename T>
void printArray(T* Arr, int N) {
  for (int I = 0; I < N; I++) {
	std::cout << Arr[I] << " ";
  }
  std::cout << std::endl;
}

}// namespace cmplx::heapsort