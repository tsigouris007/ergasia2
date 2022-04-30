/* This code is from the book "Algorithms in C, 3rd edition" by Robert Sedgewick. */

typedef struct complex *Complex;
Complex COMPLEXinit(float, float);
  float Re(Complex);
  float Im(Complex);
Complex COMPLEXmult(Complex, Complex);
