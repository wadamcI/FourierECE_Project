//
//  Fill.hpp
//  Assignment5
//
//  Created by marcus chen i wada on 4/1/24.
//

#ifndef Fill_hpp
#define Fill_hpp

#include <stdio.h>
#include <iostream>
#include <string>



using namespace std;
class Fill{
public:
    //Member variables
    int r;
    int g;
    int b;
    
    int alpha;
    
    
    //Methods
    Fill();
    Fill(int red_in, int green_in, int blue_in, int alpha_in);
    void print(string label);
    void setColor(int red_in, int green_in, int blue_in);
};


#endif /* Fill_hpp */
