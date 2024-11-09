#include <gtest/gtest.h>
#include "../src/EngineDetail.hpp"

TEST(EngineDetailTest, getQuality) {
    EngineDetail engineDetail1(0.2, 0.8, 0.9), engineDetail2(1, 1, 1), engineDetail3(0, 0, 0);
    EXPECT_LE(engineDetail1.getQuality(), 0.2 * 0.8 * 0.9);
    EXPECT_LE(engineDetail2.getQuality(), 1);
    EXPECT_EQ(engineDetail3.getQuality(), 0);
    EXPECT_GE(engineDetail1.getQuality(), 0);
    EXPECT_GE(engineDetail2.getQuality(), 0);
}