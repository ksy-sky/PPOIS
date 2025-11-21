#pragma once
#include <string>

class PaymentSource {
public:
    PaymentSource(const std::string& id, const std::string& type, const std::string& owner, 
        const std::string& expiry, double balance, const std::string& currency, double limit);
    bool isValid() const;
    bool charge(double amount);
    void refund(double amount);
    bool acceptCash(double amount);
    bool withinLimit(double amount) const; 
    const std::string& getType() const;
    const std::string& getId() const;
    const std::string& getOwner() const;
    const std::string& getExpiry() const;
    const std::string& getCurrency() const;
    double getBalance() const;
    double getLimit() const;
private:
    std::string id;
    std::string type; 
    std::string owner;
    std::string expiry;
    double balance; 
    std::string currency; 
    double limit; 
};
