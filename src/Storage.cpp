#include "Storage.hpp"
#include "Steel.hpp"
#include "CastIron.hpp"
#include "Aluminum.hpp"
#include "CarPartsPlant.hpp"
#include "cutVector.hpp"


const double PIECE_COST_ALUMINUM = 2.6354;
const double PIECE_COST_STEEL = 1.05;
const double PIECE_COST_CAST_IRON = 1.407;

const double DETAIL_COST_ENGINE = 60;
const double DETAIL_COST_TRANSMISSION = 50;
const double DETAIL_COST_CHASSIS = 40;

void Storage::buyAluminum(int amount, CarPartsPlant& carPartsPlant) {
    if (carPartsPlant.getMoney() > PIECE_COST_ALUMINUM * amount) {
        carPartsPlant.subtractMoney(PIECE_COST_ALUMINUM * amount);
        for (int i = 0; i < amount; i++) {
            Aluminum aluminum1;
            aluminum.push_back(aluminum1);
        }
    }
}

void Storage::buySteel(int amount, CarPartsPlant& carPartsPlant) {
    if (carPartsPlant.getMoney() > PIECE_COST_STEEL * amount) {
        carPartsPlant.subtractMoney(PIECE_COST_STEEL * amount);
        for (int i = 0; i < amount; i++) {
            Steel steel1;
            steel.push_back(steel1);
        }
    }
}

void Storage::buyCastIron(int amount, CarPartsPlant& carPartsPlant) {
    if (carPartsPlant.getMoney() > PIECE_COST_CAST_IRON * amount) {
        carPartsPlant.subtractMoney(PIECE_COST_CAST_IRON * amount);
        for (int i = 0; i < amount; i++) {
            CastIron castIron1;
            castIron.push_back(castIron1);
        }
    }
}

double Storage::averageSteelQuality() {
    double meanSum = 0;
    for (auto piece : steel)
        meanSum += piece.getQuality();
    if (steel.size() > 0)
        return meanSum / steel.size();
    else return 0;
}

double Storage::averageCastIronQuality() {
    double meanSum = 0;
    for (auto piece : castIron)
        meanSum += piece.getQuality();
    if (castIron.size() > 0)
        return meanSum / castIron.size();
    else return 0;
}

double Storage::averageAluminumQuality() {
    double meanSum = 0;
    for (auto piece : aluminum)
        meanSum += piece.getQuality();
    if (aluminum.size() > 0)
        return meanSum / aluminum.size();
    else return 0;
}

EngineDetail Storage::getLastEngineDetail() {
    return engineDetail.back();
}

TransmissionDetail Storage::getLastTransmissionDetail() {
    return transmissionDetail.back();
}

ChassisDetail Storage::getLastChassisDetail() {
    return chassisDetail.back();
}

void Storage::removeEngineDetail() {
    engineDetail.pop_back();
}
void Storage::removeTransmissionDetail() {
    transmissionDetail.pop_back();
}
void Storage::removeChassisDetail() {
    chassisDetail.pop_back();
}

bool Storage::hasEngineDetail() {
    return !engineDetail.empty();
}
bool Storage::hasTransmissionDetail() {
    return !transmissionDetail.empty();
}
bool Storage::hasChassisDetail() {
    return !chassisDetail.empty();
}

void Storage::addEngineDetail(double coefficient) {
    EngineDetail engineDetail1(coefficient, averageSteelQuality(), averageCastIronQuality());
    engineDetail.push_back(engineDetail1);
}
void Storage::addTransmissionDetail(double coefficient) {
    TransmissionDetail transmissionDetail1(coefficient, averageSteelQuality(), averageCastIronQuality(), averageAluminumQuality());
    transmissionDetail.push_back(transmissionDetail1);
}
void Storage::addChassisDetail(double coefficient) {
    ChassisDetail chassisDetail1(coefficient, averageSteelQuality(), averageCastIronQuality(), averageAluminumQuality());
    chassisDetail.push_back(chassisDetail1);
}



int Storage::amountSteel() {
    return steel.size();
}
int Storage::amountCastIron() {
    return castIron.size();
}
int Storage::amountAluminum() {
    return aluminum.size();
}

void Storage::removeSteel(int amount) {
    cutVector(steel, amount);
}
void Storage::removeCastIron(int amount) {
    cutVector(castIron, amount);
}
void Storage::removeAluminum(int amount) {
    cutVector(aluminum, amount);
}