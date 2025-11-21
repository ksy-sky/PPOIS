#include "KitchenStation.h"
#include "CookingTask.h"
#include "Chef.h"
#include <algorithm>
KitchenStation::KitchenStation(int uniqueStationId, const std::string& nameOfStation,
                               const std::string& initialStatus, int capacityLimit, Chef* chefInCharge)
    : stationId(uniqueStationId), stationName(nameOfStation),
      stationStatus(initialStatus), maximumCapacity(capacityLimit), responsibleChef(chefInCharge) {}

void KitchenStation::assignTask(CookingTask* taskToAssign) {
    if (assignedTasks.size() < static_cast<size_t>(maximumCapacity)) {
        assignedTasks.push_back(taskToAssign);
    }
}
void KitchenStation::completeTask(CookingTask* taskToComplete) {
    assignedTasks.erase(
        std::remove(assignedTasks.begin(), assignedTasks.end(), taskToComplete),
        assignedTasks.end());
}
int KitchenStation::getCurrentLoad() const { return static_cast<int>(assignedTasks.size()); }
void KitchenStation::setStatus(const std::string& newStatus) { stationStatus = newStatus;}
const std::string& KitchenStation::getName() const { return stationName;}
