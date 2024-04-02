//===-- cmplx/heapsort/heap.h - Heapsort Implementation ----------------------------===//
///
/// \file
/// This file contains the generic implementation for the Heapsort Data structure.
///
//===------------------------------------------------------------------------------===//

#pragma once

#include <math.h>

namespace cmplx::heapsort {
int ComparisonCount;

template<class T>
class MaxHeap {
public:
  T *HeapArr;
  int Length;
  int HeapSize;

  MaxHeap(T *RawArr, int Length) {
	this->HeapArr = RawArr;
	this->Length = Length;
	this->buildMaxHeap();
  }

  inline int parent(int Idx) {
	return (Idx - 1) >> 1;
  }
  inline int left(int Idx) {
	return (Idx << 1) + 1;
  };
  inline int right(int Idx) {
	return (Idx << 1) + 2;
  };

  void maxHeapify(int Root) {
	auto Left = this->left(Root);
	auto Right = this->right(Root);
	int Largest;

	if (Left <= this->HeapSize && this->HeapArr[Left] > this->HeapArr[Root]) {
	  ComparisonCount++;
	  Largest = Left;
	} else {
	  ComparisonCount++;
	  Largest = Root;
	}
	if (Right <= this->HeapSize && this->HeapArr[Right] > this->HeapArr[Largest]) {
	  ComparisonCount++;
	  Largest = Right;
	}
	if (Largest != Root) {
	  exchange(Root, Largest);
	  this->maxHeapify(Largest);
	}
  }

  void buildMaxHeap() {
	// 1 less than length since first element is discarded
	this->HeapSize = this->Length - 1;
	for (int Idx = parent(this->Length - 1); Idx >= 0; Idx--) {
	  this->maxHeapify(Idx);
	}
  }

  void heapSort() {
	for (int Idx = this->Length - 1; Idx >= 1; Idx--) {
	  this->exchange(0, Idx);
	  this->HeapSize--;
	  this->maxHeapify(0);
	}
  }

private:
  void exchange(int A, int B) {
	auto Temp = this->HeapArr[A];
	this->HeapArr[A] = this->HeapArr[B];
	this->HeapArr[B] = Temp;
  }
};
}// namespace cmplx::heapsort