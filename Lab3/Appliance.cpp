#include "Appliance.h"

Appliance::Appliance(int uniqueApplianceId, const std::string& nameOfAppliance, const std::string& initialStatus,
         int capacityValue, KitchenStation* stationReference)
    : applianceId(uniqueApplianceId), applianceName(nameOfAppliance), applianceStatus(initialStatus), 
    capacityLevel(capacityValue), assignedStation(stationReference) {}
void Appliance::startAppliance() { applianceStatus = "Working"; }
void Appliance::stopAppliance() { applianceStatus = "Stopped"; }
void Appliance::performMaintenance() { applianceStatus = "Maintenance"; }
const std::string& Appliance::getName() const { return applianceName; }
const std::string& Appliance::getStatus() const { return applianceStatus; }
