#include <cmplx/heapsort/heapsort.h>
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(LifeTest, TestAssertions) {
  // Expect equality.
  EXPECT_EQ(cmplx::heapsort::getMeaningOfLife(), 42);
}
