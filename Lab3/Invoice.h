#pragma once
#include <string>
class PaymentSource;

class Invoice {
public:
    Invoice(const std::string& id, double amount, PaymentSource* source);
    bool isReady() const;     
    bool pay();             
    void markPaid();
    void markCancelled();
    const std::string& getId() const;
    double getAmount() const;
    const std::string& getStatus() const;
    PaymentSource* getSource() const;
private:
    std::string invoiceId;
    double amount;
    std::string status;  
    PaymentSource* source;
};
