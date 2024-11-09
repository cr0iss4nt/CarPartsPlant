#include <gtest/gtest.h>
#include "../src/CastIron.hpp"

TEST(CastIronTest, getQuality) {
    CastIron castIron1, castIron2, castIron3;
    EXPECT_LE(castIron1.getQuality(), 1);
    EXPECT_LE(castIron2.getQuality(), 1);
    EXPECT_LE(castIron3.getQuality(), 1);
    EXPECT_GE(castIron1.getQuality(), 0);
    EXPECT_GE(castIron2.getQuality(), 0);
    EXPECT_GE(castIron3.getQuality(), 0);
}