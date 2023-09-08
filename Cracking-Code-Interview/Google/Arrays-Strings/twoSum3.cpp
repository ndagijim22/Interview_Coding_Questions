
#include <vector>

using namespace std;
/*
    Algo: Two pointer Technique: sort the array first. set left ptr to i + 1, and right ptr
                                    to arr.size()-1. the target will be -arr[i]. if sum of
                                    elt @ left and right ptr < target move left prt otherwise
                                    move right ptr. skip the duplicate
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;  // Vector to store resulting triplets
        
        // Sort the input array in ascending order
        sort(nums.begin(), nums.end());
        
        // Iterate through the array until the last two elements
        for (int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicates for the current number
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int target = -nums[i];  // Calculate the target for the two-pointer approach
            int left = i + 1;       // Initialize the left pointer to the next element
            int right = nums.size() - 1;  // Initialize the right pointer to the last element
            
            // Use two-pointer approach to find pairs that sum up to the target
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum < target) {
                    left++;  // Move the left pointer to the right
                } else if (sum > target) {
                    right--;  // Move the right pointer to the left
                } else {
                    // Found a triplet that sums up to zero
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for both left and right pointers
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    
                    // Move both pointers inward
                    left++;
                    right--;
                }
            }
        }
        
        return res;  // Return the resulting triplets
    }
};
