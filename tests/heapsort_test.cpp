//===-- tests/heapsort_test.cpp - Tests for Heapsort  ------------===//
///
/// \file
/// This file contains the test cases for the Heapsort algorithm.
///
//===-------------------------------------------------------------===//

#include <cmplx/heapsort/heapsort.h>
#include <gtest/gtest.h>

// Test for HeapSort with integers.
TEST(HeapSortTest, SortTest) {
  int Nums[] = {0, 8, 6, 20, 10, 15};
  int Sorted[] = {0, 6, 8, 10, 15, 20};
  cmplx::heapsort::sort(Nums, 6);
  for (int Idx = 0; Idx < 6; Idx++) {
	//write to the console in which iteration the error occurred
	SCOPED_TRACE(Idx);
	ASSERT_EQ(Nums[Idx], Sorted[Idx]);
  }

  int Nums1[] = {0, 2, 8, 19, 5, 3, 20, 4, 10,
				 14, 17, 11, 9, 6, 7, 16, 1, 12,
				 15, 13, 18};
  int Sorted1[] = {
	  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  cmplx::heapsort::sort(Nums1, 21);
  for (int Idx = 0; Idx < 6; Idx++) {
	//write to the console in which iteration the error occurred
	SCOPED_TRACE(Idx);
	ASSERT_EQ(Nums1[Idx], Sorted1[Idx]);
  }
}

// Test for HeapSort with floating point numbers.
TEST(HeapSortTest, FloatSortTest) {
  float Nums[] = {0, 0.0001, 0.2, -0.00000032, 10.132, 100.012, 100.011};
  float Sorted[] = {0, -0.00000032, 0.0001, 0.2, 10.132, 100.011, 100.012};
  cmplx::heapsort::sort(Nums, 7);
  for (int Idx = 0; Idx < 7; Idx++) {
	//write to the console in which iteration the error occurred
	SCOPED_TRACE(Idx);
	ASSERT_EQ(Nums[Idx], Sorted[Idx]);
  }
}
