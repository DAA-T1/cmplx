//===-- tests/heap_test.cpp - Tests for Heap -----------===//
///
/// \file
/// This file contains the test cases for the Heap Data structure.
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
  // setting the raw manually since heap property is established in the constructor.
  Heap->HeapArr = Nums;
  Heap->maxHeapify(1);

  for (int Idx = 0; Idx < Heap->Length; Idx++) {
	SCOPED_TRACE(Idx);//write to the console in which iteration the error occurred
	ASSERT_EQ(Heap->HeapArr[Idx], HeapNums[Idx]);
  }
}

// Test for buildHeap.
TEST(HeapTest, BuildMaxHeapTest) {
  int Nums[] = {0, 1, 2, 3};
  int HeapNums[] = {0, 3, 2, 1};
  auto *Heap = new cmplx::heapsort::MaxHeap(Nums, 4);
  Heap->buildMaxHeap();
  for (int Idx = 0; Idx < Heap->Length; Idx++) {
	//write to the console in which iteration the error occurred
	SCOPED_TRACE(Idx);
	ASSERT_EQ(Heap->HeapArr[Idx], HeapNums[Idx]);
  }
}

// Test for HeapSort.
TEST(HeapTest, HeapSortTest) {
  int Nums[] = {0, 8, 6, 20, 10, 15};
  int Sorted[] = {0, 6, 8, 10, 15, 20};
  auto *Heap = new cmplx::heapsort::MaxHeap(Nums, 6);
  Heap->heapSort();
  for (int Idx = 0; Idx < Heap->Length; Idx++) {
	//write to the console in which iteration the error occurred
	SCOPED_TRACE(Idx);
	ASSERT_EQ(Heap->HeapArr[Idx], Sorted[Idx]);
  }

  int Nums1[] = {0, 2, 8, 19, 5, 3, 20, 4, 10,
				 14, 17, 11, 9, 6, 7, 16, 1, 12,
				 15, 13, 18};
  int Sorted1[] = {
	  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  Heap = new cmplx::heapsort::MaxHeap(Nums1, 21);
  Heap->heapSort();
  for (int Idx = 0; Idx < Heap->Length; Idx++) {
	//write to the console in which iteration the error occurred
	SCOPED_TRACE(Idx);
	ASSERT_EQ(Heap->HeapArr[Idx], Sorted1[Idx]);
  }
}
