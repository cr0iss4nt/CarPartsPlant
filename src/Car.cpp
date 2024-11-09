#include "Car.hpp"
#include "randomPercent.hpp"

Car::Car(double engineQuality, double transmissionQuality, double chassisQuality) {
    this->quality = randomPercent() * engineQuality * transmissionQuality * chassisQuality;
}