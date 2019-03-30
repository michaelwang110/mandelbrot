#ifndef _COMPLEX_H
#define _COMPLEX_H

typedef struct _complex {
  double real;
  double imaginary;

} complex;

// (a + ib) * (c + id)
// a*c + i(b*c + a*d) - i*d
complex complexMult(complex a, complex b);

// (a + c) + i(d + b)
complex complexAdd(complex a, complex b);

// | w | = sqrt(a^2 + b^2)
double complexMag(complex a);

#endif
