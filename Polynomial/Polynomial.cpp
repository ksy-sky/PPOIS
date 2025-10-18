#include "Polynomial.h"
#include <cmath>
#include <stdexcept>

Polynomial::Polynomial(int degree) : coefficients(std::max(0, degree) + 1, 0.0) {}

Polynomial::Polynomial(const Polynomial& other) : coefficients(other.coefficients) {}

Polynomial::~Polynomial() {}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        coefficients = other.coefficients;
    }
    return *this;
}
bool Polynomial::operator==(const Polynomial& other) const {
    return coefficients == other.coefficients;
}

bool Polynomial::operator!=(const Polynomial& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    for (int i = poly.coefficients.size() - 1; i >= 0; --i) {
        if (poly.coefficients[i] != 0) {
            os << poly.coefficients[i] << "x^" << i << " ";
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, Polynomial& poly) {
    for (double& coeff : poly.coefficients) {
        is >> coeff;
    }
    return is;
}

double& Polynomial::operator[](int index) {
    return coefficients[index];
}

double Polynomial::operator[](int index) const {
    return coefficients[index];
}

double Polynomial::operator()(double x) const {
    double result = 0.0;
    for (int i = 0; i < coefficients.size(); ++i) {
        result += coefficients[i] * std::pow(x, i);
    }
    return result;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    int maxDegree = std::max(coefficients.size(), other.coefficients.size());
    Polynomial result(maxDegree - 1);
    for (int i = 0; i < maxDegree; ++i) {
        result[i] = (i < coefficients.size() ? coefficients[i] : 0) +
                     (i < other.coefficients.size() ? other.coefficients[i] : 0);
    }
    return result;
}

Polynomial& Polynomial::operator+=(const Polynomial& other) {
    *this = *this + other;
    return *this;
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    int maxDegree = std::max(coefficients.size(), other.coefficients.size());
    Polynomial result(maxDegree - 1);
    for (int i = 0; i < maxDegree; ++i) {
        result[i] = (i < coefficients.size() ? coefficients[i] : 0) -
                     (i < other.coefficients.size() ? other.coefficients[i] : 0);
    }
    return result;
}

Polynomial& Polynomial::operator-=(const Polynomial& other) {
    *this = *this - other;
    return *this;
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    Polynomial result(coefficients.size() + other.coefficients.size() - 1);
    for (int i = 0; i < coefficients.size(); ++i) {
        for (int j = 0; j < other.coefficients.size(); ++j) {
            result[i + j] += coefficients[i] * other.coefficients[j];
        }
    }
    return result;
}

Polynomial& Polynomial::operator*=(const Polynomial& other) {
    *this = *this * other;
    return *this;
}
int Polynomial::getDegree() const {
    for (int i = coefficients.size() - 1; i >= 0; --i) {
        if (std::abs(coefficients[i]) > EPSILON) {
            return i;
        }
    }
    return -1; 
}
Polynomial Polynomial::operator/(const Polynomial& other) const {
    if (other.coefficients.empty() || other.getDegree() == -1) {
        throw std::invalid_argument("Division by zero polynomial");
    }

    Polynomial remainder = *this;
    Polynomial quotient(0);
    
    int divisorDegree = other.getDegree();
    double divisorLeadingCoeff = other.coefficients[divisorDegree];
    
    int maxIterations = coefficients.size() + other.coefficients.size();
    int iterations = 0;
    
    while (remainder.getDegree() >= divisorDegree && iterations < maxIterations) {
        int remainderDegree = remainder.getDegree();
        double factor = remainder.coefficients[remainderDegree] / divisorLeadingCoeff;
        int degreeDiff = remainderDegree - divisorDegree;
        
        Polynomial term(degreeDiff);
        term[degreeDiff] = factor;

        quotient = quotient + term;
        remainder = remainder - term * other;
        
        iterations++;
    }

    return quotient;
}

Polynomial& Polynomial::operator/=(const Polynomial& other) {
    *this = *this / other;
    return *this;
}
