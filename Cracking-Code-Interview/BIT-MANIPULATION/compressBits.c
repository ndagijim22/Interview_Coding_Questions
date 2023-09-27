#include <stdio.h>

// Define the size of the matrix
#define ROWS 4
#define COLS 8

// Function to compress binary bits using Run-Length Encoding (RLE)
void compressBinaryMatrix(int matrix[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        int currentBit = matrix[row][0];  // Initialize with the first bit in the row
        int count = 1;

        for (int col = 1; col < COLS; col++) {
            if (matrix[row][col] == currentBit) {
                count++;
            } else {
                // Print the compressed data (bit and count)
                printf("%d %d ", currentBit, count);

                // Reset count and update currentBit
                count = 1;
                currentBit = matrix[row][col];
            }
        }

        // Print the last compressed data for the row
        printf("%d %d\n", currentBit, count);
    }
}

int main() {
    // Example binary matrix (4x8)
    int binaryMatrix[ROWS][COLS] = {
        {1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0}
    };

    printf("Original Binary Matrix:\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%d ", binaryMatrix[row][col]);
        }
        printf("\n");
    }

    printf("\nCompressed Binary Matrix:\n");
    compressBinaryMatrix(binaryMatrix);

    return 0;
}
