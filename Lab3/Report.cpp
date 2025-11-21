#include "Report.h"

Report::Report(std::string id)
    : reportId(id), averageSales(0), expenses(0), income(0) {}

void Report::addDaySale(double amount) { dailySales.push_back(amount); }
double Report::calculateAverage() {
    if (dailySales.empty()) return 0;
    double sum = 0;
    for (double sale : dailySales) {
        sum += sale;
    }
    averageSales = sum / dailySales.size();
    return averageSales;
}
void Report::setExpenses(double value) { expenses = value; }
void Report::setIncome(double value) { income = value; }
double Report::calculateProfit() const { return income - expenses; }
const std::string& Report::getId() const { return reportId; }
const std::vector<double>& Report::getDailySales() const { return dailySales; }
double Report::getExpenses() const { return expenses; }
double Report::getIncome() const { return income; }
