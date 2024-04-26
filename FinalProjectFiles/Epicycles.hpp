//
//  Epicycles.hpp
//  FinalProject
//
//  Created by marcus chen i wada on 4/22/24.
//

#ifndef Epicycles_hpp
#define Epicycles_hpp


#include <stdio.h>
#include "Circle.hpp"
class Circle;

class Epicycles{
public:
    float x;
    float y;
    float er;
    float ar;
    float f;
    bool t;
    int i;
    Epicycles();
    Epicycles( Circle *pCircle_in, float ar_in, float f_in, int i_in, bool t_in);
    void setEpicycles( Circle *pCircle_in, float ar_in, float f_in, int i_in, bool t_in);
    void setEpicycles( Epicycles *epicycle_in, Circle *pCircle_in, float ar_in, float f_in, int i_in, bool t_in);
    
    void printEpicycles() const {
            std::cout << "x: " << x << ", y: " << y << ", r: " << er
                      << ", ar: " << ar << ", f: " << f << ", i: " << i << std::endl;
        }
};

#endif /* Epicycles_hpp */
