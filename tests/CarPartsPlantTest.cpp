#include <gtest/gtest.h>
#include "../src/CarPartsPlant.hpp"
#include <cmath>

TEST(CarPartsPlantTest, constructor) {
    CarPartsPlant carPartsPlant;
    EXPECT_LE(carPartsPlant.getMoney(), pow(10,6));
    EXPECT_GE(carPartsPlant.getMoney(), 0);
}

TEST(CarPartsPlantTest, money) {
    CarPartsPlant carPartsPlant;
    double currentMoney = carPartsPlant.getMoney();
    carPartsPlant.addMoney(1000);
    EXPECT_EQ(carPartsPlant.getMoney(), currentMoney + 1000);
    currentMoney = carPartsPlant.getMoney();
    carPartsPlant.subtractMoney(666);
    EXPECT_EQ(carPartsPlant.getMoney(), currentMoney - 666);
}