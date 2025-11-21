#include "UserAchievement.h"
#include <iostream>

UserAchievement::UserAchievement(const string& name, const string& date)
    : achievementName(name), dateObtained(date) {}

string UserAchievement::getDetails() const {
    return achievementName + " obtained on " + dateObtained;
}