//
//  Line.hpp
//  Assignment5
//
//  Created by marcus chen i wada on 4/7/24.
//

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Fill.hpp"



using namespace std;

class Line{
public:
    //Member Variables:
    int x1;
    int x2;
    int y1;
    int y2;
    int t;
    Fill c;
    
    //Methods:
    Line();
    Line(int x1_in, int y1_in, int x2_in, int y2_in, Fill c_in);
    void setLine(int x1_in, int y1_in, int x2_in, int y2_in);
    void setLineColor(int r, int g, int b);
    void setLineColor(Fill f);
    void setThickness(int t_in);
    
    
//    methods to consider
//    float length() const; (to calculate the length of the line)
//    void translate(int dx, int dy); (to translate the line by a given offset)
//    rotate();

    
};


#endif /* Line_hpp */
