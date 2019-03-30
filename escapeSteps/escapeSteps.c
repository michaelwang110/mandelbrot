// Assignment 1 Mandelbrot
//
// Completed by
//  ... (z0000000)
//  ... (z0000000)
//
// Modified on 2017-??-??
// Tutor's name (dayHH-lab)

#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define RULE 100

typedef struct _complex {
    double re;
    double im;
} complex;

complex complexMod (complex z, complex u);
int escapeSteps (complex x);

int main (int argc, char *argv[]) {
    complex z = {2.8, 5.9};
    complex u = {1.0, 3.0};
    int x = 0;
    
    while (x <= 32) {
        int y = 0;
        
        while (y <= 85) {
            int i = 1;
            z = complexMod (z,u);
            
            while (i < RULE) {
                if (escapeSteps (z) == TRUE) {
                    printf ("*");
                } else {
                    printf (" ");
                }
                i++;
            }
            y++;
        }
        x++;
    }
    
    return EXIT_SUCCESS;
}

complex complexMod (complex z, complex u) {
    complex znew;
    
    znew.re = z.re*z.re - z.im*z.im + u.re;
    znew.im = 2*z.re*z.im + u.im;
    
    return znew;
}

int escapeSteps (complex x) {
    double length = 0;
    
    length = x.re*x.re +x.im*x.im;
    
    if (length > 4) {
        return FALSE;
    } else {
        return TRUE;
    }
}
