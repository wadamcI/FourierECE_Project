//
//  Stroke.cpp
//  Assignment5
//
//  Created by marcus chen i wada on 4/7/24.
//

#include "Stroke.hpp"


Stroke::Stroke(){
    t = 0;
}
Stroke::Stroke(Rectangle rectangle_in, Fill c_in, int t_in){
    rectangle = rectangle_in;
    c = c_in;
    t = t_in;
}
Stroke::Stroke(Circle circle_in, Fill c_in, int t_in){
    circle = circle_in;
    c = c_in;
    t = t_in;
}
void Stroke::setStroke(Rectangle rectangle_in, Fill c_in, int t_in){
    rectangle = rectangle_in;
    c = c_in;
    t = t_in;
}
void Stroke::setStroke(Circle circle_in, Fill c_in, int t_in){
    circle = circle_in;
    c = c_in;
    t = t_in;
}
