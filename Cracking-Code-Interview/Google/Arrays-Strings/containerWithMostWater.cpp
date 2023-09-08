#include <vector>
#include <algorithm>

using namespace std;

/*
    Two Pointer technique:
        1. init max to zero
        2. init left and right to both ends of array
        3. while left < right, loop
        4. calculate current area and update max area
        5. take decision regarding which pointer to move
        6. return the max area
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;  // Variable to store the maximum area
        
        int left = 0;  // Initialize the left pointer
        int right = height.size() - 1;  // Initialize the right pointer
        
        // Iterate using two-pointer approach until left pointer is less than right pointer
        while (left < right) {
            int width = right - left;  // Calculate the width between the two pointers
            
            // Calculate the area by multiplying the minimum height with the width
            maxarea = max(maxarea, min(height[left], height[right]) * width);
            
            // Move the pointer with the smaller height to potentially find a larger area
            if (height[left] <= height[right]) {
                left++;  // Move the left pointer to the right
            } else {
                right--;  // Move the right pointer to the left
            }
        }
        
        return maxarea;  // Return the maximum area found
    }
};
