#include "User.h"
#include<iostream>

User::User(const string& username, const string& password, const string& name, const string& email, const PrivacySettings& settings)
    : username(username), password(password), profile(name, email, settings) {}

string User::getUsername() const {
    return username; 
}
bool User::authenticate(const string& password) const {
    return this->password == password;
}

void User::addAchievement(const UserAchievement& achievement) {
    achievements.push_back(achievement);
}
vector<UserAchievement> User::getAchievements() const {
    return achievements;
}
void User::addFriend(const string& friendUsername) {
    friendSystem.addFriend(friendUsername);
}
void User::removeFriend(const string& friendUsername) {
    friendSystem.removeFriend(friendUsername);
}
vector<string> User::getFriends() const {
    return friendSystem.getFriends(); 
}
void User::addDownload(const string& track) {
    downloadedTracks.push_back(track);
    cout << "Track " << track << " added to user " << username << "'s downloads." << endl;
}
void User::listDownloads() const {
    cout << "Downloads for user " << username << ":" << endl;
    for (const auto& track : downloadedTracks) {
        cout << "- " << track << endl;
    }
}
