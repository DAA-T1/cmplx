//===-- tests/heap_tests.cpp - Heapsort Implementation -------------------===//
///
/// \file
/// This file contains the implementation for the Heapsort Data structure.
///
//===--------------------------------------------------------------------===//

#include "heap.h"
#include <cassert>
#include <math.h>

cmplx::heapsort::MaxHeap::MaxHeap(int *RawArr, int Length) {
  // ensuring that the first element is blank
  // need to have an array of pointers to complex numbers
  assert(RawArr[0] == 0);
  this->HeapArr = RawArr;
  this->Length = Length;
  this->buildMaxHeap();
}
void cmplx::heapsort::MaxHeap::maxHeapify(int Root) {
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
void cmplx::heapsort::MaxHeap::buildMaxHeap() {
  // 1 less than length since first element is discarded
  this->HeapSize = this->Length - 1;
  for (int Idx = floor(this->Length / 2); Idx > 0; Idx--)
	this->maxHeapify(Idx);
}
