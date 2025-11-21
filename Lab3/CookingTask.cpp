#include "CookingTask.h"

CookingTask::CookingTask(int uniqueTaskId, Recipe* recipeReference, Chef* chefAssigned, KitchenStation* stationAssigned)
    : taskId(uniqueTaskId), linkedRecipe(recipeReference), assignedChef(chefAssigned), assignedStation(stationAssigned),
      taskStatus("Assigned"), startTime(""), endTime("") {}
void CookingTask::startTask(const std::string& startTimestamp) {
    taskStatus = "InProgress";
    startTime = startTimestamp;
}
void CookingTask::finishTask(const std::string& endTimestamp) {
    taskStatus = "Completed";
    endTime = endTimestamp;
}
void CookingTask::reassignChef(Chef* newChef) { assignedChef = newChef; }
void CookingTask::reassignStation(KitchenStation* newStation) { assignedStation = newStation; }
const std::string& CookingTask::getStatus() const { return taskStatus; }
int CookingTask::getTaskId() const { return taskId; }
const std::string& CookingTask::getStartTime() const { return startTime; }
const std::string& CookingTask::getEndTime() const { return endTime; }
Chef* CookingTask::getAssignedChef() const { return assignedChef; }
KitchenStation* CookingTask::getAssignedStation() const { return assignedStation; }
Recipe* CookingTask::getLinkedRecipe() const { return linkedRecipe; }