#include "complex.h"
#include "math_functions.h"

#include <sstream>

namespace math {

// Construct.
// Default. 
Complex::Complex() : real(0.0), imag(0.0) {}

// With real value.
Complex::Complex(double r) : real(r), imag(0.0) {}

// With real and imaginary value.
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Getters.
double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }

// Setters. 
void Complex::setReal(double r) { real = r; }
void Complex::setImag(double i) { imag = i; }

// Arithmetics functions.
// Compound operators.
Complex& Complex::operator+=(const Complex& other) {
    real += other.real;
    imag += other.imag;
    return *this;
}

} // namespace mymath