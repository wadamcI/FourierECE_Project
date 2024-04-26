//
//  FFT.cpp
//  FinalProjectTest
//
//  Created by marcus chen i wada on 4/26/24.
//

#include "FFT.hpp"
FFT::FFT() : array(nullptr), N(0) {}
FFT::~FFT() {
    delete[] array;
}

void FFT::set(Complex *array_in,unsigned int N_in ){
    array = new Complex[N_in];
    for (unsigned int i = 0; i < N_in; ++i) {
        array[i] = array_in[i];
    }
    N=N_in;
}
void FFT::fft(){
    if (N <= 1) return;
    
    //Divide
    Complex *even, *odd;
    int halfN = N / 2;
    even = new Complex[halfN];
    odd = new Complex[N - halfN];
    
    int count1 =0, count2=0;
    for(int i=0; i<N; i++){
        if(i%2==0){
            even[count1] = array[i];
            count1++;
        }
        if(i%2==1){
            odd[count2] = array[i];
            count2++;
        }
    }
    //conquer
    FFT evenA, oddA;
    evenA.set(even, halfN);
    oddA.set(odd, N - halfN );
    
    evenA.fft();
    oddA.fft();
        
    //combine
    for(int k=0; k<N/2; k++){
        Complex t;
        t.setReal(cos(-2 * M_PI * k / N));
        t.setImaginary(sin(-2 * M_PI * k / N));
        Complex tTimesOdd = t * odd[k];
        
        array[k] = even[k] + tTimesOdd;
        array[k+N/2] = even[k] - tTimesOdd;
    }
    
    delete[] even;
    delete[] odd;
}



void FFT::ifft(){

    //Conjugate
    for(int i=0; i<N; i++){
        array[i].setImaginary(-array[i].getImaginary());
    }
    // forward fft
    FFT forwardFFT;
    forwardFFT.set(array, N);
    forwardFFT.fft();
    
    // conjugate the complex numbers again and scale
    for (int i = 0; i < N; ++i) {
        forwardFFT.array[i].setImaginary(-forwardFFT.array[i].getImaginary() / N);
        forwardFFT.array[i].setReal(forwardFFT.array[i].getReal() / N);
    }
    
    for (int i = 0; i < N; ++i) {
        array[i] = forwardFFT.array[i];
    }
}
