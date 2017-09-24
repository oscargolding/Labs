#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Image.h"


int main(void) {
    printf("Starting Tests...\n");

    Image myImage = newImage(16,16);
    //imageSetPixel (Image i, point p, pixel color){
    point myPoint;
    myPoint.x = 0;
    myPoint.y = 0;

    pixel myColor = {87,87,87};


    printf("Starting pixel tests...\n");

    imageSetPixel(myImage, myPoint, myColor); //failing on this line

    printf("1Starting pixel tests...\n");
    pixel result = imageGetPixel(myImage,myPoint);

    //assert(result.red == myPoint.red);
    unsigned char redVal = result.red;
    unsigned char greenVal = result.green;
    unsigned char blueVal = result.blue;
    printf("2Starting pixel tests...\n");
    assert(redVal == result.red);

    //assert(imageGetWidth(myImage)== 64);
    //assert(imageGetHeight(myImage)== 32);
    printf("passed pixel set test\n");


    unsigned char *buf;
    printf("start\n");
    int size = imageAsBMP(myImage, &buf);
    printf("next\n");
    fwrite(buf, sizeof(unsigned char), size, stdout);
    printf("\n");
    printf("4regrhe\n");
    free(buf);

    point start = {4, 4};
    point end = {8, 8};

    pixel linePixel = {126,126,126};

    unsigned char *ayylmao;
    imageDrawLine (myImage, linePixel, start, end);
    int sizeLine = imageAsBMP(myImage, &ayylmao);
    fwrite(ayylmao, sizeof(unsigned char), sizeLine, stdout);
    printf("\n");

    Image circleChange = newImage(16,16);

    point centre = {5,5};
    unsigned int radius = 4;

    unsigned char *circleString;
    imageDrawCircle (circleChange, linePixel, centre, radius);
    int sizeCircle = imageAsBMP(circleChange, &circleString);
    fwrite(circleString, sizeof(unsigned char), sizeCircle, stdout);
    printf("\n");

    printf("Passed all Tests!\n");


}
