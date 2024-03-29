//===-- tests/heap_tests.cpp - Heapsort Implementation -----------===//
///
/// \file
/// This file contains the test cases for the Heapsort Data structure.
///
//===--------------------------------------------------------------------===//

#include <cmplx/heapsort/heap.h>
#include <gtest/gtest.h>

// Test for parent, left and right idx logic.
TEST(HeapTest, TreeRelationships) {
  int Nums[] = {0, 1, 2, 3, 4, 5, 6};
  auto *Heap = new cmplx::heapsort::MaxHeap(Nums, 7);

  EXPECT_EQ(Heap->parent(2), 1);
  EXPECT_EQ(Heap->parent(3), 1);
  EXPECT_EQ(Heap->right(1), 3);
  EXPECT_EQ(Heap->left(1), 2);
  EXPECT_EQ(Heap->parent(10), 5);
  EXPECT_EQ(Heap->right(3), 7);
  EXPECT_EQ(Heap->left(3), 6);
}

// Test for max-heapify.
TEST(HeapTest, MaxHeapifyTest) {
  int Nums[] = {0, 1, 2, 3};
  int HeapNums[] = {0, 3, 2, 1};
  auto *Heap = new cmplx::heapsort::MaxHeap(Nums, 4);
  // setting HeapSize manually since buildHeap hasn't been run
  Heap->HeapSize = 4;
  Heap->maxHeapify(1);

  for (int Idx = 0; Idx < Heap->Length; Idx++) {
	SCOPED_TRACE(Idx);//write to the console in which iteration the error occurred
	ASSERT_EQ(Heap->HeapArr[Idx], HeapNums[Idx]);
  }
}