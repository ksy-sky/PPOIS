#include "ShoppingCart.h"
#include <iostream>

ShoppingCart::ShoppingCart(User* user) : total(0), discounts(0), taxes(0), shipping(0), user(user) {}
void ShoppingCart::addDigitalItem(const DigitalPurchase& item, int quantity) {
    digitalItems.push_back(item);
    digitalQuantities.push_back(quantity);
    cout << "Added " << quantity << " of " << item.getItem() << " to the cart." << endl;
}
void ShoppingCart::addPhysicalItem(const PhysicalMediaOrder& item, int quantity) {
    physicalItems.push_back(item);
    physicalQuantities.push_back(quantity);
    cout << "Added " << quantity << " of " << item.getMedia() << " to the cart." << endl;
}
double ShoppingCart::calculateTotal() const {
    double grandTotal = 0.0f;

    for (size_t i = 0; i < digitalItems.size(); ++i) {
        grandTotal += digitalItems[i].getPrice() * digitalQuantities[i];
    }
    for (size_t i = 0; i < physicalItems.size(); ++i) {
        grandTotal += physicalItems[i].getPrice() * physicalQuantities[i];
    }
    grandTotal += shipping;
    grandTotal -= discounts; 
    grandTotal += taxes;
    
    cout << "Calculated total is: $" << grandTotal << endl;
    return grandTotal;
}
void ShoppingCart::applyDiscount(double discount) {
    discounts += discount;
}
User* ShoppingCart::getUser() const { return user; }
void ShoppingCart::setUser(User* newUser) { user = newUser; }
string ShoppingCart::getUserUsername() const {
    if (user != nullptr) {
        return user->getUsername();
    }
    return "No user";
}
void ShoppingCart::applyUserDiscounts() {
    if (user != nullptr) {
        int achievementCount = user->getAchievements().size();
        double userDiscount = achievementCount * 0.01; 
        
        if (userDiscount > 0.1) userDiscount = 0.1; 
        
        double currentTotal = calculateTotal();
        applyDiscount(currentTotal * userDiscount);
        
        cout << "Applied user discount: " << (userDiscount * 100) << "% for " << user->getUsername() << endl;
    }
}
void ShoppingCart::saveCart() {
    if (user != nullptr) {
        cout << "Cart saved for user: " << user->getUsername() << endl;
    }
}
void ShoppingCart::loadUserCart() {
    if (user != nullptr) {
        cout << "Loading saved cart for user: " << user->getUsername() << endl;
    }
}