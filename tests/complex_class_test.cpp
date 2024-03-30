//===-- tests/heap_test.cpp - Tests for Heap ----------------------------===//
///
/// \file
/// This file contains the test cases for the Heap Data structure.
///
//===--------------------------------------------------------------------===//

#include <cmplx/utils/complex.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// Test for parent, left and right idx logic.
TEST(ComplexClassTest, BasicTest) {
  auto cn = new cmplx::utils::ComplexNumber(5.0, 7.0);

  EXPECT_EQ(cn->Real, 5.0);
  EXPECT_EQ(cn->Imaginary, 5.0);
}

TEST(ComplexClassTest, ComparisionTest) {
  auto cn = new cmplx::utils::ComplexNumber(5.0, 7.0);
  auto cn2 = new cmplx::utils::ComplexNumber(3.0, 7.0);

  EXPECT_EQ(cn <= cn2, true);
  EXPECT_EQ(cn == cn2, false);
  EXPECT_EQ(cn >= cn2, false);
}
