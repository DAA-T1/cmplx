//===-- tests/heap_tests.cpp - Heapsort Implementation -------------------===//
///
/// \file
/// This file contains the declaration for the Heapsort Data structure.
///
//===--------------------------------------------------------------------===//

#pragma once

namespace cmplx::heapsort {
class MaxHeap {
public:
  int *HeapArr;
  int Length;
  int HeapSize;
  MaxHeap(int *, int);
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

  void maxHeapify(int);
  void buildMaxHeap();

private:
  // @todo write test case for this function
  void exchange(int A, int B) {
	auto Temp = this->HeapArr[A];
	this->HeapArr[A] = this->HeapArr[B];
	this->HeapArr[B] = Temp;
  }
};
}// namespace cmplx::heapsort