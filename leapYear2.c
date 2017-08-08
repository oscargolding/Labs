// This checks for leap years.
// Written by Oscar (z5160173) and Michaela (z5117328)
// 2017-08-08

#include <stdio.h>
#include <stdlib.h>

#define NOA 2
#define TRUE 1
#define FALSE 0

int isLeapYear (int year);

int main (int argc, char *argv[]) {

    int year;

    printf("Enter a year after 1582: ");
    scanf("%d", &year);

    if (isLeapYear (year) == 1){
        printf("%d is a leap year.\n", year);
    } else if (isLeapYear (year) == 0) {
        printf("%d is not a leap year.\n", year);
    } else {
        printf("%d is before 1582.\n", year);
    }
    return EXIT_SUCCESS;
}

int isLeapYear (int year) {
    int abyear = FALSE;
if (year < 1582) {
    abyear = NOA;
} else if (year % 400 == 0) {
    abyear = TRUE;
} else if (year % 100 == 0) {
    abyear = FALSE;
} else if (year % 4 == 0) {
    abyear = TRUE;
} else {
    abyear = FALSE;
}
return abyear;
}
