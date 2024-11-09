#include <gtest/gtest.h>
#include "../src/randomPercent.hpp"

TEST(randomDoubleTest, randomDoubleFunction) {
    double value1 = randomPercent();
    double value2 = randomPercent();
    double value3 = randomPercent();
    EXPECT_LE(value1, 1);
    EXPECT_LE(value2, 1);
    EXPECT_LE(value3, 1);
    EXPECT_GE(value1, 0);
    EXPECT_GE(value2, 0);
    EXPECT_GE(value3, 0);
}