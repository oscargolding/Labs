// Draw a 512x512 chessboard
// By ... (z0000000)
// Written on 2017-08-??
// Tutor (dayHH-lab)

// Remember to pipe the output of this program into a file
// $ ./chessboard > chessboard.bmp
// $ eog chessboard.bmp &

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BOARD_SIZE   512
#define SQUARE_SIZE  (512 / 8)

// For writing BMP
#define PIXEL_START 26
#define PIXEL_BYTES 3
#define PIXEL_ALIGN 4
#define PIXEL_BITS  24
#define HEADER_SIZE 12

typedef struct _pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

void drawChessboard(pixel pixels[BOARD_SIZE][BOARD_SIZE]);

// Write an image to output
void writeImage(int output, pixel pixels[BOARD_SIZE][BOARD_SIZE]);

int main(int argc, char *argv[]) {
    // Pixel 2-dimensional array
    // remember, it's pixels[y][x]
    pixel pixels[BOARD_SIZE][BOARD_SIZE];

    drawChessboard(pixels);

    // Write the image to output
    writeImage(STDOUT_FILENO, pixels);

    return EXIT_SUCCESS;
}

// Draws a chessboard
void drawChessboard(pixel pixels[BOARD_SIZE][BOARD_SIZE]) {

    // Complete this function
    //pixel color;
    //pixel white = {255, 255, 255};
    //pixel black = {0, 0, 0};

    //int i = 1;
    //int j = 1;
    int row = 0;
    int column = 0;
    while (row < BOARD_SIZE) {
        column = 0;
        while (column < BOARD_SIZE) {
            if (row < 64 && column < 64) {
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 128 && column < 64){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 192 && column < 64){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 256 && column < 64){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 320 && column < 64){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 384 && column < 64){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 448 && column < 64){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 512 && column < 64){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 64 && column < 128) {
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 128 && column < 128){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 192 && column < 128){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 256 && column < 128){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 320 && column < 128){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 384 && column < 128){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 448 && column < 128){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 512 && column < 128){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 64 && column < 192) {
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 128 && column < 192){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 192 && column < 192){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 256 && column < 192){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 320 && column < 192){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 384 && column < 192){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 448 && column < 192){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 512 && column < 192){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 64 && column < 256) {
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 128 && column < 256){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 192 && column < 256){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 256 && column < 256){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 320 && column < 256){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 384 && column < 256){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 448 && column < 256){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 512 && column < 256){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 64 && column < 320) {
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 128 && column < 320){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 192 && column < 320){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 256 && column < 320){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 320 && column < 320){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 384 && column < 320){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 448 && column < 320){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 512 && column < 320){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 64 && column < 384) {
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 128 && column < 384){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 192 && column < 384){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 256 && column < 384){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 320 && column < 384){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 384 && column < 384){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 448 && column < 384){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 512 && column < 384){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 64 && column < 448) {
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 128 && column < 448){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 192 && column < 448){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 256 && column < 448){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 320 && column < 448){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 384 && column < 448){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 448 && column < 448){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 512 && column < 448){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 64 && column < 512) {
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 128 && column < 512){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 192 && column < 512){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 256 && column < 512){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 320 && column < 512){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 384 && column < 512){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            } else if (row < 448 && column < 512){
                pixels[row][column].red = 255;
                pixels[row][column].green = 255;
                pixels[row][column].blue = 255;
            } else if (row < 512 && column < 512){
                pixels[row][column].red = 0;
                pixels[row][column].green = 0;
                pixels[row][column].blue = 0;
            }
            column++;
        }
        row++;
    }
}

// Writes the pixels as a BMP file using the specification from
// https://en.wikipedia.org/wiki/BMP_file_format
void writeImage(int output, pixel pixels[BOARD_SIZE][BOARD_SIZE]) {
    // Initial BM bytes
    write(output, "BM", 2);

    // File size
    int rowSize = BOARD_SIZE * PIXEL_BYTES;
    int rowPadding = 0;
    if (rowSize % PIXEL_ALIGN != 0) {
        // Padd pixel to align properly
        rowPadding = PIXEL_ALIGN - (rowSize % PIXEL_ALIGN);
        rowSize += rowPadding;
    }

    int fileSize = PIXEL_START + (rowSize * BOARD_SIZE);
    write(output, (char *)&fileSize, sizeof(fileSize));

    // 4 reserved bytes
    write(output, "\0\0\0\0", 4);

    // start of pixel data
    // pixels start immediately after header
    int pixelStart = PIXEL_START;
    write(output, (char *)&pixelStart, sizeof(pixelStart));

    // Size of header
    int headerSize = HEADER_SIZE;
    write(output, (char *)&headerSize, sizeof(headerSize));

    // Image width and height
    short size = BOARD_SIZE;
    write(output, (char *)&size, sizeof(size));
    write(output, (char *)&size, sizeof(size));

    // Number of image planes (1)
    short planes = 1;
    write(output, (char *)&planes, sizeof(planes));

    // Number of bits per pixel (24)
    short bitsPerPixel = PIXEL_BITS;
    write(output, (char *)&bitsPerPixel, sizeof(bitsPerPixel));

    // Write each of the pixels
    int padding = 0x01234567;
    int y = 0;
    while (y < BOARD_SIZE) {
        int x = 0;
        while (x < BOARD_SIZE) {
            // Write the blue, green, then red pixels
            pixel pixel = pixels[y][x];
            write(output, &(pixel.blue), sizeof(pixel.blue));
            write(output, &(pixel.green), sizeof(pixel.green));
            write(output, &(pixel.red), sizeof(pixel.red));
            x++;
        }

        // Write the row padding bytes
        write(output, (char *)&padding, rowPadding);
        y++;
    }
}
