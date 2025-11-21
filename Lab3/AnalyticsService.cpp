#include "AnalyticsService.h"

double AnalyticsService::calculateAverageCheck(const Report& report, int buyersCount) {
    if (buyersCount == 0) return 0;
    double totalSales = 0;
    for (double sale : report.getDailySales()) totalSales += sale;
    return totalSales / buyersCount;
}
double AnalyticsService::calculateConversion(int visitors, int buyers) {
    if (visitors == 0) return 0;
    return static_cast<double>(buyers) / visitors;
}
