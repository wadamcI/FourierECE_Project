//
//  Point.hpp
//  Assignment5
//
//  Created by marcus chen i wada on 4/7/24.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
class Pointt{
public:
    // Member variables
    int x;
    int y;

    // Methods
    Pointt();
    Pointt(int x_in, int y_in);
    void set(int x_in, int y_in);
};

#endif /* Point_hpp */
