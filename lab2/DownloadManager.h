#pragma once
#include <string>
#include <vector>
#include "User.h"
#include "Song.h"
using namespace std;

class DownloadManager {
public:
    DownloadManager(User* user);
    void downloadTrack(const Song& song);
    void pause();
    void resume();
    bool checkLimit() const;
private:
    User* user; 
    vector<Song> downloadQueue;
    double progress;  
    double speed;
    double limit;
    vector<string> history;  
};