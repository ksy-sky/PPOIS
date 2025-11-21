#pragma once
#include <string>
#include <vector>
class CookingTask;
class Chef;

class KitchenSchedule {
public:
    KitchenSchedule(int uniqueScheduleId, const std::string& dateOfSchedule);
    void addTask(CookingTask* taskToAdd);
    std::vector<CookingTask*> getTasksForChef(Chef* chefReference) const;
    void printSchedule() const;
private:
    int scheduleId;
    std::string scheduleDate;
    std::vector<CookingTask*> scheduledTasks;
    std::vector<Chef*> assignedChefs;
};
