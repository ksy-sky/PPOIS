#pragma once
#include <string>
#include <vector>
class CookingTask;
class Chef;

class KitchenStation {
public:
    KitchenStation(int uniqueStationId, const std::string& nameOfStation,
         const std::string& initialStatus, int capacityLimit, Chef* chefInCharge);
    void assignTask(CookingTask* taskToAssign);
    void completeTask(CookingTask* taskToComplete);
    int getCurrentLoad() const;
    void setStatus(const std::string& newStatus);
    const std::string& getName() const;
private:
    int stationId;
    std::string stationName;
    std::string stationStatus; 
    int maximumCapacity;
    std::vector<CookingTask*> assignedTasks;
    Chef* responsibleChef;
};
