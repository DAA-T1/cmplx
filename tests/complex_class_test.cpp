//===-- tests/heap_test.cpp - Tests for Heap ----------------------------===//
///
/// \file
/// This file contains the test cases for the Heap Data structure.
///
//===--------------------------------------------------------------------===//

#include <cmplx/utils/complex.h>
#include <gtest/gtest.h>

// Test for real and imaginary assignment.
TEST(ComplexClassTest, BasicTest) {
  auto *Cn = new cmplx::utils::ComplexNumber(5.0, 7.0);

  EXPECT_EQ(Cn->Real, 5.0);
  EXPECT_EQ(Cn->Imaginary, 7.0);
}

TEST(ComplexClassTest, ComparisionTest) {
  auto Cn = cmplx::utils::ComplexNumber(5.0, 7.0);
  auto Cn2 = cmplx::utils::ComplexNumber(3.0, 7.0);

  EXPECT_EQ(Cn <= Cn2, false);
  EXPECT_EQ(Cn == Cn2, false);
  EXPECT_EQ(Cn >= Cn2, true);
}

// Test for construction of Complex Number from string.
TEST(ComplexClassTest, CreationTest) {
  auto Cn = cmplx::utils::ComplexNumber("5.1 + 7.4i");
  auto Cn2 = cmplx::utils::ComplexNumber("53 - 10i");
  auto Cn3 = cmplx::utils::ComplexNumber("-12 + 40i");
  auto Cn4 = cmplx::utils::ComplexNumber("-53.3 - 45930.30i");
  auto Cn5 = cmplx::utils::ComplexNumber("-53.3 +40.353i");

  EXPECT_EQ(Cn.Real, 5.1);
  EXPECT_EQ(Cn.Imaginary, 7.4);
  EXPECT_EQ(Cn2.Real, 53.0);
  EXPECT_EQ(Cn2.Imaginary, -10.0);
  EXPECT_EQ(Cn3.Real, -12.0);
  EXPECT_EQ(Cn3.Imaginary, 40.0);
  EXPECT_EQ(Cn4.Real, -53.3);
  EXPECT_EQ(Cn4.Imaginary, -45930.30);
  EXPECT_EQ(Cn5.Real, -53.3);
  EXPECT_EQ(Cn5.Imaginary, 40.353);
}
