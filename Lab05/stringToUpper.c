// CONVERT A STRING TO UPPERCASE
// CREATED BY
//  ... (Z0000000)
//  ... (Z0000000)
// CREATED ON 2017-08-??
// TUTOR'S NAME (DAYHH-LAB)

#include <stdio.h>
#include <stdlib.h>

void stringToUpper (char *buffer);

int main (int argc, char *argv[]) {
    /// THIS WON'T WORK!
    ///
    /// `str` only points to a string literal, which is stored in a
    /// read only section of the program.  If you attempt to modify
    /// it, your program will crash with a memory error (usually,
    /// SIGSEGV, the infamous "segmentation fault").
    //
    // char *str = "Hello!"
    // stringToUpper (str)

    
    char str[] = "aAAA";
    stringToUpper (str);
    printf ("%s\n", str);

    return EXIT_SUCCESS;
}

// TAKES A STRING IN `buffer`, AND UPPERCASES IT.
void stringToUpper (char *buffer) {
    // YOUR CODE GOES HERE!
    int i = 0;
    while (buffer[i] != '\0') {
        
        if (buffer[i] >= 'a' && buffer[i] <= 'z') {
        buffer[i] = buffer[i] - 32;
     
        
        }
     i++;
    }i = 0;
}
