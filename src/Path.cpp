//
//  Path.cpp
//  Assignment5
//
//  Created by marcus chen i wada on 4/1/24.
//

#include "Path.hpp"

Path::Path(){
    n = 0;
    xptr = nullptr;
    yptr = nullptr;
    t=0;
    closed = false;
    
}
Path::Path(int n_in, int *x_in, int *y_in, bool closed_in, int t_in, Fill c_in){
    n = n_in;
    
    xptr = new int[n];
    yptr = new int[n];
    
    for (int i = 0; i < n_in; ++i) {
        xptr[i] = x_in[i];
        yptr[i] = y_in[i];
    }
    
    closed = closed_in;
    
    c = c_in;
    t = t_in;
}

void Path::setPath(int n_in, int *x_in, int *y_in){
    n = n_in;
    xptr = x_in;
    yptr = y_in;
}
void Path::setPathLineWidth(int t_in){
    t = t_in;
}
void Path::setPathColor(Fill c_in){
    c = c_in;
}
void Path::addVertex(int x_in, int y_in){
    int *new_xptr = new int[n + 1];
    int *new_yptr = new int[n + 1];
        
    for (int i = 0; i < n; ++i) {
        new_xptr[i] = xptr[i];
        new_yptr[i] = yptr[i];
    }
    
    new_xptr[n] = x_in;
    new_yptr[n] = y_in;
        
    delete[] xptr;
    delete[] yptr;
    
    xptr = new int[n+1];
    yptr = new int[n+1];
    
    for (int i = 0; i < n+1; ++i) {
        xptr[i] = new_xptr[i];
        yptr[i] = new_yptr[i];
    }
    
    
    n=n+1;
}

void Path::clear(){
    delete[] xptr;
    delete[] yptr;
    n = 0;
}

void Path::setClosed(bool closed_in){
    closed = closed_in;
}

int Path::getNumVertices(){
    return n;
}

bool Path::isClosed(){
    return closed;
}


Path::~Path() {
}
