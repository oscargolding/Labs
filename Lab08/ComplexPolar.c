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
    double mod;
    double arg;
} complex;

static Complex newComplexModArg (double mod, double arg);

// Create a new `Complex` number from two `double`s.
Complex newComplex (double re, double im) {
    double mod = sqrt((re * re + im * im));
    double arcTan = atan2 (im, re);
    Complex new = newComplexModArg (mod, arcTan);
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
    double real = (c->mod)*cos(c->arg);
    return real;
}

// Retrieve the imaginary part of the `Complex` number.
double complexIm (Complex c) {
    // Add your code here.
    double imaginary = (c->mod)*sin(c->arg);
    return imaginary;
}

// Add two `Complex` numbers together.
Complex complexAdd (Complex w, Complex z) {
    // Add your code here.
    // There is no simple way to add two complex numbers together in
    // their respective polar forms, so there must be a transformation
    // back into cartesian form for this to work.
    double real = complexRe (w);
    double realQ = complexRe (z);
    double imag = complexIm (w);
    double imagQ = complexIm (z);

    double tempNewReal = real + realQ;
    double tempNewImag = imag + imagQ;
    // Have to create a new complex number for this to work.
    Complex newAdd = newComplex (tempNewReal, tempNewImag);
    // Return this new complex.
    return newAdd;
}

// Multiply two `Complex` numbers together.
Complex complexMultiply (Complex w, Complex z) {
    // Add your code here.
    // Multiplying in polar form is relatively simple using the
    // argument of complex numbers along with
    double tempNewMod = (w->mod * z->mod);
    double tempNewArg = (w->arg + z->arg);
    // Create a new complex number again.
    Complex newMult = newComplexModArg (tempNewMod, tempNewArg);
    // Return this new Complex number that was made.
    return newMult;
}

// Take the magnitude (or modulus, or absolute) of a `Complex` number.
double complexMod (Complex w) {
    // Add your code here.
    return w->mod;
}

// Take the argument (or angle) of a `Complex` number.
double complexArg (Complex w) {
    // Add your code here.
    return w->arg;
}
// takes z^x.
Complex complexExp (Complex z, double x) {
    return newComplexModArg (pow (z->mod, x), z->arg * x);
}
static Complex newComplexModArg (double mod, double arg) {
    complex *c = calloc (1, sizeof (complex));
    if (c == NULL) {
        printf ("Complex: couldn't allocate memory\n");
        exit (1);
    }
    c->mod = mod;
    c->arg = arg;
    return c;
}
