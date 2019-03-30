// Assignment 1 Mandelbrot: Pixel Color
//
// Completed by
//  ... (z0000000)
//  ... (z0000000)
//
// Modified on 2017-??-??
// Tutor's name (dayHH-lab)

#include "mandelbrot.h"
#include "pixelColor.h"

// This function should take a number (of steps taken to escape the
// Mandelbrot set), and convert it to a color.
//
// You have artistic licence here, so make your Mandelbrot look amazing.
pixel pixelColor(int steps) {
    pixel color = {
        .red = 0,
        .green = 0,
        .blue = 0
    };

    if (steps == NO_ESCAPE) {
        color.red = 0x0;
        color.green = 0x0;
        color.blue = 0x0;
    } else {
        color.red = 0xFF;
        color.green = 0xFF;
        color.blue = 0xFF;
    }

    return color;
}
