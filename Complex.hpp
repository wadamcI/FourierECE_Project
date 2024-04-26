//
//  Complex.hpp
//  FinalProjectTest
//
//  Created by marcus chen i wada on 4/26/24.
//

#ifndef Complex_hpp
#define Complex_hpp

#include <stdio.h>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructors
    Complex();
    Complex(double re, double im);

    // Getter methods
    double getReal() const;
    double getImaginary() const;
    
    
    double getModulus() const;
    double getArgument() const;

    // Setter methods
    void setReal(double re);
    void setImaginary(double im);

    // Operator overloading
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;


    // Display method
    void display() const;
};

#endif /* Complex_hpp */

