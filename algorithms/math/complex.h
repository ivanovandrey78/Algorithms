#pragma once

#include <iostream>

namespace mymath {
    
class Complex {
private:

    double real;
    double imag;
    
public:
    // Construct. 

    // Default constructor - 0 + 0i 
    Complex(); 

    Complex(double r);

    Complex(double r = 0.0, double i = 0.0); // standart initialisation

    Complex(const Complex &other); // copy wth other number 
    
    // Get-operators.
    double getReal() const;
    double getImag() const;

    // Edit-operators 
    void setReal(double r); 
    void setImag(double i);
    
    // Arithmetics functions.
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    
    // Compare.
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    
    // Math functions.
    double magnitude() const;
    double phase() const;
    Complex conjugate() const; // Сопряженное 
    Complex reciprocal() const; //Обратное на русский...
    
    // Utilits.
    std::string to_string() const;
    static Complex from_polar(double magnitude, double phase);
};

} 