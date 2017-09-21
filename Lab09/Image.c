//ADT related code for Image ADT activity

#include <stdlib.h>
#include <stdio.h>
#include "Image.h"

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
    newImage->pixels[height][width];

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
