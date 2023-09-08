/*
    Algo: use Two pointer method. Have left ptr at the beginning and right ptr at the end
            find sum of the number at both ptrs if sum bigger than target, do right--
            otherwise left++
*/
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;  // Vector to store the resulting indices
        
        int left = 0;   // Initialize the left pointer
        int right = numbers.size() - 1;  // Initialize the right pointer
        
        // Loop while the left pointer is less than the right pointer
        while(left < right){
            int sum = numbers[left] + numbers[right];  // Calculate the sum of the two numbers
            
            // If the sum equals the target, found a valid pair
            if(sum == target){
                res.push_back(left + 1);   // Add 1 to convert from 0-based index to 1-based index
                res.push_back(right + 1);  // Same here
                return res;  // Return the resulting indices
            }
            // If the sum is less than the target, move the left pointer to the right
            else if(sum < target){
                left++;
            }
            // If the sum is greater than the target, move the right pointer to the left
            else {
                right--;
            }      
        }
        
        return res;  // Return the resulting indices (empty if no solution found)
    }
};
