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

d TEST(ComplexClassTest, CreationTest) {
  auto cn = cmplx::utils::ComplexNumber::constructFromString("5.1 + 7.4i");
  auto cn2 = cmplx::utils::ComplexNumber::constructFromString("53 - 10i");
  auto cn3 = cmplx::utils::ComplexNumber::constructFromString("-12 + 40i");
  auto cn4 = cmplx::utils::ComplexNumber::constructFromString("-53.3 - 45930.30i");
  auto cn5 = cmplx::utils::ComplexNumber::constructFromString("-53.3 +40.353i");

  EXPECT_EQ(cn.Real, 5.1);
  EXPECT_EQ(cn.Imaginary, 7.4);
  EXPECT_EQ(cn2.Real, 53.0);
  EXPECT_EQ(cn2.Imaginary, -10.0);
  EXPECT_EQ(cn3.Real, -12.0);
  EXPECT_EQ(cn3.Imaginary, 40.0);
  EXPECT_EQ(cn4.Real, -53.3);
  EXPECT_EQ(cn4.Imaginary, -45930.30);
  EXPECT_EQ(cn5.Real, -53.3);
  EXPECT_EQ(cn5.Imaginary, 40.353);
}
