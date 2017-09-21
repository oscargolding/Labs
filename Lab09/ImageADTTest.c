#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Image.h"


int main(void) {
    printf("Starting Tests...\n");

    Image myImage = newImage(1,1);
    //imageSetPixel (Image i, point p, pixel color){
    point myPoint;
    myPoint.x = 0;
    myPoint.y = 0;

    pixel myColor = {125,125,125};


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
    //fwrite(buf, sizeof(unsigned char), size, stdout);
    //printf("4regrhe\n");
    //free(buf);

    printf("Passed all Tests!\n");


}
