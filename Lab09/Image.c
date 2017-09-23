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
        int startX = centre.x - i->width / 2;
        int startY = centre.y - i->height / 2;
        while (startY < i->height) {
            startX = centre.x - i->width / 2;
            while (startX < i->width) {
                double distance = sqrt((double)(startY-radius)*
                (startY-radius)+(startX-radius)*(startX-radius));
                if (distance > radius - 0.5 && distance < radius + 0.5) {
                    i->pixels[startY][startX] = color;
                }
                startX++;
            }
            startY++;
        }
}
void imageDrawLine (Image i, pixel color, point start, point end) {

    dx = (end.x - start.x);
    dy = (end.y - start.y);
    int steps;
    if (absolute(dx) > absolute(dy)) {
        steps = absolute(dx);
    } else {
        steps = absolute(dy);
    }
    int p = 2 * dy - dx;
    int x = start.x;
    int y = start.y;
    int startX = start.x - i->width / 2;
    int startY = start.y - i->height / 2;
    while (startY < i->height) {
        startX = start.x - i->width / 2;
        while (startX < i->width) {
            if (p > 0) {
                i->pixels[startY][startX] = color;
                y = y + 1;
                p = p + 2 * dy - 2 * dx;
            } else {
                p = p + 2 * dy;
            }
            startX++;
        }
        startY++;
    }
}
