#include <cmplx/quicksort/quicksort.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(QuickSortTest, TestSingleElement) {
  int V[] = {42};
  cmplx::quicksort::sort(V, 1);

  EXPECT_EQ(V[0], 42) << "the element is not 42";
}

TEST(QuickSortTest, TestTwoElements) {
  int V[] = {42, -42};
  cmplx::quicksort::sort(V, 2);

  ASSERT_THAT(V, testing::ElementsAre(-42, 42));
}

TEST(QuickSortTest, TestThreeElements) {
  int V[] = {0, 42, -42};
  cmplx::quicksort::sort(V, 3);

  ASSERT_THAT(V, testing::ElementsAre(-42, 0, 42));
}

TEST(QuickSortTest, TestForReal) {
  int V[] = {7, 2, -12, 13, 42, 21, -42, 0};
  cmplx::quicksort::sort(V, 8);

  ASSERT_THAT(V, testing::ElementsAre(-42, -12, 0, 2, 7, 13, 21, 42));
}

TEST(QuickSortTest, TestForRealFloats) {
  double V[] = {7.0, 2.0, -12.0, 13.0, 42.0, 21.0, -42.0, 0.0};
  cmplx::quicksort::sort(V, 8);

  ASSERT_THAT(V, testing::ElementsAre(-42.0, -12.0, 0.0, 2.0, 7.0, 13.0, 21.0, 42.0));
}

TEST(QuickSortTest, TestForRealAgain) {
  int V[] = {100000, 10000, 1000, 100, 10, 1, 0, -1, -10, -100, -1000, -10000, -100000};
  cmplx::quicksort::sort(V, 13);

  ASSERT_THAT(V, testing::ElementsAre(-100000, -10000, -1000, -100, -10, -1, 0, 1, 10, 100, 1000, 10000, 100000));
}

TEST(QuickSortTest, TestForRealAgainFloats) {
  double V[] = {100000.0, 10000.0, 1000.0, 100.0, 10.0, 1.0, 0.0, -1.0, -10.0, -100.0, -1000.0, -10000.0, -100000.0};
  cmplx::quicksort::sort(V, 13);

  ASSERT_THAT(V, testing::ElementsAre(-100000.0, -10000.0, -1000.0, -100.0, -10.0, -1.0, 0.0, 1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0));
}
