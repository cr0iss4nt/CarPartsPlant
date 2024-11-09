#include <gtest/gtest.h>
#include "../src/Car.hpp"

TEST(CarTest, getQuality) {
    Car car(1, 1, 1);
    EXPECT_LE(car.getQuality(), 1);
    EXPECT_GE(car.getQuality(), 0);
}