#include <gtest/gtest.h>
#include "../src/Motorbike.hpp"

TEST(MotorBikeTest, getQuality) {
    Motorbike motorbike(1, 1, 1);
    EXPECT_LE(motorbike.getQuality(), 1);
    EXPECT_GE(motorbike.getQuality(), 0);
}