#include "Permission.h"

Permission::Permission(std::string key, std::string description, int priority) : permissionKey(key), permissionDescription(description), priorityLevel(priority) {}
const std::string& Permission::getKey() const { return permissionKey; }
const std::string& Permission::getDescription() const { return permissionDescription; }
int Permission::getPriorityLevel() const { return priorityLevel; }
