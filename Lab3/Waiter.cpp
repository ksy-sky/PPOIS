#include "Waiter.h"

Waiter::Waiter(User* account, double salary, int experience)
    : Employee(account, "Waiter", salary, experience), tablesServed(0) {}

void Waiter::takeOrder() {
    if (canDo("take_order")) {
        std::cout << "Официант принял заказ.\n";
        tablesServed++;
    } else {
        std::cout << "Нет прав на принятие заказа!\n";
    }
}

void Waiter::serveTable() {
    if (canDo("serve_table"))
        std::cout << "Официант обслуживает столик.\n";
    else
        std::cout << "Нет прав на обслуживание столика!\n";
}

int Waiter::getTablesServed() const { return tablesServed; }
