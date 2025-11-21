#pragma once
#include <string>
#include <vector>

class Report {
public:
    Report(std::string id);
    void addDaySale(double amount);
    double calculateAverage();
    void setExpenses(double value);
    void setIncome(double value);
    double calculateProfit() const;
    const std::string& getId() const;
    const std::vector<double>& getDailySales() const;
    double getExpenses() const;
    double getIncome() const;
private:
    std::string reportId;
    std::vector<double> dailySales;
    double averageSales;
    double expenses;
    double income;
};
