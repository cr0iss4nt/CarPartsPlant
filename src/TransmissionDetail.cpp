#include "TransmissionDetail.hpp"
#include "randomPercent.hpp"

TransmissionDetail::TransmissionDetail(double coefficient, double steelQuality, double castIronQuality, double aluminumQuality) {
    this->quality = randomPercent() * coefficient * steelQuality * castIronQuality * aluminumQuality;
}

double TransmissionDetail::getQuality() {
    return quality;
}