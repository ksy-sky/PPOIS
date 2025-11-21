#pragma once
#include <string>

class Supplier {
public:
    Supplier(const std::string& id, const std::string& name, const std::string& contact);
    const std::string& getId() const;
    const std::string& getName() const;
    const std::string& getContact() const;
    std::string getInfo() const;
private:
    std::string supplierId;
    std::string name;
    std::string contact;
};
