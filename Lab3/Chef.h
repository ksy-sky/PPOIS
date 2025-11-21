#pragma once
#include "Employee.h"
#include <iostream>

class Chef : public Employee {
public:
    Chef(User* account, double salary, int experience);
    void prepareDish();
    int getDishesPrepared() const;
private:
    int dishesPrepared;
};
