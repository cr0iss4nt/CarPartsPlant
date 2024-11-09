#pragma once
#include "Detail.hpp"
class TransmissionDetail: public Detail {
    public:
        TransmissionDetail(double coefficient, double steelQuality, double castIronQuality, double aluminumQuality);
        virtual double getQuality() override;
};