#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "UserProfile.h"
#include "UserAchievement.h"
#include "FriendSystem.h"
using namespace std;

class User {
public:
    User(const string& username, const string& password, const string& name, const string& email, const PrivacySettings& settings);
    string getUsername() const; 
    bool authenticate(const string& password) const;
    void addAchievement(const UserAchievement& achievement);
    vector<UserAchievement> getAchievements() const;
    void addFriend(const string& friendUser);
    void removeFriend(const string& friendUser);
    vector<string> getFriends() const;
    void addDownload(const string& track);
    void listDownloads() const;
private:
    string username;
    string password;
    UserProfile profile;
    vector<UserAchievement> achievements;
    FriendSystem friendSystem;
    vector<string> downloadedTracks;
};

