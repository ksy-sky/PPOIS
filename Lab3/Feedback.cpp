#include "Feedback.h"
#include <iostream>

Feedback::Feedback(std::string id, User* user, std::string message)
    : feedbackId(id), client(user), text(message) {}
void Feedback::submit() {
    std::cout << "Feedback submitted: " << text << "\n";
}
