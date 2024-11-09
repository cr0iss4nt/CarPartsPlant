#pragma once
#include <vector>
#include "Steel.hpp"
#include "CastIron.hpp"
#include "Aluminum.hpp"
#include "EngineDetail.hpp"
#include "TransmissionDetail.hpp"
#include "ChassisDetail.hpp"
#include "CarPartsPlant.hpp"
class Storage {
    protected:
        std::vector<Steel> steel;
        std::vector<CastIron> castIron;
        std::vector<Aluminum> aluminum;
        std::vector<EngineDetail> engineDetail;
        std::vector<TransmissionDetail> transmissionDetail;
        std::vector<ChassisDetail> chassisDetail;
    public:
        void buySteel(int amount, CarPartsPlant& carPartsPlant);
        void buyCastIron(int amount, CarPartsPlant& carPartsPlant);
        void buyAluminum(int amount, CarPartsPlant& carPartsPlant);


        double averageSteelQuality();
        double averageCastIronQuality();
        double averageAluminumQuality();
        
        EngineDetail getLastEngineDetail();
        TransmissionDetail getLastTransmissionDetail();
        ChassisDetail getLastChassisDetail();

        void removeEngineDetail();
        void removeTransmissionDetail();
        void removeChassisDetail();
        
        bool hasEngineDetail();
        bool hasTransmissionDetail();
        bool hasChassisDetail();
        
        void addEngineDetail(double coefficient);
        void addTransmissionDetail(double coefficient);
        void addChassisDetail(double coefficient);

        int amountSteel();
        int amountCastIron();
        int amountAluminum();

        void removeSteel(int amount);
        void removeCastIron(int amount);
        void removeAluminum(int amount);
        
};

