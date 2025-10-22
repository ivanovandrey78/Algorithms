#include "complex.h"
#include "math_functions.h"

#include <sstream>

namespace math {

// Construct.
// With real and imaginary value.
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Arithmetics functions.
// Compound operators.
Complex& Complex::operator+=(const Complex& other) {
    real += other.real;
    imag += other.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    real -= other.real;
    imag -= other.imag;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    double new_real = real * other.real - imag * other.imag;
    double new_imag = real * other.imag + imag * other.real;
    real = new_real;
    imag = new_imag;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    double denominator = other.real * other.real + other.imag * other.imag;
    if (denominator == 0) throw std::runtime_error("Complex division by zero");
    
    double new_real = (real * other.real + imag * other.imag) / denominator;
    double new_imag = (imag * other.real - real * other.imag) / denominator; 
    real = new_real;
    imag = new_imag;
    return *this;
}

//Unary operators.
Complex Complex::operator-() const {
    return Complex(-real,-imag);
}

//Binary operators.
Complex operator+(const Complex& lhs,const Complex& rhs) {
    Complex result = lhs;
    result += rhs;
    return result;
}

Complex operator-(const Complex& lhs,const Complex& rhs) {
    Complex result = lhs;
    result -= rhs;
    return result;
}

Complex operator*(const Complex& lhs,const Complex& rhs) {
    Complex result = lhs;
    result *= rhs;
    return result;
}

Complex operator/(const Complex& lhs,const Complex& rhs) {
    Complex result = lhs;
    result /= rhs;
    return result;
}

// Compare operations.
bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const {
    return *this == other;
}


} // namespace math