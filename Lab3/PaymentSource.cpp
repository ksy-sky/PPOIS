#include "PaymentSource.h"

PaymentSource::PaymentSource(const std::string& id, const std::string& type, const std::string& owner,
                             const std::string& expiry,double balance, const std::string& currency, double limit)
    : id(id), type(type), owner(owner), expiry(expiry), balance(balance), currency(currency), limit(limit) {}

bool PaymentSource::isValid() const {
    if (type == "Cash") return balance >= 0;
    if (type == "Wallet") return balance >= 0;
    if (type == "Card") return !expiry.empty() && balance >= 0;
    return false;
}
bool PaymentSource::charge(double amount) {
    if (type == "Cash") return false; 
    if (amount <= 0) return false;
    if (balance >= amount && withinLimit(amount)) {
        balance -= amount;
        return true;
    }
    return false;
}
void PaymentSource::refund(double amount) { if (amount > 0) balance += amount; }
bool PaymentSource::acceptCash(double amount) {
    if (type == "Cash" && amount > 0) {
        balance += amount;
        return true;
    }
    return false;
}
bool PaymentSource::withinLimit(double amount) const {
    if (type == "Card") return amount <= limit;
    return true; 
}
const std::string& PaymentSource::getType() const { return type; }
const std::string& PaymentSource::getId() const { return id; }
const std::string& PaymentSource::getOwner() const { return owner; }
const std::string& PaymentSource::getExpiry() const { return expiry; }
const std::string& PaymentSource::getCurrency() const { return currency; }
double PaymentSource::getBalance() const { return balance; }
double PaymentSource::getLimit() const { return limit; }
