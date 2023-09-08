#include <vector>
using namespace std;

/*
    algo: Keep track of the lower_bound. compare that to the current elt in array
        if not equal add lower_bound as first elt in range and the current elt - 1
        after this check. update the lower-bound to current elt + 1
        after this check the upper bound  as well. if there left-bound is <= to upper
        add both as a range.
*/
class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> res;  // Create a vector to store missing ranges
        int left_bound = lower;    // Initialize the left bound with the lower limit
        
        // Loop through the 'nums' vector
        for (int i = 0; i < nums.size(); i++) {
            if (left_bound != nums[i])
            // Add a missing range from left_bound to nums[i] - 1
                res.push_back({left_bound, nums[i] - 1});  
            
            // Update the left bound to the next value
            left_bound = nums[i] + 1;  
        }
        
        // Check if there's a missing range between the last number and 'upper'
        if (left_bound <= upper)
        // Add the missing range from left_bound to 'upper'
            res.push_back({left_bound, upper});  
        
        return res;  // Return the vector containing missing ranges
    }
};
