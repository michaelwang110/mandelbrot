#ifndef _MANDEL_H
#define _MANDEL_H

#define PIXEL_JUMP 0.025
#define MAX_STEPS 256
#define MANDELBROT_LIM 2.0

// Complex Numbers
// Complex number is (re + im * i)
typedef struct _complex {
    double re;
    double im;
} complex;


int escapeSteps(double x, double y);

void printMandelbrot(double left, double top);

void printPixel(double x, double y);

complex mandelbrotCalc (complex x, complex c);

double modulusSquared (complex x);

#endif
