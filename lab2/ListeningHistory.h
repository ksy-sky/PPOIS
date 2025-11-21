#pragma once
#include <iostream>
#include <vector>
#include "Song.h"
using namespace std;
class ListeningHistory {
public:
    ListeningHistory() = default;
    void addSong(const Song& song);
    void clearHistory();
    vector<Song> getHistory() const;
private:
    vector<Song> songs;
};

