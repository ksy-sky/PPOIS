#include "ReportService.h"

std::string ReportService::generateWeeklyReport(Report& report) {
    std::string result = "Weekly Report [" + report.getId() + "]\n";
    result += "Days: " + std::to_string(report.getDailySales().size()) + "\n";
    result += "Average Sales: " + std::to_string(report.calculateAverage()) + "\n";
    result += "Profit: " + std::to_string(report.calculateProfit()) + "\n";
    return result;
}

std::string ReportService::generateFinancialReport(Report& report) {
    std::string result = "Financial Report [" + report.getId() + "]\n";
    result += "Income: " + std::to_string(report.getIncome()) + "\n";
    result += "Expenses: " + std::to_string(report.getExpenses()) + "\n";
    result += "Profit: " + std::to_string(report.calculateProfit()) + "\n";
    return result;
}

std::string ReportService::generateSalesReport(Report& report) {
    std::string result = "Sales Report [" + report.getId() + "]\n";
    result += "Days: " + std::to_string(report.getDailySales().size()) + "\n";
    result += "Average Sales: " + std::to_string(report.calculateAverage()) + "\n";
    return result;
}

std::string ReportService::generateSummaryReport(Report& report) {
    std::string result = "Summary Report [" + report.getId() + "]\n";
    result += "Average Sales: " + std::to_string(report.calculateAverage()) + "\n";
    result += "Profit: " + std::to_string(report.calculateProfit()) + "\n";
    return result;
}
