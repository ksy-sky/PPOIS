#pragma once
#include "Employee.h"
#include <iostream>

class Waiter : public Employee {
public:
    Waiter(User* account, double salary, int experience);
    void takeOrder();
    void serveTable();
    int getTablesServed() const;
private:
    int tablesServed;
};