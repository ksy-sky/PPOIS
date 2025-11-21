#pragma once
#include <string>
#include <vector>
using namespace std;

class MoodAnalyzer {
public:
    MoodAnalyzer();
    string detectMood(const string& input);
    vector<string> suggestByMood(const string& mood);
    void analyzePatterns(const string& userId);

private:
    vector<string> moodTypes; 
    vector<string> trackAnalysis; 
    vector<string> patterns; 
    double accuracy; 
    vector<string> userFeedback; 
    bool adaptation; 
    vector<string> correlation; 
};