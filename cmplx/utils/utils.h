#pragma once
#include <iostream>

namespace cmplx::utils {
template<typename T>
void printArray(T *Arr, int N) {
  for (int I = 0; I < N - 1; I++) {
	std::cout << Arr[I] << ", ";
  }
  std::cout << Arr[N - 1] << std::endl;
}

}// namespace cmplx::utils