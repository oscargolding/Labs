// String Equality
// Created by
//  ... (z0000000)
//  ... (z0000000)
// Created on 2017-08-??
// Tutor's name (dayHH-lab)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (1 == 1)
#define FALSE (! TRUE)

int stringsEqual (char *stringA, char *stringB);

int main (int argc, char *argv[]) {
    // Some simple assert-based tests.
    // You probably want to write some more.
    assert (stringsEqual ("", "") == TRUE);
    assert (stringsEqual (" ", "") == FALSE);
    assert (stringsEqual ("", " ") == FALSE);
    assert (stringsEqual (" ", " ") == TRUE);
    assert (stringsEqual ("\n", "\n") == TRUE);
    assert (stringsEqual ("This is 17 bytes.", "") == FALSE);
    assert (stringsEqual ("", "This is 17 bytes.") == FALSE);
    assert (stringsEqual ("This is 17 bytes.", "This is 17 bytes.") == TRUE);
    assert (stringsEqual ("Here are 18 bytes!", "This is 17 bytes.") == FALSE);
    assert (stringsEqual ("\n", " ") == FALSE);

    printf ("All tests passed.  You are awesome!\n");

    return EXIT_SUCCESS;
}


// Takes two strings, and if they are the same,
// returns TRUE, or FALSE otherwise.
int stringsEqual (char *stringA, char *stringB) {
    // Your code goes here!
    int i = 0;
    while (stringA[i] == stringB[i] && stringA[i] != '\0') {
    i++;
} if (stringA[i] > stringB[i]) {
    return FALSE;
} else if (stringA[i] < stringB[i]) {
    return FALSE;
} else {
    return TRUE;
    }
}
