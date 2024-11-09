#pragma once
#include <vector>
#include "Steel.hpp"
#include "CastIron.hpp"
#include "Aluminum.hpp"
class CarPartsPlant {
    private:
        double money;
    public:
        void addMoney(double amount);
        void subtractMoney(double amount);
        CarPartsPlant();
        double getMoney();
};