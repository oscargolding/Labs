// Functions and types used to extract x,y,z values from a string
// containing a URL of the form:
// "http://almondbread.cse.unsw.edu.au/mandelbrot/2/5/3.14/-0.141/tile.bmp"
//
// By ... (z0000000)
//    ... (z0000000)
// Written on 2017-09-??
// Tutor (dayHH-lab)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "extract.h"

int main (int argc, char *argv[]) {

    char *message = "http://almondbread.cse.unsw.edu.au/mandelbrot/2/5/3.14/-0.141/tile.bmp";

    triordinate dat = extract (message);
    printf ("dat is (%f, %f, %d)\n", dat.x, dat.y, dat.z);
    myAtoD(&message[49]);
    myAtoD(&message[51]);
    myAtoD(&message[56]);

    assert (dat.z == 5);
    assert (dat.x == 3.14);
    assert (dat.y == -0.141);
    assert (dat.z == 5);


    return EXIT_SUCCESS;
}

triordinate extract (char *message){

    triordinate result;
    int i = 7;

    while (message[i] != '2') i++;


    result.z = myAtoL(&message[i]);

    i = i + 2;

    while(message[i] != '/') i++;

    result.x = myAtoD(&message[i]);

    i = i + 1;

    while(message[i] != '/') i++;

    result.y = myAtoD(&message[i]);

    return result;

}
double myAtoD (char *message) {
    int i = 1;
    double result = 0;
    double neg = 1;
    double power = 10;
    while (message[i] != '/' && message[i] != '.') {
        if (message[i] == '-') {
            neg = -1;
            i = 2;
        }
        result = 10 * result + (message[i] - '0');
        printf("First %f\n", result);
        i++;
    }
    if (message[i] == '.') {
        i = i + 1;
    }
    printf("%d\n", i);
    while (message[i] != '/') {
        result = result + ((message[i] - '0')/power);
        power = power * 10;
        i++;
        printf("Second %f\n", result);
    }
    result = result * neg;
    return result*1000/1000;

}
long myAtoL (char *message){
    int i = 2;
    long result = 0;
    while (message[i] != '/') {
        result = 10 * result + (message[i] - '0');
        i++;
    }
    return result;
}
