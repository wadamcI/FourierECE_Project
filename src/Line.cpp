//
//  Line.cpp
//  Assignment5
//
//  Created by marcus chen i wada on 4/7/24.
//

#include "Line.hpp"

Line::Line(){
    x1 = 0;
    x2 = 0;
    y1 = 0;
    y2 = 0;
    t = 0;
    c.r = 0;
    c.g = 0;
    c.b = 0;
}
Line::Line(int x1_in, int y1_in, int x2_in, int y2_in, Fill c_in){
    x1 = x1_in;
    x2 = x2_in;
    y1 = y1_in;
    y2 = y2_in;
    c =  c_in;
}
void Line::setLine(int x1_in, int y1_in, int x2_in, int y2_in){
    x1 = x1_in;
    x2 = x2_in;
    y1 = y1_in;
    y2 = y2_in;
    
}
void Line::setLineColor(int r, int g, int b){
    c.r = r;
    c.g = g;
    c.b = b;
    
}
void Line::setLineColor(Fill f){
    c = f;
    
}
void Line::setThickness(int t_in){
    t = t_in;
}
