#include <gtest/gtest.h>
#include "../src/Steel.hpp"

TEST(SteelTest, getQuality) {
    Steel steel1, steel2, steel3;
    EXPECT_LE(steel1.getQuality(), 1);
    EXPECT_LE(steel2.getQuality(), 1);
    EXPECT_LE(steel3.getQuality(), 1);
    EXPECT_GE(steel1.getQuality(), 0);
    EXPECT_GE(steel2.getQuality(), 0);
    EXPECT_GE(steel3.getQuality(), 0);
}