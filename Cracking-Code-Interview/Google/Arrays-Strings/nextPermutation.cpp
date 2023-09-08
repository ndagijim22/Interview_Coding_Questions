#include <vector>
#include <algorithm>

using namespace std;

/*
    Algo: start from the 2nd to last elt and find the 1st elt that breaks teh descending order
        find the elt that's bigger or equal to swap it with from the end of array.
        after swap, reverse remaining elts from the swapped elt(not included) 
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;  // Start from the second-to-last element
        
        // Find the first element that breaks the descending order
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        
        if (i >= 0) {
            int j = nums.size() - 1;
            
            // Find the element to swap with, ensuring the new number is just larger
            while (nums[j] <= nums[i]) {
                j--;
            }
            
            swap(nums[i], nums[j]);  // Swap the elements at indices i and j using std::swap
        }
        
        reverse(nums.begin() + i + 1, nums.end());  // Reverse the remaining part of the array
    }
};
