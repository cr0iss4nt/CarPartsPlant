#include "CarPartsPlant.hpp"
#include "Furnace.hpp"
#include "randomPercent.hpp"
#include "cutVector.hpp"


const int REQUIRED_STEEL_ENGINE_DETAIL = 3;
const int REQUIRED_CAST_IRON_ENGINE_DETAIL = 7;

const int REQUIRED_STEEL_TRANSMISSION_DETAIL = 5;
const int REQUIRED_CAST_IRON_TRANSMISSION_DETAIL = 2;
const int REQUIRED_ALUMINUM_TRANSMISSION_DETAIL = 3;

const int REQUIRED_STEEL_CHASSIS_DETAIL = 3;
const int REQUIRED_CAST_IRON_CHASSIS_DETAIL = 1;
const int REQUIRED_ALUMINUM_CHASSIS_DETAIL = 6;

Furnace::Furnace() {
    performance = randomPercent();
}
double Furnace::getPerformance() {
    return performance;
}

void Furnace::makeEngineDetail(int number, Storage& storage) {
    if (number > 0
    && storage.amountSteel() >= REQUIRED_STEEL_ENGINE_DETAIL * number
    && storage.amountCastIron() >= REQUIRED_CAST_IRON_ENGINE_DETAIL * number)
        for (int i = 0; i < number; i++) {
            storage.addEngineDetail(performance);
            storage.removeSteel(REQUIRED_STEEL_ENGINE_DETAIL);
            storage.removeCastIron(REQUIRED_CAST_IRON_ENGINE_DETAIL);
        }
}

void Furnace::makeTransmissionDetail(int number, Storage& storage) {
    if (number > 0
    && storage.amountSteel() >= REQUIRED_STEEL_TRANSMISSION_DETAIL * number
    && storage.amountCastIron() >= REQUIRED_CAST_IRON_TRANSMISSION_DETAIL * number
    && storage.amountAluminum() >= REQUIRED_ALUMINUM_TRANSMISSION_DETAIL * number)
        for (int i = 0; i < number; i++) {
            storage.addTransmissionDetail(performance);
            storage.removeSteel(REQUIRED_STEEL_TRANSMISSION_DETAIL);
            storage.removeCastIron(REQUIRED_CAST_IRON_TRANSMISSION_DETAIL);
            storage.removeAluminum(REQUIRED_ALUMINUM_TRANSMISSION_DETAIL);
        }
}

void Furnace::makeChassisDetail(int number, Storage& storage) {
    if (number > 0
    && storage.amountSteel() >= REQUIRED_STEEL_CHASSIS_DETAIL * number
    && storage.amountCastIron() >= REQUIRED_CAST_IRON_CHASSIS_DETAIL * number
    && storage.amountAluminum() >= REQUIRED_ALUMINUM_CHASSIS_DETAIL * number)
        for (int i = 0; i < number; i++) {
            storage.addChassisDetail(performance);
            storage.removeSteel(REQUIRED_STEEL_CHASSIS_DETAIL);
            storage.removeCastIron(REQUIRED_STEEL_CHASSIS_DETAIL);
            storage.removeAluminum(REQUIRED_ALUMINUM_CHASSIS_DETAIL);
        }
}