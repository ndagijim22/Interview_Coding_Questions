#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix in CSR format
//More about this format: https://en.wikipedia.org/wiki/Sparse_matrix

typedef struct {
    int rows;               // Number of rows
    int cols;               // Number of columns
    int nnz;                // Number of non-zero elements
    int* values;            // Array to store non-zero values
    int* row_ptr;           // Row pointers
    int* col_indices;       // Column indices
} CSRMatrix;

// Function to create a CSR matrix from a 2D matrix of zeros and ones
CSRMatrix* createCSRMatrix(int** matrix, int rows, int cols) {
    CSRMatrix* csr = (CSRMatrix*)malloc(sizeof(CSRMatrix));
    if (csr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    csr->rows = rows;
    csr->cols = cols;
    csr->nnz = 0;

    // Count the number of non-zero elements to allocate memory
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                csr->nnz++;
            }
        }
    }

    // Allocate memory for CSR arrays
    csr->values = (int*)malloc(csr->nnz * sizeof(int));
    csr->row_ptr = (int*)malloc((rows + 1) * sizeof(int));
    csr->col_indices = (int*)malloc(csr->nnz * sizeof(int));

    if (csr->values == NULL || csr->row_ptr == NULL || csr->col_indices == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize CSR arrays
    int nnz_idx = 0;  // Initialize the non-zero index to 0.
    csr->row_ptr[0] = 0; // The first row always starts at index 0 in row_ptr.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                // If the current element in the matrix is non-zero:
                // 1. Store its value in the 'values' array.
                // 2. Store its column index in the 'col_indices' array.
                // 3. Increment nnz_idx to move to the next non-zero element.
                csr->values[nnz_idx] = matrix[i][j];
                csr->col_indices[nnz_idx] = j;
                nnz_idx++;
            }
        }
        // After processing a row, update row_ptr to indicate the starting index
        // of the next row in the 'values' and 'col_indices' arrays.
        csr->row_ptr[i + 1] = nnz_idx;
    }

    return csr;
}

// Function to free the memory of a CSR matrix
void freeCSRMatrix(CSRMatrix* csr) {
    free(csr->values);
    free(csr->row_ptr);
    free(csr->col_indices);
    free(csr);
}

int main() {
    int rows = 3;
    int cols = 3;
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // Initialize a sample matrix with zeros and ones
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = 0;
    matrix[1][2] = 1;
    matrix[2][0] = 0;
    matrix[2][1] = 1;
    matrix[2][2] = 0;

    // Create a CSR matrix from the 2D matrix
    CSRMatrix* csr = createCSRMatrix(matrix, rows, cols);

    // Free the memory of the CSR matrix
    freeCSRMatrix(csr);

    // Free the memory of the 2D matrix
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
