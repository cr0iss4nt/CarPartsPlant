#include "EngineDetail.hpp"
#include "randomPercent.hpp"

EngineDetail::EngineDetail(double coefficient, double steelQuality, double castIronQuality) {
    this->quality = randomPercent() * coefficient * steelQuality * castIronQuality;
}

double EngineDetail::getQuality() {
    return quality;
}