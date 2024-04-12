//
//  Stroke.hpp
//  Assignment5
//
//  Created by marcus chen i wada on 4/7/24.
//

#ifndef Stroke_hpp
#define Stroke_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Fill.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Line.hpp"


using namespace std;

class Stroke{
    
public:
    //Member Variables
    Rectangle rectangle;
    Circle circle;
    int t;
    Fill c;
    
    
    //methods
    Stroke();
    Stroke(Rectangle rectangle_in, Fill c_in, int t_in);
    Stroke(Circle circle_in, Fill c_in, int t_in);
    
    void setStroke(Rectangle rectangle_in, Fill c_in, int t_in);
    void setStroke(Circle circle_in, Fill c_in, int t_in);
    
    
};


#endif /* Stroke_hpp */
