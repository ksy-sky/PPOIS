#pragma once
#include <string>
class Recipe;
class Chef;
class KitchenStation;

class CookingTask {
public:
    CookingTask(int uniqueTaskId, Recipe* recipeReference, Chef* chefAssigned, KitchenStation* stationAssigned);
    void startTask(const std::string& startTimestamp);
    void finishTask(const std::string& endTimestamp);
    void reassignChef(Chef* newChef);
    void reassignStation(KitchenStation* newStation);
    const std::string& getStatus() const;
    int getTaskId() const;
    const std::string& getStartTime() const;
    const std::string& getEndTime() const;
    Chef* getAssignedChef() const;
    KitchenStation* getAssignedStation() const;
    Recipe* getLinkedRecipe() const;
private:
    int taskId;
    Recipe* linkedRecipe;
    Chef* assignedChef;
    KitchenStation* assignedStation;
    std::string taskStatus; 
    std::string startTime;
    std::string endTime;
};