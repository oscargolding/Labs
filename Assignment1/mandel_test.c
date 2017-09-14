#include "mandelbrot.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define SIZE 3
#define TERMINAL_WIDTH 80
#define TERMINAL_HEIGHT 72
#define MAX_ITERATIONS 256

#define DRAWING_ZOOM 5

void testEscapeSteps(void);
static void pixelCalc (complex c);
static void printAsterix (void);
static double power(int base, int power);

int main(void) {


    testEscapeSteps();
    //printAsterix ();
    int grid[TILE_SIZE][TILE_SIZE];
    complex center = {5, 5};
    //printf("%f %f", center.im, center.re);
    //escapeGrid(grid, center, 8);



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


    complex lv = {-1.5000000000000, -1.5000000000000};
    assert (escapeSteps (lv) == 1);

    complex lt = {0.3565670610700, 0.1094322227625};
    assert (escapeSteps (lt) == 224);



   printf (" ... escapeSteps tests passed!\n");
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
    /*double i = 0;
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
    }  */

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

   /*complex c = {0, 0};
   int row = c.re;
   int col = c.im;
   while (row <= 255) {
      col = 0;
      printf("\n");
      while (col <= 255) {
         if (escapeSteps (c) != MAX_STEPS) {
            printf("*");
         } else {
            printf(" ");
         }
         col++;
      }
      row++;
   }*/
   int column;
   int row;
   double scaleX, scaleY;
   double scale;
   scale = 1 / power(2, DRAWING_ZOOM);
   row = TILE_SIZE;
   while (row > -TILE_SIZE) {
       column = -TILE_SIZE;
            while (column < TILE_SIZE) {
               // centering
               scaleX = -(TILE_SIZE / 2) * scale;
               scaleY = -(TILE_SIZE / 2) * scale;
               // calculate current point
               scaleX = scaleX + (column * scale);
               scaleY = scaleY + (row * scale);
               //printf("%d, %d\n", column, row);
               //printf("%lf, %lf\n", scaleX, scaleY);
               complex c = {scaleX, scaleY};
               if (escapeSteps(c) == MAX_STEPS) {
                   printf("*");
               } else {
                   printf(" ");
               }

               column++;
           }
           printf("\n");
           row--;

       }
}
static void printAsterix (void) {
   int row = 0;
   int col = 0;
   complex c = {row, col};
   while (row <= 255) {
      col = 0;
      printf("\n");
      while (col <= 255) {
         if (escapeSteps (c) >= 4) {
            printf("*");
         } else {
            printf(" ");
         }
         col++;
      }
      row++;
   }
}
static double power (int base, int power) {
    int i = 0;
    double calcResult = 1;
    while (i < power) {
        calcResult *= base;
        i++;
    }
    return calcResult;
}
