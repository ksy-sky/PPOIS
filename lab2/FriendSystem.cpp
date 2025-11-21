#include "FriendSystem.h"
#include <algorithm>
using namespace std;

void FriendSystem::addFriend(const string& username) {
    friendUsernames.push_back(username); 
}
void FriendSystem::removeFriend(const string& username) {
    friendUsernames.erase(
        remove(friendUsernames.begin(), friendUsernames.end(), username),
        friendUsernames.end()
    );
}
vector<string> FriendSystem::getFriends() const {
    return friendUsernames; 
}