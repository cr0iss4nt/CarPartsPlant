#pragma once
#include "Detail.hpp"
class EngineDetail: public Detail {
    public:
        EngineDetail(double coefficient, double steelQuality, double castIronQuality);
        virtual double getQuality() override;
};