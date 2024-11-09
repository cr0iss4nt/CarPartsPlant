#include <gtest/gtest.h>
#include "../src/CarPlant.hpp"
#include "../src/CarPartsPlant.hpp"
#include "../src/Storage.hpp"
#include <cmath>

TEST(CarPlantTest, constructor) {
    CarPlant carPlant;
    EXPECT_LE(carPlant.getMoney(), pow(10, 6));
    EXPECT_GE(carPlant.getMoney(), 0);
}

TEST(CarPlantTest, money) {
    CarPlant carPlant;
    double currentMoney = carPlant.getMoney();
    carPlant.addMoney(1000);
    EXPECT_EQ(carPlant.getMoney(), currentMoney + 1000);
    currentMoney = carPlant.getMoney();
    carPlant.subtractMoney(666);
    EXPECT_EQ(carPlant.getMoney(), currentMoney - 666);
}

TEST(CarPlantTest, buyDetail) {
    CarPartsPlant carPartsPlant;
    Storage storage;
    for (int i = 0; i < 50; i++) {
        storage.addEngineDetail(1);
        storage.addTransmissionDetail(1);
        storage.addChassisDetail(1);
    }
    CarPlant carPlant;
    carPlant.addMoney(999999);
    double oldPlantMoney = carPlant.getMoney();
    double oldPartsPlantMoney = carPartsPlant.getMoney();
    carPlant.buyEngineDetail(10, carPartsPlant, storage);
    carPlant.buyTransmissionDetail(15, carPartsPlant, storage);
    carPlant.buyChassisDetail(30, carPartsPlant, storage);
    EXPECT_EQ(oldPlantMoney - carPlant.getMoney(), carPartsPlant.getMoney() - oldPartsPlantMoney);
}

TEST(CarPlantTest, averageQuality) {
    CarPartsPlant carPartsPlant;
    Storage storage;
    storage.addEngineDetail(1);
    storage.addTransmissionDetail(1);
    storage.addChassisDetail(1);
    CarPlant carPlant;
    carPlant.addMoney(999999);
    carPlant.buyEngineDetail(1, carPartsPlant, storage);
    carPlant.buyTransmissionDetail(1, carPartsPlant, storage);
    carPlant.buyChassisDetail(1, carPartsPlant, storage);
    EXPECT_EQ(carPlant.averageEngineQuality(), carPlant.getLastEngineDetail().getQuality());
    EXPECT_EQ(carPlant.averageTransmissionQuality(), carPlant.getLastTransmissionDetail().getQuality());
    EXPECT_EQ(carPlant.averageChassisQuality(), carPlant.getLastChassisDetail().getQuality());
}

TEST(CarPlantTest, car) {
    CarPartsPlant carPartsPlant;
    Storage storage;
    CarPlant carPlant;
    carPlant.addMoney(9999999);
    for (int i = 0; i < 400; i++) {
        storage.addEngineDetail(1);
        carPlant.buyEngineDetail(1, carPartsPlant, storage);
    }    
    for (int i = 0; i < 300; i++) {
        storage.addTransmissionDetail(1);
        carPlant.buyTransmissionDetail(1, carPartsPlant, storage);
    }
    for (int i = 0; i < 200; i++) {
        storage.addChassisDetail(1);
        carPlant.buyChassisDetail(1, carPartsPlant, storage);
    }
    double currentPlantMoney = carPlant.getMoney();
    carPlant.makeCar();
    carPlant.sellCar(1);
    EXPECT_LE(carPlant.getMoney() - currentPlantMoney, 60000);
}

TEST(CarPlantTest, motorbike) {
    CarPartsPlant carPartsPlant;
    Storage storage;
    CarPlant carPlant;
    carPlant.addMoney(9999999);
    for (int i = 0; i < 190; i++) {
        storage.addEngineDetail(1);
        carPlant.buyEngineDetail(1, carPartsPlant, storage);
    }    
    for (int i = 0; i < 140; i++) {
        storage.addTransmissionDetail(1);
        carPlant.buyTransmissionDetail(1, carPartsPlant, storage);
    }
    for (int i = 0; i < 90; i++) {
        storage.addChassisDetail(1);
        carPlant.buyChassisDetail(1, carPartsPlant, storage);
    }
    double currentPlantMoney = carPlant.getMoney();
    carPlant.makeMotorbike();
    carPlant.sellMotorbike(1);
    EXPECT_LE(carPlant.getMoney() - currentPlantMoney, 35000);
}