// A program that reads three numbers and sorts them.
// Written by Oscar (z5160173) and Michaela (z5117328).
// 2017-08-08

#include <stdio.h>
#include <stdlib.h>

void numbercomparison(int num1, int num2, int num3);

int main (int argc, char *argv[]) {

    int num1, num2, num3;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    numbercomparison(num1, num2, num3);
    return EXIT_SUCCESS;
}

void numbercomparison(int num1, int num2, int num3) {
    if (num1 < num2 && num2 < num3) {
        printf("%d\n%d\n%d\n", num1, num2, num3);
    } else if (num2 < num1 && num1 < num3) {
        printf("%d\n%d\n%d\n", num2, num1, num3);
    } else if (num3 < num2 && num2 < num1) {
        printf("%d\n%d\n%d\n", num3, num2, num1);
    } else if (num1 < num3 && num3 < num2) {
        printf("%d\n%d\n%d\n", num1, num3, num2);
    } else if (num2 < num3 && num3 < num1) {
        printf("%d\n%d\n%d\n", num2, num3, num1);
    } else if (num3 < num1 && num1 < num2) {
        printf("%d\n%d\n%d\n", num3, num1, num2);
    } else if (num1 < num3 && num3 == num2) {
        printf("%d\n%d\n%d\n", num1, num3, num3);
    } else if (num2 < num3 && num3 == num1) {
        printf("%d\n%d\n%d\n", num2, num3, num1);
    } else if (num3 < num1 && num1 == num2) {
        printf("%d\n%d\n%d\n", num3, num1, num2);
    } else if (num1 == num2 == num3) {
        printf("%d\n%d\n%d\n", num3, num1, num2);
    }
}
