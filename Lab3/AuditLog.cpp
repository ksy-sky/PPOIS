#include "AuditLog.h"

AuditLog::AuditLog(int uniqueId)
    : logId(uniqueId) {}

int AuditLog::getId() const { return logId; }
void AuditLog::addEntry(const std::string& entry) { logEntries.push_back(entry); }
const std::vector<std::string>& AuditLog::getEntries() const { return logEntries; }
