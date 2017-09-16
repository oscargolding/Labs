// Assignment 1 Mandelbrot: Pixel Color
//
// Completed by
//  Michaela (z5117328)
//  Jack (z5162832)
//  Oscar (z5160173)
// Modified on 2017-16-09
// Tutor's name (dayHH-lab)
// Alex Hinds (Tuesday 9-12)

#include "mandelbrot.h"
#include "pixelColor.h"

// This function should take a number (of steps taken to escape the
// Mandelbrot set), and convert it to a color.
//
// You have artistic licence here, so make your Mandelbrot look amazing.
pixel pixelColor(int steps) {
    pixel color = {
        .red = steps,
        .green = steps,
        .blue = steps
    };
    // COMPLETE THIS FUNCTION
    return color;
}
