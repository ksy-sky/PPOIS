#pragma once
#include <iostream>
#include <string>
using namespace std;
class UserAchievement {
public:
    UserAchievement(const string& name, const string& date);
    string getDetails() const;
private:
    string achievementName;
    string dateObtained;
};