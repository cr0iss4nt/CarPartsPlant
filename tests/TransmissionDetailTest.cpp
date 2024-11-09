#include <gtest/gtest.h>
#include "../src/TransmissionDetail.hpp"

TEST(TransmissionDetailTest, getQuality) {
    TransmissionDetail transmissionDetail1(0.2, 0.8, 0.9, 0.7), transmissionDetail2(1, 1, 1, 1), transmissionDetail3(0, 0, 0, 0);
    EXPECT_LE(transmissionDetail1.getQuality(), 0.2 * 0.8 * 0.9 * 0.7);
    EXPECT_LE(transmissionDetail2.getQuality(), 1);
    EXPECT_EQ(transmissionDetail3.getQuality(), 0);
    EXPECT_GE(transmissionDetail1.getQuality(), 0);
    EXPECT_GE(transmissionDetail2.getQuality(), 0);
}