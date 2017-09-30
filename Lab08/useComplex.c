// Test the complex functions made in the ADT interfrace Complex.c
// Written by Oscar Golding.

#include "Complex.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int main (int argc, char *argv[]) {

    printf("Starting the first test.\n");
    double expect = 0;
    Complex w = newComplex (expect, expect);
    assert (w != NULL);
    assert (complexRe (w) == expect);
    assert (complexIm (w) == expect);
    printf("Passed the first set of tests.\n");
    destroyComplex(w);

    printf("Starting the second set of tests.\n");
    double testR = 2;
    double testIm = 3;
    Complex testN = newComplex (testR, testIm);
    assert (testN != NULL);
    assert (complexRe (testN) == testR);
    assert (complexIm (testN) == testIm);
    double complexModT = complexMod(testN);
    double nearest = roundf(complexModT * 100) / 100;
    double nearestTwo = roundf(sqrt(13) * 100) / 100;
    assert (nearest == nearestTwo);
    double testArg = atan2(3, 2);
    double complexArgN = complexArg(testN);
    assert (complexArg(testN) == testArg);
    assert (complexRe (testN) == testR);
    assert (complexIm (testN) == testIm);
    printf("Passed the second round of tests.\n");

    printf("Starting the third set of tests.\n");
    Complex testAdd = newComplex (1, 2);
    assert (testAdd != NULL);
    assert (complexRe (testAdd) == 1);
    assert (complexIm (testAdd) == 2);
    Complex newAdd = complexAdd (testN, testAdd);
    assert (complexRe (newAdd) == 3);
    assert (complexIm (newAdd) == 5);
    printf("Passed the third set of tests.\n");

    printf("Starting the fourth set of tests.\n");
    Complex testMult = complexMultiply (newAdd, testAdd);
    assert (complexRe (testMult) == -7);
    assert (complexIm (testMult) == 11);
    printf("Passed the fourth set of tests.\n");

    printf("Starting the fifth set of tests.\n");
    Complex testDec = newComplex (1.321, -0.00021);
    assert (complexRe (testDec) == 1.321);
    assert (complexIm (testDec) == -0.00021);
    Complex testDecAdd = complexAdd (testMult, testDec);
    assert (complexRe (testDecAdd) == -5.679);
    assert (complexIm (testDecAdd) == 10.99979);
    Complex testDecMult = complexMultiply (testMult, testDec);
    nearest = roundf(complexRe(testDecMult) * 100) / 100;
    double nearestA = roundf(complexIm(testDecMult) * 100) / 100;
    printf("%lf %lf\n", nearest, nearestA);
    // Have to typecast to avoid these floating point errors. Note
    // when typecasting there is always a round down, so if the value
    // is 14.56 then it will get rounded down to 14.
    assert ((int)nearest == -9);
    assert ((int)nearestA == 14);
    assert ((int)complexMod (testDecMult) == 17);
    printf("Passed the fifth set of tests.\n");

    printf("Clearing memory procedure.\n");
    destroyComplex (testMult);
    destroyComplex (newAdd);
    destroyComplex (testN);
    destroyComplex (testAdd);
    destroyComplex (testDec);
    destroyComplex (testDecAdd);
    destroyComplex (testDecMult);
    printf("All the memory has been cleared.\n");

    return EXIT_SUCCESS;
}
