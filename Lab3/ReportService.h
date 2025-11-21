#pragma once
#include "Report.h"
#include <string>

class ReportService {
public:
    std::string generateWeeklyReport(Report& report);
    std::string generateFinancialReport(Report& report);
    std::string generateSalesReport(Report& report);
    std::string generateSummaryReport(Report& report);
};
