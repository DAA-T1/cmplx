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