//===-- cmplx/heapsort/heapsort.h - Heapsort Implementation ----------===//
///
/// \file
/// This file contains the implementation of the Heapsort algorithm.
///
//===-----------------------------------------------------------------===//

#pragma once
#include <cmplx/heapsort/heap.h>
#include <iostream>

namespace cmplx::heapsort {
template<typename T>
void sort(T *Arr, int N) {
  auto *Heap = new cmplx::heapsort::MaxHeap(Arr, N);
  Heap->heapSort();
  delete Heap;
}
}// namespace cmplx::heapsort
