#pragma once
#include <string>
class User; 

class Feedback {
public:
    Feedback(std::string id, User* user, std::string message);
    void submit();
private:
    std::string feedbackId;
    User* client;
    std::string text;
};
