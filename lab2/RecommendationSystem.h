#pragma once
#include <vector>
#include <string>
#include "User.h"
using namespace std;

class RecommendationSystem {
public:
    RecommendationSystem(const User& user);
    void generateRecommendations(const string& userId);
    void updateAlgorithm();
    void measureAccuracy();
private:
    User user;
    vector<string> algorithms; 
    vector<string> userData;
    vector<string> history;
    double accuracy;
    vector<string> filters;
    vector<string> trends;
    vector<string> personalization;
    vector<string> testing;
    vector<string> optimization;
};