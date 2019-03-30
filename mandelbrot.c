// Assignment 1 Mandelbrot
//
// Completed by
//  ... (z0000000)
//  ... (z0000000)
//
// Modified on 2017-??-??
// Tutor's name (dayHH-lab)

// Add your own #includes here

#include "mandelbrot.h"
#include "pixelColor.h"
#include <math.h>

// Add your own #defines here

// Add your own function prototypes here



// Draw a single Mandelbrot tile, by calculating and colouring each of
// the pixels in the tile.
//
// Your function "returns" this tile by filling in the `pixels` 2D array
// that is passed in to your function.
//
// The `pixels` array is TILE_SIZE high and TILE_SIZE wide.
// The bottom left corner of the image is pixels[0][0].
//
// `center` is a complex number, representing the center of the tile.
// `z` is used to calculate the distance between each pixel in the image.
// Each pixel is 2^(-z) apart from each other.
void drawMandelbrot(pixel pixels[TILE_SIZE][TILE_SIZE],
        complex center, int z) {
    // hint: use this array to store the result from escapeGrid.
    int grid[TILE_SIZE][TILE_SIZE];
    int x;
    int y;
    int steps;
    
    escapeGrid (grid, center, z);
    
    y = 0;
    
    while (y < TILE_SIZE) {
        x = 0;
        
        while (x < TILE_SIZE) {
            steps = grid[y][x];
            
            pixels[y][x] = pixelColor (steps);
            
            x++;
        }
        
        y++;
    }
}

// Determine the number of steps required to escape the Mandelbrot set,
// for the given complex number `c`.
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

    double zoom;
    int x;
    int y;
    complex point;
    
    zoom = exp2(-z);
    
    y = 0;
    
    while (y < TILE_SIZE) {
        point.im = center.im - (TILE_SIZE/2 - y) * zoom;
        
        x = 0;
        
        while (x < TILE_SIZE) {
            point.re = center.re - (TILE_SIZE/2 - x) * zoom;
            
            grid[y][x] = escapeSteps (point);
            
            x++;
        }
        
        y++;
    }
}

// Add your own functions here.
// Remember to make them static.

// Mandelbrot Value Calculator
static complex mandelbrotCalc (complex x, complex c) {
    complex xNew;
    
    xNew.re = x.re * x.re - x.im * x.im + c.re;
    xNew.im = 2 * x.re * x.im + c.im;
    
    return xNew;
}

// Complex modulus calculator
static double modulusSquared (complex x) {
    return (x.re * x.re + x.im * x.im);
}


