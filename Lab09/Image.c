//ADT related code for Image ADT activity

#include <stdlib.h>
#include <stdio.h>
#include "Image.h"
#include <err.h>
#include <math.h>

typedef struct _image{
    unsigned int height;
    unsigned int width;
    pixel **pixels;
}image;


// Given a width and a height, creates a new `Image`.
Image newImage (unsigned int width, unsigned int height){
    Image newImage = calloc(1,sizeof(image));

    newImage->height = height;
    newImage->width = width;

    newImage->pixels = calloc(height, sizeof(pixel*));

    int i = 0;
    while (i < height){
        newImage->pixels[i] = calloc(width, sizeof(pixel));
        i++;
    }

    if(newImage->pixels == NULL){
        err(EXIT_FAILURE,"COULDNT ALLOCATE PIXEL MEMORY");
    }
    //newImage->pixels[height][width];

    pixel defaultPixel = {0x7D,0x7C,0x7B};
    //Now set all of the pixels to be default color.
    int row = 0;
    int col = 0;
    while (row < height){
        col = 0;
        while (col < width){
            newImage->pixels[row][col] = defaultPixel;
            col ++;
        }
        row++;
    }


    return newImage;
}

// Release all resources associated with an `Image`.
void destroyImage (Image i){
    free(i);
}


// Given an image, get the image's width.
unsigned int imageGetWidth (Image i){
    return i->width;
}


// Given an image, get the image's height.
unsigned int imageGetHeight (Image i){
    return i->height;
}

// Given an image, and a particular point, get that point's value.
pixel imageGetPixel (Image i, point p){
    pixel tempPixel;
    unsigned int x = p.x;
    unsigned int y = p.y;
    tempPixel = i->pixels[y][x];

    return tempPixel;
}

// Given an image, and a particular point and a pixel, set that
// point's value to the pixel passed in.
void imageSetPixel (Image i, point p, pixel color){
    pixel tempPixel;
    unsigned int x = p.x;
    unsigned int y = p.y;
    tempPixel = i->pixels[y][x];
    unsigned char red = color.red;
    unsigned char green = color.green;
    unsigned char blue = color.blue;

    pixel newPixel;
    newPixel.red = red;
    newPixel.green = green;
    newPixel.blue = blue;

    //now set the pixel in the array to be this new pixel
    i->pixels[y][x] = newPixel;
}
void imageDrawCircle (
    Image i, pixel color, point centre, unsigned int radius) {
        // Takes the bottom left of generate Image i, and increments
        // using circle arithmetic.
        // If the point lies on the diameter of the circle, it will
        // be coloured in.
        int startX = 0;
        int startY = 0;
        int d, a;
        while (startY < i->height) {
            startX = 0;
            while (startX <i->width) {
                a = ((startY - centre.y)*(startY - centre.y) +
                    (startX - centre.x)*(startX - centre.x));
                d = sqrt(a);
                if (radius == d || radius > abs(d)) {
                    i->pixels[startY][startX] = color;
                }
                startX++;
            }
            startY++;
        }
}
void imageDrawLine (Image i, pixel color, point start, point end) {
    // Using arithmetic logic from the Wiki for Bresenham.
    // Determines whether a point actually lies on a line using
    // an equation. If so, colour these specific points.
    double dx = (end.x - start.x);
    double dy = (end.y - start.y);
    double b = start.y - ((dy/dx) * start.x);
    double d = 2 * dy - dx;
    int startX = 0;
    int startY = 0;
    while (startY < i->height) {
        startX = 0;
        while (startX < i->width) {
            if (dy*startX + (-dx * startY) + (dx * b) == 0) {
                startX = (int)startX;
                startY = (int)startY;
                if (startX <= end.x && startY <= end.y &&
                    startX >= start.x && startY >= start.y) {
                    i->pixels[startY][startX] = color;
                }
            }
            startX++;
        }
        startY++;
    }
}
