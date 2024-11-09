#include <gtest/gtest.h>
#include "../src/ChassisDetail.hpp"

TEST(ChassisDetailTest, getQuality) {
    ChassisDetail chassisDetail1(0.2, 0.8, 0.9, 0.7), chassisDetail2(1, 1, 1, 1), chassisDetail3(0, 0, 0, 0);
    EXPECT_LE(chassisDetail1.getQuality(), 0.2 * 0.8 * 0.9 * 0.7);
    EXPECT_LE(chassisDetail2.getQuality(), 1);
    EXPECT_EQ(chassisDetail3.getQuality(), 0);
    EXPECT_GE(chassisDetail1.getQuality(), 0);
    EXPECT_GE(chassisDetail2.getQuality(), 0);
}