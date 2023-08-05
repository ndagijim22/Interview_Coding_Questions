/*
    Given an array nums containing n distinct numbers in the range [0, n], return
    the only number in the range that is missing from the array

    Ex: Input: nums = [3,0,1]
    Output: 2
    Explanation: n = 2 since there are 3 numbers, so all numbers are in the range [0,3]. 
    2 is the missing number in the range since it does not appear in nums.

    Intuition:
    a brute force solutin: check for the presence of each number that is expected to be there
    The naive implementation: use a linear scan of the array to check for containment.
    But we can use a HashSet to get constant time containment queries and overal linear runtime
    
    Algorithm: 
    This algo. is identical to brute force approach, except we first insert each element of nums
    into a set, allowing us to later query for containment in O(1) time

    time: O(n): set allows for O(1) to check for presence, 
                main loop runs in O(n)
    space: O(n): to store n elements

*/
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Create an unordered_set to store unique numbers from the input vector
        unordered_set<int> numSet; 

        for (int num : nums) {
            // Insert each number from the input vector into the set
            numSet.insert(num); 
        }
        // Calculate the expected total count of numbers (including the missing one)
        int expectedNumCount = nums.size() + 1; 

        for (int number = 0; number < expectedNumCount; number++) {
            // Check if the current number is not found in the set (meaning it is missing)
            if (numSet.find(number) == numSet.end()) {
                return number; // Return the missing number
            }
        }
        // If no missing number is found, return -1 
        //(this should never happen in a valid scenario)
        return -1; 
    }
};
