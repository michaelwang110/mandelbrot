#include <stdio.h>
#include <math.h>
#include "complex.h"

// (a + ib) * (c + id)
// a*c + i(b*c + a*d) - c*d
complex complexMult(complex a, complex b) {
  complex result;
  result.real = a.real*b.real - a.imaginary * b.imaginary;
  result.imaginary = a.imaginary*b.real + a.real*b.imaginary;
  return result;
}

// (a + c) + i(d + b)
complex complexAdd(complex a, complex b) {
  complex result;
  result.real = a.real + b.real;
  result.imaginary = a.imaginary + b.imaginary;
  return result;
}

// | w | = sqrt(a^2 + b^2)
double complexMag(complex a) {
  return sqrt(a.real*a.real + a.imaginary*a.imaginary);
}
