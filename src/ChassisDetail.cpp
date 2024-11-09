#include "ChassisDetail.hpp"
#include "randomPercent.hpp"

ChassisDetail::ChassisDetail(double coefficient, double steelQuality, double castIronQuality, double aluminumQuality) {
    this->quality = randomPercent() * coefficient * steelQuality * castIronQuality * aluminumQuality;
}

double ChassisDetail::getQuality() {
    return quality;
}