#include "Invoice.h"
#include "PaymentSource.h"

Invoice::Invoice(const std::string& id, double amount, PaymentSource* source)
    : invoiceId(id), amount(amount), status("Pending"), source(source) {}
    
bool Invoice::isReady() const {
    return source && source->getBalance() >= amount && source->isValid();
}
bool Invoice::pay() {
    if (!source) return false;
    if (isReady() && source->charge(amount)) {
        markPaid();
        return true;
    }
    return false;
}
void Invoice::markPaid() { status = "Paid"; }
void Invoice::markCancelled() { status = "Cancelled"; }
const std::string& Invoice::getId() const { return invoiceId; }
double Invoice::getAmount() const { return amount; }
const std::string& Invoice::getStatus() const { return status; }
PaymentSource* Invoice::getSource() const { return source; }
