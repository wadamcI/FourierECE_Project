//
//  FFT.hpp
//  FinalProjectTest
//
//  Created by marcus chen i wada on 4/26/24.
//

#ifndef FFT_hpp
#define FFT_hpp

#include <stdio.h>
#include "Complex.hpp"
#include <iostream>
#include <math.h>

class FFT{
public:
    //Variable
    Complex *array;
    unsigned int N;
    
    
    //Methods
    FFT();
    ~FFT();
        
    void set(Complex *array_in,unsigned int N_in );
    void fft();
    void ifft();
    
    
};



#endif /* FFT_hpp */
