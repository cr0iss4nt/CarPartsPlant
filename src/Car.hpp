#pragma once
#include "Transport.hpp"
class Car: public Transport {
    private:
        double quality;
    public:
        Car(double engineQuality, double transmissionQuality, double chassisQuality);
};