#include <gtest/gtest.h>
#include "../src/Storage.hpp"

TEST(StorageTest, hasDetail) {
    Storage storage;
    EXPECT_FALSE(storage.hasEngineDetail());
    EXPECT_FALSE(storage.hasTransmissionDetail());
    EXPECT_FALSE(storage.hasChassisDetail());
    storage.addEngineDetail(1);
    storage.addTransmissionDetail(1);
    storage.addChassisDetail(1);
    EXPECT_TRUE(storage.hasEngineDetail());
    EXPECT_TRUE(storage.hasTransmissionDetail());
    EXPECT_TRUE(storage.hasChassisDetail());
    storage.removeEngineDetail();
    EXPECT_FALSE(storage.hasEngineDetail());
    storage.removeTransmissionDetail();
    EXPECT_FALSE(storage.hasTransmissionDetail());
    storage.removeChassisDetail();
    EXPECT_FALSE(storage.hasChassisDetail());
}

TEST(StorageTest, getLastDetail) {
    Storage storage;
    CarPartsPlant carPartsPlant;
    carPartsPlant.addMoney(999999);
    storage.buySteel(1, carPartsPlant);
    storage.buyCastIron(1, carPartsPlant);
    storage.buyAluminum(1, carPartsPlant);
    storage.addEngineDetail(1);
    storage.addTransmissionDetail(1);
    storage.addChassisDetail(1);
    double lastEngineQuality = storage.getLastEngineDetail().getQuality();
    double lastTransmissionQuality = storage.getLastTransmissionDetail().getQuality();
    double lastChassisQuality = storage.getLastChassisDetail().getQuality();

    EXPECT_LE(lastEngineQuality, storage.averageSteelQuality() * storage.averageCastIronQuality());

    EXPECT_LE(lastTransmissionQuality,
    storage.averageSteelQuality() * storage.averageCastIronQuality() * storage.averageAluminumQuality());

    EXPECT_LE(lastChassisQuality,
    storage.averageSteelQuality() * storage.averageCastIronQuality() * storage.averageAluminumQuality());

    EXPECT_GE(lastEngineQuality, 0);
    EXPECT_GE(lastTransmissionQuality, 0);
    EXPECT_GE(lastChassisQuality, 0);
}