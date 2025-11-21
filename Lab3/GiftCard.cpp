#include "GiftCard.h"

GiftCard::GiftCard(std::string code, double initialBalance)
    : cardCode(code), balance(initialBalance), isActive(true) {}

bool GiftCard::redeem(double amount) {
    if (isActive && balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}
void GiftCard::deactivate() { isActive = false; }
const std::string& GiftCard::getCode() const { return cardCode; }
double GiftCard::getBalance() const { return balance; }
bool GiftCard::getStatus() const { return isActive; }
