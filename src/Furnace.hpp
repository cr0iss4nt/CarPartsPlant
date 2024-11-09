#pragma once
#include "Storage.hpp"
class Furnace {
    private:
        double performance;

    public:
        Furnace();
        double getPerformance();

        void makeEngineDetail(int number, Storage& storage);
        void makeTransmissionDetail(int number, Storage& storage);
        void makeChassisDetail(int number, Storage& storage);
};