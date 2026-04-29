#include "fraction.h"

#include <iostream>
#include <stdexcept>
#include <utility>

namespace {

void check_not_null(const int* p1, const int* p2) {
    if (p1 == nullptr || p2 == nullptr) {
        throw std::runtime_error("can't dereference null pointers");
    }
}

}  // namespace

Fraction::Fraction() {
    std::cout << "I am in the default constructor" << std::endl;
    numer_ = new int(0);
    denom_ = new int(1);
}

Fraction::Fraction(int numerator, int denominator) {
    std::cout << "I am in the custom constructor" << std::endl;
    if (denominator == 0) {
        throw std::runtime_error("Can't divide by zero!");
    }
    numer_ = new int(numerator);
    denom_ = new int(denominator);
}

Fraction::Fraction(const Fraction& other) {
    std::cout << "I am in the copy constructor" << std::endl;
    check_not_null(other.numer_, other.denom_);
    numer_ = new int(*other.numer_);
    denom_ = new int(*other.denom_);
}

Fraction::Fraction(Fraction&& other) noexcept {
    std::cout << "I am in the move constructor" << std::endl;
    numer_ = other.numer_;
    denom_ = other.denom_;
    other.numer_ = nullptr;
    other.denom_ = nullptr;
}

Fraction& Fraction::operator=(const Fraction& other) {
    std::cout << "I am in the assignment operator (lvalue)" << std::endl;
    if (this == &other) {
        return *this;
    }
    check_not_null(other.numer_, other.denom_);
    delete numer_;
    delete denom_;
    numer_ = new int(*other.numer_);
    denom_ = new int(*other.denom_);
    return *this;
}

Fraction& Fraction::operator=(Fraction&& other) noexcept {
    std::cout << "I am in the assignment operator (rvalue)" << std::endl;
    if (this == &other) {
        return *this;
    }
    delete numer_;
    delete denom_;
    numer_ = other.numer_;
    denom_ = other.denom_;
    other.numer_ = nullptr;
    other.denom_ = nullptr;
    return *this;
}

Fraction::~Fraction() {
    std::cout << "I am in the destructor" << std::endl;
    delete numer_;
    delete denom_;
}

double Fraction::convertToDecimal() const {
    std::cout << "I am in the convertToDecimal" << std::endl;
    check_not_null(numer_, denom_);
    return static_cast<double>(*numer_) / static_cast<double>(*denom_);
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    std::cout << "I am in the plus operator" << std::endl;
    check_not_null(lhs.numer_, lhs.denom_);
    check_not_null(rhs.numer_, rhs.denom_);
    const int numer = (*lhs.numer_) * (*rhs.denom_) + (*rhs.numer_) * (*lhs.denom_);
    const int denom = (*lhs.denom_) * (*rhs.denom_);
    return Fraction(numer, denom);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    std::cout << "I am in the multiplication operator" << std::endl;
    check_not_null(lhs.numer_, lhs.denom_);
    check_not_null(rhs.numer_, rhs.denom_);
    const int numer = (*lhs.numer_) * (*rhs.numer_);
    const int denom = (*lhs.denom_) * (*rhs.denom_);
    return Fraction(numer, denom);
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    std::cout << "I am in the << operator" << std::endl;
    check_not_null(fraction.numer_, fraction.denom_);
    os << *fraction.numer_ << "/" << *fraction.denom_;
    return os;
}
