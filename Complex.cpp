//
//  Complex.cpp
//  FinalProjectTest
//
//  Created by marcus chen i wada on 4/26/24.
//

#include "Complex.hpp"
#include <iostream>
#include <math.h>


// Constructors
Complex::Complex() : real(0.0), imag(0.0) {}

Complex::Complex(double re, double im) : real(re), imag(im) {}

// Getter methods
double Complex::getReal() const {
    return real;
}

double Complex::getImaginary() const {
    return imag;
}

// Setter methods
void Complex::setReal(double re) {
    real = re;
}

void Complex::setImaginary(double im) {
    imag = im;
}

// Operator overloading
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    double newReal = real * other.real - imag * other.imag;
    double newImag = real * other.imag + imag * other.real;
    return Complex(newReal, newImag);
}

// Display method
void Complex::display() const {
    std::cout << real;
    if (imag >= 0)
        std::cout << " + " << imag << "i";
    else
        std::cout << " - " << -imag << "i";
    std::cout << std::endl;
}


double Complex::getModulus() const {
    return sqrt(imag*imag+real*real);
}
double Complex::getArgument() const {
    if (real == 0.0 && imag == 0.0) {
            return 0.0;
    } else {
        return atan2(imag, real);
    }
}

