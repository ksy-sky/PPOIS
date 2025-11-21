#pragma once
#include <vector>
#include "DigitalPurchase.h"
#include "PhysicalMediaOrder.h"
#include "User.h"
using namespace std;
class ShoppingCart {
public:
    ShoppingCart(User* user = nullptr);
    void addDigitalItem(const DigitalPurchase& item, int quantity);
    void addPhysicalItem(const PhysicalMediaOrder& item, int quantity);
    double calculateTotal() const;
    void applyDiscount(double discount);
    User* getUser() const;
    void setUser(User* newUser);
    string getUserUsername() const;
    void applyUserDiscounts(); 
    void saveCart();
    void loadUserCart();

private:
    vector<DigitalPurchase> digitalItems;
    vector<PhysicalMediaOrder> physicalItems;
    vector<int> digitalQuantities;
    vector<int> physicalQuantities;
    double total;
    double discounts;
    double taxes;
    double shipping;
    string paymentMethod;
    vector<DigitalPurchase> savedCarts;
    vector<string> recommendations;
    User* user;
};