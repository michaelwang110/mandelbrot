// Print an "ascii-brot" flag picture of the Mandelbrot set

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Size of each image
#define HEIGHT 50
#define WIDTH 80

// Escape Steps
#define MAX_STEPS 256
#define NO_ESCAPE -1

#define ZOOM 6
#define TRUE 1
#define FALSE 0

typedef struct _complex {
    double re;
    double im;
} complex;

typedef struct _pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

int escapeSteps (complex c);
complex mandelbrotCalc (complex x, complex c);
double modulusSquared (complex x);
double modComplex (complex num);
complex squareComplex (complex num);
complex addComplex (complex num, complex num1);

int main (int argc, char *argv[]) {
    complex c = {-1.5000000000000, -1.5000000000000};
    
    int steps = escapeSteps (c);
    
    printf ("%d\n", steps);
    
    return EXIT_SUCCESS;
}

int escapeSteps(complex c) {
    complex z = {0,0};
    // Inital step, z=z^2 + c, where z is 0 + 0i.
    z = addComplex(squareComplex(z), c);
    int steps = 1;
    // For all values of |z| where |z^2 + c| < 2 AND steps < 256
    while ((modComplex(z) <= 4) && (steps < MAX_STEPS)) {
        // Update z with the previous result of z.
        z = addComplex(squareComplex(z), c);
        steps++;
    }
    return steps;
}

// Complex Add Function: Separately add the Real & Imaginary part of num & num1.
complex addComplex (complex num, complex num1) {
    complex sum;
    sum.re = num.re + num1.re;
    sum.im = num.im + num1.im;
    return sum;
}

// Complex Square Function: c^2 = Re(c^2) - Im(c^2) + 2*Re(c) + 2*Im(c)
// Where the Real part of c^2 = Re(c^2) - Im(c^2)
// And the Imaginary part of c^2 = 2*Re(c) + 2*Im(c)
complex squareComplex (complex num) {
    complex square;
    square.re = pow(num.re, 2) - pow(num.im, 2);
    square.im = 2*num.re*num.im;
    return square;
}

// Complex Modulus Function: Square root of the sum of the Real and Imaginary part
double modComplex (complex num) {
    double modulus = sqrt(pow(num.re,2) + pow(num.im,2));
    return modulus;
}
// Mandelbrot Value Calculator
complex mandelbrotCalc (complex x, complex c) {
    complex xNew;
    
    xNew.re = x.re * x.re - x.im * x.im + c.re;
    xNew.im = 2 * x.re * x.im + c.im;
    
    return xNew;
}

// Complex modulus calculator
double modulusSquared (complex x) {
    return (x.re * x.re + x.im * x.im);
}

