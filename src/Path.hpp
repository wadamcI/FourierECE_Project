//
//  Path.hpp
//  Assignment5
//
//  Created by marcus chen i wada on 4/1/24.
//
#ifndef Path_hpp
#define Path_hpp

#include <iostream>
#include "Fill.hpp" // Assuming Fill.hpp contains the definition of Fill class

class Path {
public:
    // Member Variables
    int n;
    bool closed;
    int *xptr;
    int *yptr;
    Fill c;
    int t;
    
    // Methods
    Path();
    Path(int n_in, int *x_in, int *y_in, bool closed_in, int t_in, Fill c_in);
    ~Path();
    
    void setPath(int n_in, int *x_in, int *y_in);
    void setPathLineWidth(int t_in);
    void setPathColor(Fill c_in);
    void addVertex(int x_in, int y_in);
    void clear();
    void setClosed(bool closed_in);
    int getNumVertices();
    bool isClosed();
};

#endif /* Path_hpp */

