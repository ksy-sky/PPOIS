#pragma once
#include <string>
#include <vector>

class Survey {
public:
    Survey(std::string id);
    void addQuestion(const std::string& question);
    void addAnswer(const std::string& answer);
    std::string summarizeResults() const;
private:
    std::string surveyId;
    std::vector<std::string> questions;
    std::vector<std::string> answers;
};
