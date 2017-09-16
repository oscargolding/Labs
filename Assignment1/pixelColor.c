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
        .red = 2 - steps ,
        .green = steps  - steps * steps / 4 + steps * steps * steps / 8
            - steps * steps * steps * steps / 25,
        .blue = 25 - steps + steps * steps - steps * steps * steps
            + steps * steps * steps * steps
            
            /*or for purple stuff 
        .red = steps * steps  + steps  + 62,
        .green = steps * 2 + 7,
        .blue = steps * steps  - steps + 70
        */
    };
    // COMPLETE THIS FUNCTION
    return color;
}
