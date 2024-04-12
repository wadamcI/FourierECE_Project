//
//  Fill.cpp
//  Assignment5
//
//  Created by marcus chen i wada on 4/1/24.
//

#include "Fill.hpp"
Fill::Fill(){
    r = 0;
    g = 0;
    b = 0;
    alpha = 255;
}
Fill::Fill(int red_in, int green_in, int blue_in, int alpha_in){
    r = red_in;
    g = green_in;
    b = blue_in;
    alpha = alpha_in;
    
}
void Fill::print(string label){
    
}
void Fill::setColor(int red_in, int green_in, int blue_in){
    r = red_in;
    g = green_in;
    b = blue_in;
    alpha = 255;
    
}
