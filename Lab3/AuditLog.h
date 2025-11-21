#pragma once
#include <string>
#include <vector>

class AuditLog {
public:
    AuditLog(int uniqueId);
    int getId() const;
    void addEntry(const std::string& entry);
    const std::vector<std::string>& getEntries() const;
private:
    int logId;
    std::vector<std::string> logEntries;
};
