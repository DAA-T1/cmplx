//===-- tests/heap_tests.cpp - Heapsort Implementation -------------------===//
///
/// \file
/// This file contains the declaration for the Heapsort Data structure.
///
//===--------------------------------------------------------------------===//

#pragma once

namespace cmplx::heapsort {
class Heap {
public:
  int *HeapArr;
  int Length;
  int HeapSize;
  Heap(int *, int);
  // inline functions need to be declared here due to compiler issues
  inline int parent(int Idx) {
	return Idx >> 1;
  }
  inline int left(int Idx) {
	return Idx << 1;
  };
  inline int right(int Idx) {
	return (Idx << 1) + 1;
  };
};
}// namespace cmplx::heapsort