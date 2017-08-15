// Sum of many numbers. 
// Written by Michaela (z5117328) and Oscar (z5160173)
// 2017-08-15

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    int numsum;
    int count = 0;
    int sum = 0;
    int newnum;

    printf("How many numbers: ");
    scanf("%d", &numsum);
    while(count < numsum) {
        scanf("%d", &newnum);
        sum = sum + newnum;
        count++;
    }
    printf("%d\n", sum);

    return EXIT_SUCCESS;
}
