//
//  Circle.cpp
//  FinalProject
//
//  Created by marcus chen i wada on 4/22/24.
//
#include <iostream>
#include "Circle.hpp"
#include <math.h>

Circle::Circle(){
    x = 100;
    y = 100;
    r = 100;
}
Circle::Circle(float x_in, float y_in, float r_in) {
    setX(x_in);
    setY(y_in);
    setR(r_in);
}


float Circle::getX() {
    return x;
}

float Circle::getY() {
    return y;
}

float Circle::getR() {
    return r;
}

// Setter methods

void Circle::setX(float x_in) {
    if (x_in > 0) {
        x = x_in;
    } else {
        std::cout << "Incorrect value for X coordinate. Please enter a value greater than 0." << std::endl;
    }
}

void Circle::setY(float y_in) {
    if (y_in > 0) {
        y = y_in;
    } else {
        std::cout << "Incorrect value for Y coordinate. Please enter a value greater than 0." << std::endl;
    }
}

void Circle::setR(float r_in) {
    r = r_in;
}

// Method to set circle properties
void Circle::setCircle(float x_in, float y_in, float r_in) {
    setX(x_in);
    setY(y_in);
    setR(r_in);
}

// Method to set circle properties from another circle
void Circle::setCircle(Circle c_in) {
    setX(c_in.getX());
    setY(c_in.getY());
    setR(c_in.getR());
}

// Method to get the entire circle
Circle Circle::getCircle() {
    return Circle(x, y, r);
}


ofPoint* Circle::getRadialSamples(int n, bool t){
    ofPoint *points = new ofPoint[n];
        
    if(t){
        for (int i = 0; i < n; i++) {
            float angle = 2 * M_PI * i / n; // Calculate angle in radians
            points[i].x = x + r * cos(angle); // Calculate X coordinate
            points[i].y = y + r * sin(angle); // Calculate Y coordinate
        }
        return points;
    }
    else {
        for (int i = 0; i < n; i++) {
            float angle = 2 * M_PI * i / n; // Calculate angle in radians
            points[i].x = x + r * cos(angle); // Calculate X coordinate
            points[i].y = y - r * sin(angle); // Calculate Y coordinate
        }
        return points;
    }
}
