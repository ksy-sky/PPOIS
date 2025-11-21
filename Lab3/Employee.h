#pragma once
#include "User.h"

class Employee {
public:
    Employee(User* account, std::string position, double salary, int experience);
    bool canDo(const std::string& action) const;
    const std::string& getPosition() const;
    double getSalary() const;
    int getExperience() const;
    void setSalary(double newSalary);
protected:
    User* linkedAccount;
    std::string employeePosition;
    double salary;
    int yearsOfExperience;
};
