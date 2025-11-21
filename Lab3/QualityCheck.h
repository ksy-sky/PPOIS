#pragma once
#include <string>
#include "Delivery.h"

class QualityCheck {
public:
    QualityCheck(int uniqueId, Delivery* delivery, const std::string& date);
    int getId() const;
    const std::string& getResult() const;
    void markAsPassed();
    void markAsFailed(const std::string& reason);
private:
    int checkId;
    Delivery* deliveryReference;
    std::string checkDate;
    std::string checkResult; 
};
