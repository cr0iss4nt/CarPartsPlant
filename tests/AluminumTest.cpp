#include <gtest/gtest.h>
#include "../src/Aluminum.hpp"

TEST(AluminumTest, getQuality) {
    Aluminum aluminum1, aluminum2, aluminum3;
    EXPECT_LE(aluminum1.getQuality(), 1);
    EXPECT_LE(aluminum2.getQuality(), 1);
    EXPECT_LE(aluminum3.getQuality(), 1);
    EXPECT_GE(aluminum1.getQuality(), 0);
    EXPECT_GE(aluminum2.getQuality(), 0);
    EXPECT_GE(aluminum3.getQuality(), 0);
}