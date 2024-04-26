//
//  Circle.hpp
//  FinalProject
//
//  Created by marcus chen i wada on 4/22/24.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include "ofMain.h"

class Circle{
public:
    float x;
    float y;
    float r;
    
    Circle();
    Circle(float x_in, float y_in, float r_in);
    
    //setter
    void setCircle(float x_in, float y_in, float r_in);
    void setCircle(Circle c_in);
    float getX();
    float getY();
    float getR();

    //Getter
    Circle getCircle();
    void setX(float x_in);
    void setY(float y_in);
    void setR(float r_in);
    
    // Methods
    ofPoint* getRadialSamples(int n, bool t);
    
    

};

#endif /* Circle_hpp */
