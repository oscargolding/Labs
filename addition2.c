// Hexadecimal addition calculator only using positive integers.
// Written by Oscar (z5160173) and Michaela (z5117328)
// 2017-08-07

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    int num1;
    int num2;
    int sum;

    printf("Please enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;

    printf("%#04x + %#04x = %#04x\n", num1, num2, sum);
    return EXIT_SUCCESS;
}
