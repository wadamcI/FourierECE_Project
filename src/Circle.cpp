//
//  Circle.cpp
//  Assignment5
//
//  Created by marcus chen i wada on 4/7/24.
//

#include "Circle.hpp"
#include <math.h>


Circle::Circle(){
    x = 0;
    y = 0;
    r = 0;
}
Circle::Circle(int x_in, int y_in, int r_in){
    x = x_in;
    y = y_in;
    r = r_in;
}
void Circle::setCircle(int x_in, int y_in, int r_in){
    x = x_in;
    y = y_in;
    r = r_in;
}
//void Circle::setCircleColor(int r, int g, int b){
//    c.r = r;
//    c.g = g;
//    c.b = b;
//
//}
//void Circle::setCircleColor(Fill c_in){
//    c = c_in;
//}
bool Circle::CircleIntersect(Circle c2){
    int dist;
    dist = sqrt((x-c2.x)*(x-c2.x)+(y-c2.y)*(y-c2.y));
    if (dist<r+c2.r){
        return true;
    }
    else return false;
}

Pointt* Circle::calculateSetEquidistantpoints(int numPoints){
    Pointt *points = new Pointt[numPoints];
        
    for (int i = 0; i < numPoints; ++i) {
        float angle = 2 * M_PI * i / numPoints; // Calculate angle in radians
        points[i].x = x + r * cos(angle); // Calculate X coordinate
        points[i].y = y + r * sin(angle); // Calculate Y coordinate
    }
    return points;
}

//Pointt calculateNextSetEquidistantpoints(int numPoints){
//    Pointt point;
//    
//    return point;
//}
