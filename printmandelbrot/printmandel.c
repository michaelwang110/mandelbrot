#include <stdio.h>
#include <stdlib.h>
#include "complex.h"
#include "printmandel.h"

// Complex Numbers
// Complex number is (re + im * i)
typedef struct _complex {
    double re;
    double im;
} complex;

int main(int argc, char *argv[]) {

  double x, y;
  printf("Enter X, Y for mandelbrot: ");
  scanf("%lf %lf", &x, &y);
  printf("mandelbrot for x:%lf y:%lf\n",x, y);
  printMandelbrot(x, y);

  return EXIT_SUCCESS;
}

int escapeSteps(double x, double y) {
  // return the number of escape steps
    int steps = 0;
    
    complex c = {x,y};
    complex x = {0,0};

    while ((steps < MAX_STEPS) && (modulusSquared (x) <= 4)) {
        complex x0;
        x0.re = x.re;
        x0.im = x.im;
        

        x.re = mandelbrotCalc (x0, c).re;
        x.im = mandelbrotCalc (x0, c).im;

        steps++;
    }
    
    if (steps == MAX_STEPS) {
        return NO_ESCAPE;
    }
    
    return steps;
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

// print out the Mandelbrot
void printMandelbrot(double left, double top) {
  double x, y;
  y = top;
  while (y > top - 2.0) {
    x = left;
    while (x < left + 3.0) {
      printPixel(x, y);
      x = x + PIXEL_JUMP;
    }
    printf("\n");
    y = y - 2*PIXEL_JUMP;
  }

}

// print out a pixel for an x, y coord
void printPixel(double x, double y) {
  if (escapeSteps(x, y) < MAX_STEPS) {
    printf(" ");
  } else {
    printf("*");
  }
}
