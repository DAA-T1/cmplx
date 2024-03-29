//===-- tests/heap_tests.cpp - Heapsort Implementation ----------------------------===//
///
/// \file
/// This file contains the generic implementation for the Heapsort Data structure.
///
//===------------------------------------------------------------------------------===//

#pragma once

#include <cassert>
#include <math.h>

namespace cmplx::heapsort {
template<class T>
class MaxHeap {
public:
  T *HeapArr;
  int Length;
  int HeapSize;

  MaxHeap(T *RawArr, int Length) {
	// ensuring that the first element is blank
	// need to have an array of pointers to complex numbers
	assert(RawArr[0] == 0);
	this->HeapArr = RawArr;
	this->Length = Length;
	this->buildMaxHeap();
  }

  inline int parent(int Idx) {
	return Idx >> 1;
  }
  inline int left(int Idx) {
	return Idx << 1;
  };
  inline int right(int Idx) {
	return (Idx << 1) + 1;
  };

  void maxHeapify(int Root) {
	auto Left = this->left(Root);
	auto Right = this->right(Root);
	int Largest;

	if (Left <= this->HeapSize && this->HeapArr[Left] > this->HeapArr[Root])
	  Largest = Left;
	else
	  Largest = Root;
	if (Right <= this->HeapSize && this->HeapArr[Right] > this->HeapArr[Largest])
	  Largest = Right;
	if (Largest != Root) {
	  exchange(Root, Largest);
	  this->maxHeapify(Largest);
	}
  }

  void buildMaxHeap() {
	// 1 less than length since first element is discarded
	this->HeapSize = this->Length - 1;
	for (int Idx = floor(this->Length / 2); Idx > 0; Idx--)
	  this->maxHeapify(Idx);
  }

  void heapSort() {
	for (int idx = this->Length - 1; idx >= 2; idx--) {
	  this->exchange(1, idx);
	  this->HeapSize--;
	  this->maxHeapify(1);
	}
  }

private:
  // @todo write test case for this function
  void exchange(int A, int B) {
	auto Temp = this->HeapArr[A];
	this->HeapArr[A] = this->HeapArr[B];
	this->HeapArr[B] = Temp;
  }
};
}// namespace cmplx::heapsort