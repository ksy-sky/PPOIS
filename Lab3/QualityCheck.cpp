#include "QualityCheck.h"

QualityCheck::QualityCheck(int uniqueId, Delivery* delivery, const std::string& date)
    : checkId(uniqueId), deliveryReference(delivery), checkDate(date), checkResult("Pending") {}

int QualityCheck::getId() const { return checkId; }
const std::string& QualityCheck::getResult() const { return checkResult; }
void QualityCheck::markAsPassed() { checkResult = "Passed"; }
void QualityCheck::markAsFailed(const std::string& reason) { checkResult = "Failed: " + reason; }
