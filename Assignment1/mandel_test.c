#include "mandelbrot.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

void testEscapeSteps(void);

int main(void) {


    testEscapeSteps();


    return 0;
}

void testEscapeSteps(void) {
    complex a = {0, 0};
    assert(escapeSteps(a) == MAX_STEPS);
    complex b = {20, 0};
    assert(escapeSteps(b) == 1);
    complex d = {3, 0};
    assert(escapeSteps(d) == 1);
    complex g = {-3, 0};
    assert(escapeSteps(g) == 1);

    //double x = -SIZE;
    //double y = SIZE;
    complex c = {3, 4};

    //printf(" c = %lf\n", c);
    /* while (y > -SIZE) {
        x = -SIZE;
        complex c = {x, y};
        //printf("c = %lf %lf\n", c.re, c.im);
        while (x < SIZE) {
            complex c = {x, y};
            //printf("c = %lf %lf\n", c.re, c.im);
            if (escapeSteps(c) < MAX_STEPS) {
                printf(" ");
                //printf("Steps = %d\n", escapeSteps(c));
            } else {
                printf("*");
                //printf("Steps = %d\n", escapeSteps(c));
            }
            //printf("c = %lf %lf\n", c.re, c.im);

            x++;

        }
        y--;

    } */
    double row = 0;
    double column = 0;
    while (row < SIZE) {
        column = 0;
        complex c = {row, column};
        while (column < SIZE) {
            if (escapeSteps(c) == 1) {
                printf(" ");
            } else {
                printf("*");
            }
            column++;
        }
        printf("\n");
        row++;
    }


    /*
    double x, y;
    y = c.im;
    while (y > c.im){
        x = c.re;
        while (x < c.re) {
            if (escapeSteps(c) == 1) {
                printf(" ");
            } else {
                printf("*");
            }
            x++;
        }
        printf("\n");
        y--;
    }
    */
}
