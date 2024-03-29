//===-- tests/heap_tests.cpp - Heapsort Implementation -----------===//
///
/// \file
/// This file contains the test cases for the Heapsort algorithm.
///
//===--------------------------------------------------------------------===//

#include <cmplx/heapsort/heapsort.h>
#include <gtest/gtest.h>

// Test for HeapSort.
TEST(HeapSortTest, SortTest) {
  int Nums[] = {0, 8, 6, 20, 10, 15};
  int Sorted[] = {0, 6, 8, 10, 15, 20};
  cmplx::heapsort::sort(Nums, 6);
  for (int Idx = 0; Idx < 6; Idx++) {
	//write to the console in which iteration the error occurred
	SCOPED_TRACE(Idx);
	ASSERT_EQ(Nums[Idx], Sorted[Idx]);
  }
}
