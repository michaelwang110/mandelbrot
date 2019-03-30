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


int main (int argc, char *argv[]) {
    int y = -10;
    int z = ZOOM;
    complex center;
    int steps;

    while (y < 10) {
        int x = -50;
        while (x < 30) {
            double z = exp2(-ZOOM);
            
            complex c;
            c.re = x * z;
            c.im = y * z;
            
            int escape = escapeSteps (c);
            
            if (escape == NO_ESCAPE) {
                printf ("*");
            } else {
                printf (" ");
            }
            x++;
        }
        
        printf ("\n");
        
        y++;
    }
    
    return EXIT_SUCCESS;
}

int escapeSteps(complex c) {
    int steps = 0;
    int setCheck = TRUE;
    
    complex x;
    x.re = c.re;
    x.im = c.im;
    
    while (steps < MAX_STEPS && setCheck == TRUE) {
        complex x0;
        x0.re = x.re;
        x0.im = x.im;
        

        x.re = mandelbrotCalc (x0, c).re;
        x.im = mandelbrotCalc (x0, c).im;
        
        if (modulusSquared(x) > 4) {
            setCheck = FALSE;
        } else {
            steps++;
        }
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

