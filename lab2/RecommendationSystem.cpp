#include "RecommendationSystem.h"
#include <iostream>

RecommendationSystem::RecommendationSystem(const User& user)
    : user(user), accuracy(0.0f) {}  

void RecommendationSystem::generateRecommendations(const string& userId) {
    cout << "Generating recommendations for user: " << userId << endl;
}
void RecommendationSystem::updateAlgorithm() {
    cout << "Updating recommendation algorithm." << endl;
}
void RecommendationSystem::measureAccuracy() {
    cout << "Measuring accuracy of recommendations." << endl;
}