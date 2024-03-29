//===-- cmplx/heapsort/heapsort.cpp - Heapsort Implementation -----------===//
///
/// \file
/// This file contains the implementation of th Heapsort algorithm.
///
//===--------------------------------------------------------------------===//

#include <cmplx/heapsort/heap.h>
#include <cmplx/heapsort/heapsort.h>
#include <iostream>

namespace cmplx::heapsort {
void printHello() {
  std::cout << "Hello!" << std::endl;
}
template<typename T>
void sort(T *Arr, int Length) {
  auto Heap = new cmplx::heapsort::MaxHeap(Arr, Length);
  Heap->heapSort;
}
int getMeaningOfLife() {
  return 42;
}
}// namespace cmplx::heapsort
