#include "Employee.h"

Employee::Employee(User* account, std::string position, double salary, int experience)
    : linkedAccount(account), employeePosition(position), salary(salary), yearsOfExperience(experience) {}

bool Employee::canDo(const std::string& action) const {
    return linkedAccount ? linkedAccount->canDo(action) : false;
}
const std::string& Employee::getPosition() const { return employeePosition; }
double Employee::getSalary() const { return salary; }
int Employee::getExperience() const { return yearsOfExperience; }
void Employee::setSalary(double newSalary) { salary = newSalary; }
