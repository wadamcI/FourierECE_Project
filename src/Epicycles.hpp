//
//  Epicycles.hpp
//  Assignment5
//
//  Created by marcus chen i wada on 4/10/24.
//

#ifndef Epicycles_hpp
#define Epicycles_hpp
#include "Circle.hpp"

#include <stdio.h>
class Epicycles: public Circle
{
public:
    //Member variables:
    Circle c;
    int ratio;
    int v;
    
    //Methods
    Epicycles();
    Epicycles(Circle c_in, int ratio_in, int v_in);
    
    void setEpicycles(Circle c_in, int ratio_in, int v_in);
    void setEpicyclesVelocity(int v_in);
    void setEpicycleRatio(int ratio_in);
    
    
};

#endif /* Epicycles_hpp */
