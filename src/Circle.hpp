//
//  Circle.hpp
//  Assignment5
//
//  Created by marcus chen i wada on 4/7/24.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <Fill.hpp>
#include <Point.hpp>
#include <cmath>




class Circle{
public:
    //Member Variables
    int x;
    int y;
    int r;
//    Fill c;
    
    //Methods
    Circle();
    Circle(int x_in, int y_in, int r_in);
    void setCircle(int x_in, int y_in, int r_in);
//    void setCircleColor(int r, int g, int b);
//    void setCircleColor(Fill c_in);
    bool CircleIntersect(Circle c2);
    
    Pointt* calculateSetEquidistantpoints(int numPoints);
    //What if it returns me just the next point?
//    Pointt calculateNextSetEquidistantpoints(int numPoints);
    
    
};


#endif /* Circle_hpp */
