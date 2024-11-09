#include "CarPlant.hpp"
#include "randomPercent.hpp"
#include "Storage.cpp"


const int REQUIRED_CAR_DETAILS_ENGINE = 400;
const int REQUIRED_CAR_DETAILS_TRANSMISSION = 300;
const int REQUIRED_CAR_DETAILS_CHASSIS = 200;

const int REQUIRED_MOTORBIKE_DETAILS_ENGINE = 190;
const int REQUIRED_MOTORBIKE_DETAILS_TRANSMISSION = 140;
const int REQUIRED_MOTORBIKE_DETAILS_CHASSIS = 90;


const double PRICE_CAR = 60000;
const double PRICE_MOTORBIKE = 35000;



CarPlant::CarPlant() : money(pow(10,6) * randomPercent()) {
}


void CarPlant::buyEngineDetail(int amount, CarPartsPlant& carPartsPlant, Storage& storage) {
    for (int i = 0; i < amount; i++) {
        if (storage.hasEngineDetail() && CarPlant::money >= DETAIL_COST_ENGINE) {
            carPartsPlant.addMoney(storage.getLastEngineDetail().getQuality() * DETAIL_COST_ENGINE);
            subtractMoney(storage.getLastEngineDetail().getQuality() * DETAIL_COST_ENGINE);
            engineDetail.push_back(storage.getLastEngineDetail());
            storage.removeEngineDetail();
        }
        else break;
    }
}

void CarPlant::buyTransmissionDetail(int amount, CarPartsPlant& carPartsPlant, Storage& storage) {
    for (int i = 0; i < amount; i++) {
        if (storage.hasTransmissionDetail() && CarPlant::money >= DETAIL_COST_TRANSMISSION) {
            carPartsPlant.addMoney(storage.getLastTransmissionDetail().getQuality() * DETAIL_COST_TRANSMISSION);
            subtractMoney(storage.getLastTransmissionDetail().getQuality() * DETAIL_COST_TRANSMISSION);
            transmissionDetail.push_back(storage.getLastTransmissionDetail());
            storage.removeTransmissionDetail();
        }
        else break;
    }
}

void CarPlant::buyChassisDetail(int amount, CarPartsPlant& carPartsPlant, Storage& storage) {
    for (int i = 0; i < amount; i++) {
        if (storage.hasChassisDetail() && CarPlant::money >= DETAIL_COST_CHASSIS) {
            carPartsPlant.addMoney(storage.getLastChassisDetail().getQuality() * DETAIL_COST_CHASSIS);
            subtractMoney(storage.getLastChassisDetail().getQuality() * DETAIL_COST_CHASSIS);
            chassisDetail.push_back(storage.getLastChassisDetail());
            storage.removeChassisDetail();
        }
        else break;
    }
}


double CarPlant::averageEngineQuality() {
    double meanSum = 0;
    for (auto piece : engineDetail)
        meanSum += piece.getQuality();
    if (engineDetail.size() > 0)
        return meanSum / engineDetail.size();
    else return 0;
}

double CarPlant::averageTransmissionQuality() {
    double meanSum = 0;
    for (auto piece : transmissionDetail)
        meanSum += piece.getQuality();
    if (transmissionDetail.size() > 0)
        return meanSum / transmissionDetail.size();
    else return 0;
}

double CarPlant::averageChassisQuality() {
    double meanSum = 0;
    for (auto piece : chassisDetail)
        meanSum += piece.getQuality();
    if (chassisDetail.size() > 0)
        return meanSum / chassisDetail.size();
    else return 0;
}


void CarPlant::makeCar() {
    if (engineDetail.size() >= REQUIRED_CAR_DETAILS_ENGINE
    && transmissionDetail.size() >= REQUIRED_CAR_DETAILS_TRANSMISSION
    && chassisDetail.size() >= REQUIRED_CAR_DETAILS_CHASSIS) {
        Car car1(averageEngineQuality(), averageTransmissionQuality(), averageChassisQuality());
        car.push_back(car1);
        cutVector(engineDetail, REQUIRED_CAR_DETAILS_ENGINE);
        cutVector(transmissionDetail, REQUIRED_CAR_DETAILS_TRANSMISSION);
        cutVector(chassisDetail, REQUIRED_CAR_DETAILS_CHASSIS);

    }
}

void CarPlant::makeMotorbike() {
    if (engineDetail.size() >= REQUIRED_MOTORBIKE_DETAILS_ENGINE
    && transmissionDetail.size() >= REQUIRED_MOTORBIKE_DETAILS_TRANSMISSION
    && chassisDetail.size() >= REQUIRED_MOTORBIKE_DETAILS_CHASSIS) {
        Motorbike motorBike1(averageEngineQuality(), averageTransmissionQuality(), averageChassisQuality());
        motorbike.push_back(motorBike1);
        cutVector(engineDetail, REQUIRED_MOTORBIKE_DETAILS_ENGINE);
        cutVector(transmissionDetail, REQUIRED_MOTORBIKE_DETAILS_TRANSMISSION);
        cutVector(chassisDetail, REQUIRED_MOTORBIKE_DETAILS_CHASSIS);

    }
}

void CarPlant::sellCar(int amount) {
    for (int i = 0; i < amount; i++) {
        if (!car.empty()) {
            money += car.back().getQuality() * PRICE_CAR;
            car.pop_back();
        }
        else break;
    }
}

void CarPlant::sellMotorbike(int amount) {
    for (int i = 0; i < amount; i++) {
        if (!motorbike.empty()) {
            money += motorbike.back().getQuality() * PRICE_MOTORBIKE;
            motorbike.pop_back();
        }
        else break;
    }
}

double CarPlant::getMoney() {
    return money;
}
void CarPlant::addMoney(double amount) {
    money += amount;
}
void CarPlant::subtractMoney(double amount) {
    money -= amount;
}

EngineDetail CarPlant::getLastEngineDetail() {
    return engineDetail.back();
}

TransmissionDetail CarPlant::getLastTransmissionDetail() {
    return transmissionDetail.back();
}

ChassisDetail CarPlant::getLastChassisDetail() {
    return chassisDetail.back();
}