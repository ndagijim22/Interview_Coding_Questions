#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;  // Pointers for left and right boundaries
        int ans = 0;  // Variable to store the total trapped water
        int left_max = 0, right_max = 0;  // Variables to track the maximum heights encountered

        // Loop until the left and right pointers meet or cross
        while (left < right) {
            // Compare heights at left and right pointers
            if (height[left] < height[right]) {
                // If height at left pointer is less, process left side
                // Check if current height is greater than or equal to the left maximum
                if (height[left] >= left_max) {
                    left_max = height[left];  // Update left maximum
                } else {
                    ans += (left_max - height[left]);  // Add trapped water to the answer
                }
                ++left;  // Move the left pointer towards the right
            } else {
                // If height at right pointer is less or equal, process right side
                // Check if current height is greater than or equal to the right maximum
                if (height[right] >= right_max) {
                    right_max = height[right];  // Update right maximum
                } else {
                    ans += (right_max - height[right]);  // Add trapped water to the answer
                }
                --right;  // Move the right pointer towards the left
            }
        }
        return ans;  // Return the total trapped water
    }
};
