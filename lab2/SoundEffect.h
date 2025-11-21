#pragma once
#include <string>
#include <vector>
using namespace std;

class SoundEffect {
public:
    SoundEffect(const string& name, const string& category, double duration, const string& format,
                const string& application, const string& author, double price,
                const vector<string>& tags, const vector<double>& parameters, const string& usageRights);
    void preview() const ;
    void applyToAudio() const ;
    void categorize() const;
private:
    string name; 
    string category;
    double duration;
    string format;
    string application;
    string author;
    double price;
    vector<string> tags;
    vector<double> parameters;
    string usageRights;
};