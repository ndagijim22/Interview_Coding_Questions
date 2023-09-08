#include <vector>

using namespace std;
/*
    Algo: Loop thru matrix unit i < (n+1)/2 (adding 1 for odd num of rows). 
         On each layer do a four-way rotation. a temp variable is used to store 
         variable as you change them for in-place
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Iterate through each layer of the matrix
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                // Perform the 4-way rotation
                int temp = matrix[n - 1 - j][i];  // Store the top-left element

                // Move values from right to top
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];

                // Move values from bottom to right
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];

                // Move values from left to bottom
                matrix[j][n - 1 - i] = matrix[i][j];

                // Move stored top-left element to left
                matrix[i][j] = temp;
            }
        }
    }
};
