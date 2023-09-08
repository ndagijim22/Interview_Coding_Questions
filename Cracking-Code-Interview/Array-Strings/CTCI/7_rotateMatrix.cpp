/*
    Rotate matrix: given an image represented by an NxN matrix, where each pixel
            in the image is represented by an integer, write a method to rotate the image
            by 90 degrees. Can you do this in place?
    Algo:
        - Perform a circular rotation on each layer, moving the top edge to the right edge
        the right edge to the bottom edge, the bottom edge to the left edge, and the left
        edge to the top edge
*/
#include <iostream>
#include <vector>

using namespace std;

// Function to rotate a matrix
bool rotate(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix.size() != matrix[0].size()) {
        return false; // Return false if the matrix is empty or not square
    }
    
    int n = matrix.size(); // Get the size of the matrix
    
    // Iterate through each layer from outer to inner
    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer; // Index of the first element in the layer
        int last = n - 1 - layer; // Index of the last element in the layer
        
        // Iterate through each element in the current layer
        for (int i = first; i < last; i++) {
            int offSet = i - first; // Offset from the first element
            
            int top = matrix[first][i]; // Save the top element
            
            // Move left element to top
            matrix[first][i] = matrix[last - offSet][first];
            
            // Move bottom element to left
            matrix[last - offSet][first] = matrix[last][last - offSet];
            
            // Move right element to bottom
            matrix[last][last - offSet] = matrix[i][last];
            
            // Move saved top element to right
            matrix[i][last] = top;
        }
    }
    return true; // Return true to indicate successful rotation
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    bool rotated = rotate(matrix);

    if (rotated) {
        cout << "Matrix rotated successfully:" << endl;
        for (const auto& row : matrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Matrix rotation failed due to invalid dimensions." << endl;
    }

    return 0;
}

