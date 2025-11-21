#include "PlaylistGenerator.h"
#include <iostream>

PlaylistGenerator::PlaylistGenerator() : duration(0) {}

vector<string> PlaylistGenerator::generatePlaylist(const vector<string>& tracks) {
    vector<string> playlist;
    cout << "Generating playlist from provided tracks." << endl;
    for (const auto& track : tracks) {
        playlist.push_back(track);
    }
    return playlist;
}

void PlaylistGenerator::customizeRules(const vector<string>& rules) {
    this->rules = rules; 
    cout << "Customized playlist rules." << endl;
}

void PlaylistGenerator::optimizeSequence() {
    cout << "Optimizing track sequence in the playlist." << endl;
}