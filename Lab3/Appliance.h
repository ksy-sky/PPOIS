#pragma once
#include <string>
#include "KitchenStation.h"

class Appliance {
public:
    Appliance(int uniqueApplianceId, const std::string& nameOfAppliance, const std::string& initialStatus,
         int capacityValue, KitchenStation* stationReference);
    void startAppliance();
    void stopAppliance();
    void performMaintenance();
    const std::string& getName() const;
    const std::string& getStatus() const;
private:
    int applianceId;
    std::string applianceName;
    std::string applianceStatus; 
    int capacityLevel;
    KitchenStation* assignedStation;
};
