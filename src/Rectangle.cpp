//
//  Rectangle.cpp
//  Assignment5
//
//  Created by marcus chen i wada on 4/7/24.
//

#include "Rectangle.hpp"

Rectangle::Rectangle(){
    x = 0;
    y = 0;
    w = 0;
    h = 0;
}
Rectangle::Rectangle(int x_in, int y_in, int w_in, int h_in){
    x = x_in;
    y = y_in;
    w = w_in;
    h = h_in;
}
void Rectangle::setPosition(int x_in, int y_in){
    x = x_in;
    y = y_in;
}
void Rectangle::setSize(int w_in, int h_in){
    w = w_in;
    h = h_in;
}
