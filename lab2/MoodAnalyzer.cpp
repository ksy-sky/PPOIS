#include "MoodAnalyzer.h"
#include <iostream>

MoodAnalyzer::MoodAnalyzer() : accuracy(0.0f), adaptation(false) {
    moodTypes = {"happy", "sad", "excited", "angry", "relaxed"};
}
string MoodAnalyzer::detectMood(const string& input) {
    cout << "Analyzing input for mood detection." << endl;
    return moodTypes[rand() % moodTypes.size()]; 
}
vector<string> MoodAnalyzer::suggestByMood(const string& mood) {
    cout << "Suggesting music for mood: " << mood << endl;
    vector<string> suggestions;
    suggestions.push_back("Song 1 for " + mood);
    suggestions.push_back("Song 2 for " + mood);
    return suggestions;
}
void MoodAnalyzer::analyzePatterns(const string& userId) {
    cout << "Analyzing mood patterns for user: " << userId << endl;
}