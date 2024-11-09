#include "Motorbike.hpp"
#include "randomPercent.hpp"

Motorbike::Motorbike(double engineQuality, double transmissionQuality, double chassisQuality) {
    this->quality = randomPercent() * engineQuality * transmissionQuality * chassisQuality;
}