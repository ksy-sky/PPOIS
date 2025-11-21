#pragma once
#include <vector>
#include <string>
using namespace std;
class FriendSystem {
public:
    FriendSystem() = default;
    void addFriend(const string& username);
    void removeFriend(const string& username);
    vector<string> getFriends() const;
private:
    vector<string> friendUsernames;
};

