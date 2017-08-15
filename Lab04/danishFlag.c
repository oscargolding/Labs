// Danish Flag
// Written by Michaela (z5117328) and Oscar (z5160173)
// 2017-08-15

#include <stdio.h>
#include <stdlib.h>

int size (void);
void printflag (int flagsize, int height, int width, int rowcounter,
    int columncounter);

int main (int argc, char *argv[]) {

    int flagsize = size();
    int height = flagsize * 4;
    int width = flagsize * 9;
    int rowcounter = 0, columncounter = 0;

    printflag (flagsize, height, width, rowcounter, columncounter);

    return EXIT_SUCCESS;
}
int size (void) {
    int size;
    printf("Enter the flag size: ");
    scanf("%d", &size);
    return size;
}
void printflag (int flagsize, int height, int width, int rowcounter,
    int columncounter) {
        while(rowcounter <= width && columncounter <= height - 1) {
            if(columncounter == 2 * flagsize - 1 || columncounter == 2 * flagsize) {
                while(rowcounter < width) {
                printf(" ");
                rowcounter++;
                } if (rowcounter == width) {
                    printf("\n");
                    columncounter++;
                    rowcounter = 0;
                }
            } else {
                if(rowcounter == 3 * flagsize - 1 || rowcounter == 3 * flagsize) {
                    printf(" ");
                    rowcounter++;
                } else if (rowcounter < width) {
                    printf("#");
                    rowcounter++;
                } else if(rowcounter == width) {
                    printf("\n");
                    rowcounter = 0;
                    columncounter++;
                }
            }
        }
}
