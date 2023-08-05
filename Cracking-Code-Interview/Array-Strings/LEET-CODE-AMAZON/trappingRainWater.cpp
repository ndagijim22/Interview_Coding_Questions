/*
    Given n non-negative integers representing an elevation map where the width
    of each bar is 1, compute how much water it can trap after raining

    Ex: 
    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
            In this case, 6 units of rain water (blue section) are being trapped.

BRUTE FORCE SOLUTION:
ALGORITHM:
- init ans = 0
- iterate the array from left to right:
    - init left_max = 0 and right_max = 0
    - iterate from the current element to the beginning of array updating:
        - left_max = max(left_max, height[j])
    - iterate from the current element to the end fo array updating:
        - right_max = max(right_max, height[j])
    - Add min(left_max, right_max) - height[i] to ans

Time: O(n^2): For each element of array we iterate the left and right parts
Space: O(1): extra space
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0; // Initialize the variable to store the trapped water amount
        int size = height.size(); // Get the size of the height vector

        for (int i = 1; i < size - 1; i++) {
            int left_max = 0, right_max = 0; // Initialize variables to store max heights on the left and right sides

            // Search the left part for max bar size
            for (int j = i; j >= 0; j--) {
                left_max = max(left_max, height[j]); // Update left_max with the maximum height found so far
            }

            // Search the right part for max bar size
            for (int j = i; j < size; j++) {
                right_max = max(right_max, height[j]); // Update right_max with the maximum height found so far
            }

            // Calculate the trapped water at the current index (i) and add it to the ans
            ans += min(left_max, right_max) - height[i];
        }

        return ans; // Return the total trapped water amount
    }
};

/*
    OPTIMAL SOLUTION: USING 2 POINTERS
    ALGO:
    - Init left ptr to 0 and right ptr to size - 1
    - while left < right, do:
        - if height[left] is smaller than height[right]
            - if height[left] >= left_max, update left_max
            - else add left-max - height[left] to ans
            - Add 1 to left
        - Else
            - if height[right] >= right_max, update right_max
            - else add right_max - height[right] to ans
            - substract 1 from right

*/
#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int left = 0; // Pointer to the left side of the height vector
        int right = height.size() - 1; // Pointer to the right side of the height vector
        int ans = 0; // Initialize the variable to store the trapped water amount
        int left_max = 0; // Initialize variable to store the maximum height on the left side
        int right_max = 0; // Initialize variable to store the maximum height on the right side

        while (left < right) {
            // If height at left pointer is less than the height at the right pointer
            if (height[left] < height[right]) {
                // If the height at the left pointer is greater than or equal to the left_max, update the left_max
                // Otherwise, calculate the trapped water between left_max and height at left pointer and add it to ans
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left; // Move the left pointer to the right
            }
            else {
                // If the height at the right pointer is greater than or equal to the right_max, update the right_max
                // Otherwise, calculate the trapped water between right_max and height at right pointer and add it to ans
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right; // Move the right pointer to the left
            }
        }

        return ans; // Return the total trapped water amount
    }
};

