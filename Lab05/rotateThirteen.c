// Perform the ROT13 algorithm on a string
// Completed by
//  ... (z0000000)
//  ... (z0000000)
// Commpleted on 2017-08-??
// Tutor's name (dayHH-lab)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE (!FALSE)
#define MAX_LENGTH 256

// Add your own #defines here

void rotateThirteen (char *string);
char rotateOne (char c);
int stringLength (char *string);
int stringsEqual (char *stringA, char *stringB);

// Add your own function porototypes here

int main (int argc, char *argv[]) {
    // Example tests
    char testA[MAX_LENGTH] = "Hello, world!";
    rotateThirteen (testA);
    assert (stringsEqual ("Uryyb, jbeyq!", testA));

    char testB[MAX_LENGTH] = "abcdefghijklmnopqrstuvwxyz";
    rotateThirteen (testB);
    assert (stringsEqual ("nopqrstuvwxyzabcdefghijklm", testB));

    char testC[MAX_LENGTH] = "The quick brown fox jumped over the lazy dog.";
    rotateThirteen (testC);
    assert (stringsEqual ("Gur dhvpx oebja sbk whzcrq bire gur ynml qbt.",
                          testC));

    // Add your own tests here

    printf ("All tests passed. You are awesome!\n");

    return EXIT_SUCCESS;
}

void rotateThirteen (char *string) {
    // YOUR CODE HERE
    
     
       /* You do this until you find a '\0' */
         int i = 0;
    while (string[i] != '\0') {
        if (string[i] >= 'a' && string[i] <= 'm') { 
        string[i] += 13;
        } else if (string[i] >= 'A' && string[i] <= 'M') { 
        string[i] += 13;
        } else if (string[i] >= 'n' && string[i] <= 'z') { 
        string[i] -= 13;
        } else if (string[i] >= 'N' && string[i] <= 'Z') { 
        string[i] -= 13;
        } i++;
    } 
    
    
    // See: https://en.wikipedia.org/wiki/ROT13
}

char rotateOne (char c) {
    // Use your code from the rotateOne warm up here
    if (c >= 'a' && c < 'z') {
        c = c + 1;
        return c;
    } else if (c == 'z') {
        c = c - 25;
        return c;
    } else if (c >= 'A' && c < 'Z') {
        c = c + 1;
        return c;
    } else if (c == 'Z') {
        c = c - 25;
        return c;
    } else {
        return c;
    }
}

int stringLength (char *string) {
    // Use your code from the stringLength activity here
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    // Don't forget to return your result.
    return i;
}

int stringsEqual (char *stringA, char *stringB) {
    // Use your code from the stringsEqual activity here
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
