/*
* Test if a point is inside a triangle.
* Julian Saknussemm
* Edited by Michaela (z5117328) and Oscar (z5160173)
* Edited on 2017-08-08
* Given Three points of a triangle, and another arbitrary point this program
* determines if that point lies inside
* the triangle.
*
* This is determined by satisfying the following rule:
* A point P(x,y) is inside triangle A(x0,y0), B(x1,y1), C(x2,y2)
* iff
* P is on the same side of the line AB as C
* P is on the same side of the line BC as A
* and
* P is on the same side of the line AC as B
*
* A special case exits for a vertical line (inf gradient) when testing the side
*  of the line
*/

#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int test1(double px, double py, double m, double b, double lx, double ly);
int test2(double px, double py, double m, double b);
int test3(double x0, double y0, double x1, double y1, double x2, double y2,
    double px, double py);
int test4(double x0, double y0, double x1, double y1, double x2, double y2,
    double px, double py);
int test5(double x0, double y0, double x1, double y1, double x2, double y2,
    double px, double py);
// Above is the list of testing functions for given points.

int main (int argc, char* argv[]) {

    double x0,y0,x1,y1,x2,y2,px,py;


    // get input
    printf("Triangle Vertex A (x,y): ");
    scanf("%lf %lf", &x0, &y0);

    printf("Triangle Vertex B (x,y): ");
    scanf("%lf %lf", &x1, &y1);

    printf("Triangle Vertex C (x,y): ");
    scanf("%lf %lf", &x2, &y2);

    printf("Test Point (x,y): ");
    scanf("%lf %lf", &px, &py);

    // print error
    if (test4(x0, y0, x1, y1, x2, y2, px, py)) {
        printf("Failed numbers, not mathematically possible.\n");
        return EXIT_FAILURE;
    }
    if (test5(x0, y0, x1, y1, x2, y2, px, py)) {
        printf("Failed numbers, not mathematically possible.\n");
        return EXIT_FAILURE;
    }
    // Removed the old error in favour of two new functions (4 + 5).

    // print answer
    printf("Point (%.2lf,%.2lf) is ", px, py);
    if (test3(x0,y0,x1,y1,x2,y2,px,py)) {
    printf("inside");
    } else {
    printf("outside");
    }
    printf(" the Triangle.\n");

    // return EXIT_SUCCESS if it's all good.
    return EXIT_SUCCESS;
}
int test1(double px, double py, double m,double b, double lx, double ly) {
    return (test2(px, py, m, b) == test2(lx, ly, m, b));
}
int test2(double px, double py, double m, double b) {
    if(py < m * px + b) {
        return -1; // point is under line
    } else if (py == m * px + b){
        return 0;
    } else {
        return 1; // over
    }
}
int test3(double x0,double y0,double x1,double y1,double x2,double y2,
    double px, double py) {
    int line1, line2, line3;
// line eqns
    double m01 = (y1 - y0)/(x1 - x0);
// b: y - y1 = m( x - x1 ), x = 0
    double b01 = m01 * -x1 + y1;
    double m02, m12, b02, b12;
    m02 = (y2-y0)/(x2-x0);
    m12 = (y2-y1)/(x2-x1);
    b02 = m02 * -x2 + y2;
    b12 = m12 * -x2 + y2;
// vertical line checks
    if(x1 == x0) {
        line1 = ((px <= x0) == (x2 <= x0));
    } else {
        line1 = test1(px, py, m01, b01, x2, y2);
    } if(x1 == x2) {
        line2 = ((px <= x2) == (x0 <= x2));
    } else {
        line2 = test1(px,py, m12, b12,x0,y0);
    } if(x2 == x0) {
        line3 = ((px <= x0) == (x1 <= x0));
        } else {
        line3 = test1(px, py, m02, b02, x1, y1);
    }
    return line1 && line2 && line3;
}
int test4(double x0, double y0, double x1, double y1, double x2, double y2,
    double px, double py) {
    int FAIL = FALSE;
    if (x0 == x1 || x0 == x2 || x1 == x2) {
        FAIL = TRUE;
    } else if (x0 == x1 == x2) {
        FAIL = TRUE;
    } return FAIL;
} // Test for x values being the same, making the maths impossible.
int test5(double x0, double y0, double x1, double y1, double x2, double y2,
    double px, double py) {
    int FAIL = FALSE;
    if (y0 == y1 || y2 == y1 || y0 == y2) {
        FAIL = TRUE;
    } else if (y0 == y1 == y2) {
        FAIL = TRUE;
    } return FAIL;
} // Test for the y values being the same, making the maths impossible.
