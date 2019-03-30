// Print an "ascii-brot" flag picture of the Mandelbrot set

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Size of each image
#define TILE_SIZE 512

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
void escapeGrid(int grid[TILE_SIZE][TILE_SIZE],
        complex center, int z);


int main (int argc, char *argv[]) {
    int grid[TILE_SIZE][TILE_SIZE];
    complex center = {0,0};
    int z = ZOOM;
    int y = 0;
    
    escapeGrid (grid, center, z);
    
    while (y < TILE_SIZE) {
        int x = 0;
        while (x < TILE_SIZE) {
            if (grid[y][x] == NO_ESCAPE) {
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

// Fill a grid of TILE_SIZE by TILE_SIZE pixels, with the number of
// steps each pixel took to escape the Mandelbrot set.
void escapeGrid(int grid[TILE_SIZE][TILE_SIZE],
        complex center, int z) {
    
    double zoom = exp2(-z);
    int y = 0;
    
    while (y < TILE_SIZE) {
        int x = 0;
        
        while (x < TILE_SIZE) {
            complex point;
            point.re = center.re - TILE_SIZE/2 * zoom + x * zoom;
            point.im = center.im - TILE_SIZE/2 * zoom + y * zoom;
            
            grid[y][x] = escapeSteps (point);
            
            x++;
        }
        
        y++;
    }
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

