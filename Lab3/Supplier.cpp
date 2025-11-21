#include "Supplier.h"

Supplier::Supplier(const std::string& id, const std::string& name, const std::string& contact)
    : supplierId(id), name(name), contact(contact) {}

const std::string& Supplier::getId() const { return supplierId; }
const std::string& Supplier::getName() const { return name; }
const std::string& Supplier::getContact() const { return contact; }
std::string Supplier::getInfo() const {
    return "Supplier " + name + " (" + supplierId + "), contact: " + contact;
}
