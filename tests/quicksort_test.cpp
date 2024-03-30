#include <cmplx/quicksort/quicksort.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace cmplx::quicksort;

TEST(QuickSortTest, TestSingleElement) {
  std::vector<int> v{42};
  sort(v);

  EXPECT_EQ(v[0], 42) << "the element is not 42";
}

TEST(QuickSortTest, TestTwoElements) {
  std::vector<int> v{42, -42};
  sort(v);

  ASSERT_THAT(v, testing::ElementsAre(-42, 42));
}

TEST(QuickSortTest, TestThreeElements) {
  std::vector<int> v{0, 42, -42};
  sort(v);

  ASSERT_THAT(v, testing::ElementsAre(-42, 0, 42));
}

TEST(QuickSortTest, TestForReal) {
  std::vector<int> v{7, 2, -12, 13, 42, 21, -42, 0};
  sort(v);
  ASSERT_THAT(v, testing::ElementsAre(-42, -12, 0, 2, 7, 13, 21, 42));
}
