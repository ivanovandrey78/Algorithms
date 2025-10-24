#pragma once

#include <iostream>
#include <string>

namespace math {
    
class Complex {
private:

    double real;
    double imag;
    
public:
    // Construct. 
    // Default constructor - 0 + 0i
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    Complex(const Complex &other) = default; // Copy from other number 
    
    // Getters.
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Setters. 
    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }
    
    // Arithmetics functions.
    // Compound operators.
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    //Unary operators.
    Complex operator-() const;

    //Binary operators.
    friend Complex operator+(const Complex& lhs,const Complex& rhs);
    friend Complex operator-(const Complex& lhs,const Complex& rhs);
    friend Complex operator*(const Complex& lhs,const Complex& rhs);
    friend Complex operator/(const Complex& lhs,const Complex& rhs);
    
    // Compare.
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    
    // Math functions.
    double magnitude() const;
    double phase() const;
    Complex conjugate() const; // Сопряженное 
    Complex reciprocal() const; 

    // Stream Complex number.
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
    std::string trigonometric_form(const Complex& number);
    
    // Utilits.
    std::string to_string() const;
    static Complex from_polar(double magnitude, double phase);

    // Other functions.
    bool is_zero() const;
    
}; 

} // namespace math