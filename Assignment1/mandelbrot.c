// Assignment 1 Mandelbrot
//
// Completed by
//  ... (z0000000)
//  ... (z0000000)
//
// Modified on 2017-??-??
// Tutor's name (dayHH-lab)

// Add your own #includes here

#include <stdio.h>
#include <stdlib.h>
#include "mandelbrot.h"
#include "pixelColor.h"

// Add your own #defines here

#define BREAK_OUT 4

// Add your own function prototypes here
static complex complexAdd(complex a, complex b);
static complex complexMultiply(complex a, complex b);
static double complexAbsolute(complex c);
static void pixelCalc (complex c);


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

    // TODO: COMPLETE THIS FUNCTION

}

// Determine the number of steps required to escape the Mandelbrot set,
// for the given complex number `c`.
int escapeSteps(complex c) {
    
    int steps = 0;
    complex start = {0, 0};

    // TODO: COMPLETE THIS FUNCTION
    while (complexAbsolute(start) < BREAK_OUT && steps < MAX_STEPS) {
        start = complexMultiply(start, start);
        start = complexAdd(start, c);
        steps++;
        //printf("%d\n", steps);
        //if (steps == MAX_STEPS) {
        //    return NO_ESCAPE;
       // }
    }
    return steps;

}

// Fill a grid of TILE_SIZE by TILE_SIZE pixels, with the number of
// steps each pixel took to escape the Mandelbrot set.
void escapeGrid(int grid[TILE_SIZE][TILE_SIZE],
        complex center, int z) {

    // TODO: COMPLETE THIS FUNCTION

}

// Add your own functions here.
// Remember to make them static.
static complex complexAdd(complex a, complex b){
    // PUT YOUR CODE HERE;
    complex value;
    value.re = a.re + b.re;
    value.im = a.im + b.im;

    return value;
}
static complex complexMultiply(complex a, complex b){
    // PUT YOUR CODE HERE;
    complex value = {
        .re = (a.re * b.re) - (a.im * b.im),
        .im = (a.im * b.re) + (a.re * b.im)
    };

    return value;
}
static double complexAbsolute(complex c) {
    // PUT YOUR CODE HERE;
    double ab = (c.re * c.re + c.im * c.im);

    return ab; // CHANGE THIS TO YOUR RETURN VALUE
}
static void pixelCalc (complex c) {
    if (escapeSteps(c) < MAX_STEPS) {
        printf(" ");
    } else {
        printf("*");
    }
}
