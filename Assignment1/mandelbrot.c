#include "mandelbrot.h"
#include <assert.h>
#include <stdio.h>

#define SIZE 3

void testEscapeSteps(void);
static void pixelCalc (complex c);

int main(void) {


    testEscapeSteps();
    

    return 0;
}

void testEscapeSteps(void) {
    
    complex a = {0, 0};
    assert(escapeSteps(a) == MAX_STEPS);
    
    complex z = {-0.34, -0.0059};
    assert(escapeSteps(z) == MAX_STEPS);
    
    complex b = {20, 0};
    assert(escapeSteps(b) == 1);
    
    complex d = {3, 0};
    assert(escapeSteps(d) == 1);
    
    complex g = {-3, 0};
    assert(escapeSteps(g) == 1);
    
    complex h = {20, 20};
    assert(escapeSteps(h) == 1);
    
    complex lm = {-0.11, -0.74};
    assert(escapeSteps(lm) == MAX_STEPS);		
    //double x = -SIZE;
    //double y = SIZE;
    //complex c = {x, y};
    
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
    double i = 0;
    double j = 0;
    while (i < SIZE) {
        j = 0;
        complex c = {i, j};
        while (j < SIZE) {
            if (escapeSteps(c) == MAX_STEPS) {
                printf("*");
            } else {
                printf(" ");
            }   
            j = j + 0.1;  
        } 
        printf("\n");
        i = i + 0.1;
    }   
    
    /*complex c = {0, 0};
    double x, y;
    y = c.im;
    while (y > c.im - 2) {
        x = c.re;
        while (x < c.re + 3) {
            pixelCalc(c);
            x++;
        }
        printf("\n");
        y--;
    }*/
}
static void pixelCalc (complex c) {
    if (escapeSteps(c) < MAX_STEPS) {
        printf(" ");
    } else {
        printf("*");
    }
}

