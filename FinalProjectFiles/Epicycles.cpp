//
//  Epicycles.cpp
//  FinalProject
//
//  Created by marcus chen i wada on 4/22/24.
//

#include "Epicycles.hpp"
#include "Circle.hpp"
#include <math.h>

#define C 360

Epicycles::Epicycles(){
    x = 1;
    y = 1;
    er = 1;
    ar = 1;
    f = 0;
    i = 0;
    t = true;
    
    
}
Epicycles::Epicycles(Circle *pCircle_in, float ar_in, float f_in, int i_in, bool t_in){
    ofPoint *radialSamples;
    
    radialSamples = pCircle_in->getRadialSamples(C, t_in);
    
    er = pCircle_in->getR()*ar_in;
    i = (int)((i_in*f_in*6)) % (int)(C);
    x = (radialSamples+i)->x;
    y = (radialSamples+i)->y;
    
    delete[] radialSamples;
}
void Epicycles::setEpicycles( Circle *pCircle_in, float ar_in, float f_in, int i_in, bool t_in){
    
    ofPoint *radialSamples;
    radialSamples = pCircle_in->getRadialSamples(C, t_in);
    er = pCircle_in->r * ar_in;
    i = (int)((i_in*f_in*6)) % (int)(C);
    x = (radialSamples + i)->x;
    y = (radialSamples + i)->y;
    
    delete[] radialSamples;
}

void Epicycles::setEpicycles( Epicycles *epicycle_in, Circle *pCircle_in, float ar_in, float f_in, int i_in, bool r_in){
    ofPoint *radialSamples;
    Circle c;
    c.setCircle(epicycle_in->x, epicycle_in->y, epicycle_in->er);
    radialSamples = c.getRadialSamples(C, r_in);
    er = (pCircle_in->r)*ar_in;
    i = (int)round(i_in*f_in*6) % (int)(C);
    x = (radialSamples + i)->x;
    y = (radialSamples + i)->y;
}
