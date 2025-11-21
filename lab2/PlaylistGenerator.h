#pragma once
#include <vector>
#include <string>
using namespace std;

class PlaylistGenerator {
public:
    PlaylistGenerator();
    vector<string> generatePlaylist(const vector<string>& tracks);
    void customizeRules(const vector<string>& rules);
    void optimizeSequence();
private:
    vector<string> templates;
    vector<string> rules; 
    vector<string> sources;
    vector<string> customization;
    vector<string> themes;
    int duration;
    vector<string> variety;
    vector<string> sequencing; 
};