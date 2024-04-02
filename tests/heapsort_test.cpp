//===-- tests/heapsort_test.cpp - Tests for Heapsort  ------------===//
///
/// \file
/// This file contains the test cases for the Heapsort algorithm.
///
//===-------------------------------------------------------------===//

#include <cmplx/heapsort/heapsort.h>
//#include <cmplx/utils/complex.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(HeapSortTest, SingleSortTest) {
  int V[] = {42};
  cmplx::heapsort::sort(V, 1);

  ASSERT_THAT(V, testing::ElementsAre(42));
}

TEST(HeapSortTest, SortedArrayTest) {
  int V[] = {0, 6, 8, 9, 10, 15};
  cmplx::heapsort::sort(V, 6);

  ASSERT_THAT(V, testing::ElementsAre(0, 6, 8, 9, 10, 15));
}

TEST(HeapSortTest, UnSortedArrayTest) {
  int V[] = {16, 10, 9, 8, -2};
  cmplx::heapsort::sort(V, 5);

  ASSERT_THAT(V, testing::ElementsAre(-2, 8, 9, 10, 16));
}

TEST(HeapSortTest, DuplicateElementArrayTest) {
  int V[] = {1, 1, 5, 4, 4, 3};
  cmplx::heapsort::sort(V, 6);

  ASSERT_THAT(V, testing::ElementsAre(1, 1, 3, 4, 4, 5));
}

// Test for HeapSort with integers.
TEST(HeapSortTest, SortTest) {
  int Nums[] = {0, 8, 6, 20, 10, 15};
  cmplx::heapsort::sort(Nums, 6);

  ASSERT_THAT(Nums, testing::ElementsAre(0, 6, 8, 10, 15, 20));

  int Nums1[] = {0, 2, 8, 19, 5, 3, 20, 4, 10,
				 14, 17, 11, 9, 6, 7, 16, 1, 12,
				 15, 13, 18};
  cmplx::heapsort::sort(Nums1, 21);

  ASSERT_THAT(Nums1, testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20));
}

// Test for HeapSort with floating point numbers.
TEST(HeapSortTest, FloatSortTest) {
  float Nums[] = {0, 0.0001, 0.2, -0.00000032, 10.132, 100.012, 100.011};
  cmplx::heapsort::sort(Nums, 7);

  ASSERT_THAT(Nums, testing::ElementsAre(-0.00000032, 0, 0.0001, 0.2, 10.132, 100.011, 100.012));
}
