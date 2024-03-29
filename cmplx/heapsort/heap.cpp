//===-- tests/heap_tests.cpp - Heapsort Implementation -------------------===//
///
/// \file
/// This file contains the implementation for the Heapsort Data structure.
///
//===--------------------------------------------------------------------===//

#include "heap.h"
#include <cassert>

cmplx::heapsort::Heap::Heap(int *RawArr, int Length) {
  // ensuring that the first element is blank
  // need to have an array of pointers to complex numbers
  assert(RawArr[0] == 0);
  this->HeapArr = RawArr;
  this->Length = Length;
}
