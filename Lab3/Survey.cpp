#include "Survey.h"

Survey::Survey(std::string id) : surveyId(id) {}

void Survey::addQuestion(const std::string& question) { questions.push_back(question);}
void Survey::addAnswer(const std::string& answer) { answers.push_back(answer);}
std::string Survey::summarizeResults() const {
    return "Survey [" + surveyId + "] has " + std::to_string(questions.size()) +
           " questions and " + std::to_string(answers.size()) + " answers.";
}
