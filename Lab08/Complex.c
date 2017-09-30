// COMP1511 17s2 -- Complex ADT
// Created by: Oscar Golding (z5160173)
//             ... (z0000000)
// Created on: 2017-09-??
// Tutorial:   dayHH-lab

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Complex.h"

typedef struct _complex {
    double re;
    double im;
} complex;

// Create a new `Complex` number from two `double`s.
Complex newComplex (double re, double im) {
    // Add your code here.
    // Memory allocation for calloc.
    complex *new = calloc (1, sizeof(complex));
    // Error message if memory allocation has not been successful.
    // Introducing new syntax such as fprintf and exit function.
    if (new == NULL) {
        fprintf(stderr, "Failed\n");
        exit(EXIT_FAILURE);
    }
    // Takes the parsed in values from the prototype and assigns
    // them to the new complex number that was created.
    new->re = re;
    new->im = im;
    return new;
}

// Release all resources associated with a `Complex` number.
void destroyComplex (Complex c) {
    // Add your code here.
    // Use the new destructor function called "free"/
    free(c);
}

// Retrieve the real part of the `Complex` number.
double complexRe (Complex c) {
    // Add your code here.
    return c->re;
}

// Retrieve the imaginary part of the `Complex` number.
double complexIm (Complex c) {
    // Add your code here.
    return c->im;
}

// Add two `Complex` numbers together.
Complex complexAdd (Complex w, Complex z) {
    // Add your code here.
    // Have to do some more assigning for this to work. So create
    // new memory that only has a lifetime within this function.
    double tempNewReal = w->re + z->re;
    double tempNewImag = w->im + z->im;
    // Have to create a new complex number for this to work.
    Complex newAdd = newComplex (tempNewReal, tempNewImag);
    // Return this new complex.
    return newAdd;
}

// Multiply two `Complex` numbers together.
Complex complexMultiply (Complex w, Complex z) {
    // Add your code here.
    // Set up the respective values. This again involves temporary
    // assignment of variables.
    double tempNewReal = (w->re * z->re) - (w->im * z->im);
    double tempNewImag = (w->im * z->re) + (w->re * z->im);
    // Create a new complex number again.
    Complex newMult = newComplex (tempNewReal, tempNewImag);
    // Return this new Complex number that was made.
    return newMult;
}

// Take the magnitude (or modulus, or absolute) of a `Complex` number.
double complexMod (Complex w) {
    // Add your code here.
    // Sets up a variable, and then access the parts of the ADT to
    // change its parts.
    double mod = sqrt((w->re * w->re + w->im * w->im));
    return mod;
}

// Take the argument (or angle) of a `Complex` number.
double complexArg (Complex w) {
    // Add your code here.
    // Access the real and imaginary parts that are needed.
    double imagValue = w->im;
    double realValue = w->re;
    // Work out the inverse of this in order to calculate the argument
    // of a complex number.
    double arcTan = atan2 (imagValue, realValue);
    // Return the inverse using the new math.h function atan.
    return arcTan;
}
