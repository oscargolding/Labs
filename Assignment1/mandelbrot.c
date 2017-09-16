// Assignment 1 Mandelbrot
//
// Completed by
//  Michaela (z5117328)
//  Jack (z5162832)
//  Oscar (z5160173)
// Modified on 2017-16-09
// Tutor's name (dayHH-lab)
// Alex Hinds (Tuesday 9-12)

// Add your own #includes here

#include "mandelbrot.h"
#include "pixelColor.h"
#include <stdio.h>
#include <stdlib.h>

// Add your own #defines here

#define BREAK_OUT 4

// Add your own function prototypes here

static complex complexAdd(complex a, complex b);
static complex complexMultiply(complex a, complex b);
static double complexAbsolute(complex c);
static double power (int base, int power);

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
    printf("centre = %lf %lfi\n", center.re, center.im);
    // hint: use this array to store the result from escapeGrid.
    // Initialise a given two-dimensial arrays with the number of steps
    // it took to reach a breakout point.
    int grid[TILE_SIZE][TILE_SIZE];
    escapeGrid(grid, center, z);
    int row = 0;
    int column;
    // Use a while loop to assign the steps to a relevant RGB value
    // that can be used for BMP images.
    while (row < TILE_SIZE){
        column = 0;
        while (column < TILE_SIZE) {
            pixels[row][column] = pixelColor(grid[row][column]);
            column++;
        }
        row++;
    }
}
// Determine the number of steps required to escape the Mandelbrot set,
// for the given complex number `c`.
int escapeSteps(complex c) {
    // Sets the reference point for the Mandelbrot mathematics.
    int steps = 0;
    complex start = {0, 0};
    // Uses a loop to determine the number of steps before a brakout
    // point is actually reached.
    while (complexAbsolute(start) < BREAK_OUT && steps < MAX_STEPS) {
        start = complexMultiply(start, start);
        start = complexAdd(start, c);
        steps++;
    }
    return steps;
}

// Fill a grid of TILE_SIZE by TILE_SIZE pixels, with the number of
// steps each pixel took to escape the Mandelbrot set.
void escapeGrid(int grid[TILE_SIZE][TILE_SIZE], complex center, int z) {
    // Sets up the starting location and the variables that are needed
    // in order to start at the right location.
    int column;
    double scale;
    int row = 0;
    scale = 1 / (power(2, z));
    double scaledLength;
    scaledLength = scale * (TILE_SIZE);
    double realCenter;
    center.re = center.re - (scaledLength / 2);
    realCenter = center.re;
    center.im = center.im - (scaledLength / 2);
    // The nested loop that stores the number of steps within the array.
    // The while loop will call on scapeSteps in order to properly
    // fill the array.
    while (row < TILE_SIZE) {
        center.re = realCenter;
        column = 0;
        while (column < TILE_SIZE) {
            complex location = {center.re, center.im};
            grid[row][column] = escapeSteps(location);
            column++;
            center.re = center.re + scale;
        }
        row++;
        center.im = center.im + scale;
    }
}

// Add your own functions here.
// Remember to make them static.
static complex complexMultiply(complex a, complex b){
    // Does the necessary complex multiplication needed for escapSteps.
    complex value = {
        .re = (a.re * b.re) - (a.im * b.im),
        .im = (a.im * b.re) + (a.re * b.im)
    };
    return value;
}
static complex complexAdd(complex a, complex b){
    // Does complex number addition needed for escapeSteps.
    complex value;
    value.re = a.re + b.re;
    value.im = a.im + b.im;

    return value;
}
static double complexAbsolute(complex c) {
    // Takes the absolute value, but will take the square of this, as
    // it follows similar logic to taking square-root. Instead,
    // the #define for BREAK_OUT is also squared.
    double ab = (c.re * c.re + c.im * c.im);
    return ab;
}
static double power (int base, int power) {
    // Set up the values to do the mathematics behind taking a value
    // to a certain power.
    int i = 0;
    double storedPower = 1;
    // Use a loop to continually multiply to the specified level that
    // is parsed into the program.
    while (i < power) {
        storedPower = storedPower * base;
        i++;
    }
    return storedPower;
}
