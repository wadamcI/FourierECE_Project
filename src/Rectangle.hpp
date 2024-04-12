//
//  Rectangle.hpp
//  Assignment5
//
//  Created by marcus chen i wada on 4/7/24.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <Fill.hpp>



class Rectangle {
public:
    
    // Variables
    int x;
    int y;
    int w;
    int h;

    // Methods
    Rectangle(); // Default constructor
    Rectangle(int x_in, int y_in, int w_in, int h_in);
    
    void setPosition(int x_in, int y_in);
    void setSize(int w_in, int h_in);

    
};

#endif /* Rectangle_hpp */
