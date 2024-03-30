#include <cmplx/quicksort/quicksort.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(QuickSortTest, TestSingleElement) {
  std::vector<int> V{42};
  cmplx::quicksort::sort(V);

  EXPECT_EQ(V[0], 42) << "the element is not 42";
}

TEST(QuickSortTest, TestTwoElements) {
  std::vector<int> V{42, -42};
  cmplx::quicksort::sort(V);

  ASSERT_THAT(V, testing::ElementsAre(-42, 42));
}

TEST(QuickSortTest, TestThreeElements) {
  std::vector<int> V{0, 42, -42};
  cmplx::quicksort::sort(V);

  ASSERT_THAT(V, testing::ElementsAre(-42, 0, 42));
}

TEST(QuickSortTest, TestForReal) {
  std::vector<int> V{7, 2, -12, 13, 42, 21, -42, 0};
  cmplx::quicksort::sort(V);

  ASSERT_THAT(V, testing::ElementsAre(-42, -12, 0, 2, 7, 13, 21, 42));
}
