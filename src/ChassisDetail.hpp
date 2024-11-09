#pragma once
#include "Detail.hpp"
class ChassisDetail: public Detail {
    public:
        ChassisDetail(double coefficient, double steelQuality, double castIronQuality, double aluminumQuality);
        virtual double getQuality() override;
};