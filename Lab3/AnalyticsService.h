#pragma once
#include "Report.h"

class AnalyticsService {
public:
    double calculateAverageCheck(const Report& report, int buyersCount);
    double calculateConversion(int visitors, int buyers);
};
