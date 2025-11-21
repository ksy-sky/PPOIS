#include "Chef.h"

Chef::Chef(User* account, double salary, int experience)
    : Employee(account, "Chef", salary, experience), dishesPrepared(0) {}
void Chef::prepareDish() {
    if (canDo("prepare_dish")) {
        std::cout << "Повар готовит блюдо.\n";
        dishesPrepared++;
    } else {
        std::cout << "Нет прав на приготовление блюда!\n";
    }
}
int Chef::getDishesPrepared() const { return dishesPrepared; }
