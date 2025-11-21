#include "KitchenSchedule.h"
#include "CookingTask.h"
#include "Chef.h"
#include <iostream>

KitchenSchedule::KitchenSchedule(int uniqueScheduleId, const std::string& dateOfSchedule)
    : scheduleId(uniqueScheduleId), scheduleDate(dateOfSchedule) {}
void KitchenSchedule::addTask(CookingTask* taskToAdd) { scheduledTasks.push_back(taskToAdd); }
std::vector<CookingTask*> KitchenSchedule::getTasksForChef(Chef* chefReference) const {
    std::vector<CookingTask*> tasksForChef;
    for (auto* task : scheduledTasks) {
        if (task->getStatus() == "Assigned" || task->getStatus() == "InProgress") {
            tasksForChef.push_back(task);
        }
    }
    return tasksForChef;
}
void KitchenSchedule::printSchedule() const {
    std::cout << "Kitchen Schedule for " << scheduleDate << " contains "
              << scheduledTasks.size() << " tasks." << std::endl;
}
