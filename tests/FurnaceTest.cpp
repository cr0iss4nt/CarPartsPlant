#include <gtest/gtest.h>
#include "../src/Furnace.hpp"
#include "../src/Storage.hpp"
#include "../src/CarPartsPlant.hpp"

TEST(FurnaceTest, getPerformance) {
    Furnace furnace1, furnace2, furnace3;
    EXPECT_LE(furnace1.getPerformance(), 1);
    EXPECT_LE(furnace2.getPerformance(), 1);
    EXPECT_LE(furnace3.getPerformance(), 1);
    EXPECT_GE(furnace1.getPerformance(), 0);
    EXPECT_GE(furnace2.getPerformance(), 0);
    EXPECT_GE(furnace3.getPerformance(), 0);
}

TEST(FurnaceTest, makeDetail) {
    CarPartsPlant carPartsPlant;
    Storage storage;
    Furnace furnace;
    carPartsPlant.addMoney(99999999);
    storage.buySteel(100, carPartsPlant);
    EXPECT_EQ(storage.amountSteel(), 100);
    storage.buyCastIron(666, carPartsPlant);
    EXPECT_EQ(storage.amountCastIron(), 666);
    storage.buyAluminum(444, carPartsPlant);
    EXPECT_EQ(storage.amountAluminum(), 444);
    furnace.makeEngineDetail(1, storage);
    furnace.makeTransmissionDetail(1, storage);
    furnace.makeChassisDetail(1, storage);
    EXPECT_TRUE(storage.hasEngineDetail());
    EXPECT_TRUE(storage.hasTransmissionDetail());
    EXPECT_TRUE(storage.hasChassisDetail());
}