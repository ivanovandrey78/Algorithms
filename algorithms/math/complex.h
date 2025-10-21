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
    Complex();                               // 0 + 0i
    Complex(double r);                       // r + 0i  
    Complex(double r, double i);             // r + i
    Complex(const Complex &other) = default; // Copy from other number 
    
    // Getters.
    double getReal() const;
    double getImag() const;

    // Setters.
    void setReal(double r); 
    void setImag(double i);
    
    // Arithmetics functions.
    // Compound operators.
    Complex operator+=(const Complex& other);
    Complex operator-=(const Complex& other);
    Complex operator*=(const Complex& other);
    Complex operator/=(const Complex& other);

    //Unary operators
    Complex operator-() const;
    Complex operator+() const;

    //Binary operators
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

    // Stream Complex number
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
    
    // Utilits.
    std::string to_string() const;
    static Complex from_polar(double magnitude, double phase);
}; 

} // namespace math