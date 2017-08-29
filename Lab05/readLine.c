// Read a line of input.
// Created by
//  ... (z0000000)
//  ... (z0000000)
// Created on 2017-08-??
// Tutor's name (dayHH-lab)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LENGTH 64

void readLine (int bufferLen, char *buffer);

int main (int argc, char *argv[]) {
    // Declare a buffer.  In this case, we're declaring and using a
    // 64-byte buffer, but this could be any length you like, and in
    // our tests you will be required to handle arrays of any length.
    char buffer[BUFFER_LENGTH] = {0};

    // Read in a line...
    readLine (BUFFER_LENGTH, buffer);

    // ... and print it out.  The `%s` format code prints a string.
    printf ("<%s>\n", buffer);

    return EXIT_SUCCESS;
}

// Reads a line of input into `buffer`, excluding the newline;
// ensures that `buffer` is a null-terminated string.
void readLine (int bufferLen, char *buffer) {
    // Your code goes here!
    int i = 0;
    int temp;
    bufferLen = bufferLen - 1;
    while ((temp = getchar()) != EOF && temp != '\n'){
        if (i < bufferLen) {
            buffer[i] = temp;
            i = i + 1;
        }
    }


    return;
}
