#include "CarPartsPlant.hpp"
#include "randomPercent.hpp"

CarPartsPlant::CarPartsPlant() : money(pow(10,6) * randomPercent()) {
}

double CarPartsPlant::getMoney() {
    return money;
}

void CarPartsPlant::addMoney(double amount) {
    money += amount;
}

void CarPartsPlant::subtractMoney(double amount) {
    money -= amount;
}