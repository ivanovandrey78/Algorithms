#include "complex.h"
#include "math_functions.h"

#include <sstream>

namespace mymath {

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(
        real * other.real - imag * other.imag,
        real * other.real + imag * other.imag
    );
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    if (denominator == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Complex(
        (real * other.real + imag * other.imag) / denominator,
        (imag * other.real - real * other.imag) / denominator
    );
}

double Complex::magnitude() const {
    return sqrt(real * real + imag * imag);
}

std::string Complex::to_string() const {
    std::ostringstream oss;
    oss << real << (imag >= 0 ? " + " : " - ") << std::abs(imag) << "i";
    return oss.str();
}

} // namespace mymath