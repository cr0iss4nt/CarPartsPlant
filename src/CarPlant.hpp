#pragma once
#include "CarPartsPlant.hpp"
#include "Storage.hpp"
#include "Car.hpp"
#include "Motorbike.hpp"

class CarPlant {
    private:
        double money;
        std::vector<Car> car;
        std::vector<Motorbike> motorbike;
        std::vector<EngineDetail> engineDetail;
        std::vector<TransmissionDetail> transmissionDetail;
        std::vector<ChassisDetail> chassisDetail;
    public:
        CarPlant();

        void buyEngineDetail(int amount, CarPartsPlant& carPartsPlant, Storage& storage);
        void buyTransmissionDetail(int amount, CarPartsPlant& carPartsPlant, Storage& storage);
        void buyChassisDetail(int amount, CarPartsPlant& carPartsPlant, Storage& storage);

        double averageEngineQuality();
        double averageTransmissionQuality();
        double averageChassisQuality();

        void makeCar();
        void makeMotorbike();

        void sellCar(int amount);
        void sellMotorbike(int amount);

        double getMoney();
        void addMoney(double amount);
        void subtractMoney(double amount);
        
        EngineDetail getLastEngineDetail();
        TransmissionDetail getLastTransmissionDetail();
        ChassisDetail getLastChassisDetail();
};