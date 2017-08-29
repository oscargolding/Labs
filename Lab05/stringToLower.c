// convert a string to lowercase
// Created by
//  ... (z0000000)
//  ... (z0000000)
// Created on 2017-08-??
// Tutor's name (dayHH-lab)

#include <stdio.h>
#include <stdlib.h>

void stringToLower (char *buffer);

int main (int argc, char *argv[]) {
    /// THIS WON'T WORK!
    ///
    /// `str` only points to a string literal, which is stored in a
    /// read only section of the program.  If you attempt to modify
    /// it, your program will crash with a memory error (usually,
    /// SIGSEGV, the infamous "segmentation fault").
    //
    // char *str = "Hello!"
    // stringToLower (str)

    char str[] = "Seventeen...  SEVENTEEN, I SAY!";
    stringToLower (str);
    printf ("%s\n", str);

    return EXIT_SUCCESS;
}

// Takes a string in `buffer`, and lowercases it.
void stringToLower (char *buffer) {
    // Your code goes here!
    int i = 0;
    while (buffer[i] != '\0') {
        
        if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
        buffer[i] = buffer[i] + 32; 
        }
     i++;
    }i = 0;
}
