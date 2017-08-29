// gnirtS a esreveR
// Created by
//  ... (z0000000)
//  ... (z0000000)
// Created on 2017-08-??
// Tutor's name (dayHH-lab)

#include <stdio.h>
#include <stdlib.h>

void stringReverse (char *buffer);

int main (int argc, char *argv[]) {
    /// THIS WON'T WORK!
    ///
    /// `str` only points to a string literal, which is stored in a
    /// read only section of the program.  If you attempt to modify
    /// it, your program will crash with a memory error (usually,
    /// SIGSEGV, the infamous "segmentation fault").
    //
    // char *str = "Hello!"
    // stringReverse (str)

    char str[] = ".'neetneves' :egassem terces A";
    stringReverse (str);
    printf ("%s\n", str);

    return EXIT_SUCCESS;
}

// Takes a string in `buffer`, and reverses it in-place.
void stringReverse (char *buffer) {
    // Your code goes here!
    char *end = buffer;
    char temp;
    while (*end) {
        end++;
    }
    end--;
    while (buffer < end) {
    temp = *buffer;
    *buffer++ = *end;
    *end-- = temp;
    }
}
