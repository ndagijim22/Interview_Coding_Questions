#include <unordered_map>
#include <string>

using namespace std;
/*
    Algo: use map to store frequency characters. This is used for our sliding window
            if a char is not in map move the right pointer to the right. if it is in 
            move the left pointer. As you do so keep track of the max length of each window
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> myMap;  // Map to store character frequencies

        int left = 0;  // Initialize the left pointer of the sliding window
        int right = 0; // Initialize the right pointer of the sliding window

        int res = 0;   // Initialize the maximum length of the substring

        // Traverse through the string using the right pointer
        while (right < s.length()) {
            char currChar = s[right];   // Current character at the right pointer
            myMap[currChar]++;          // Increment the frequency of the character in the map

            // Shrink the window by moving the left pointer until no repeating characters
            while (myMap[currChar] > 1) {
                char leftChar = s[left];  // Character at the left pointer
                myMap[leftChar]--;        // Decrement the frequency of the character in the map
                left++;            // Move the left pointer to the right
            }

            // Update the maximum length of the substring
            res = max(res, right - left + 1);

            right++;  // Move the right pointer to the right
        }

        return res;  // Return the maximum length of the non-repeating substring
    }
};
#include <vector>

using namespace std;

/*
    Algo: Greedy algo. loop thru array in reverse. keep lastPos var to keep track of 
            last reachable pos. if curr pos plus jump distance reach or surpass lastPos
            the lastPos is updated to the curr pos. when the lastPos = 0 then return true
            otherwise return false
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size() - 1;  // Last reachable position
        
        // Iterate through the array in reverse
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i;  // Update last reachable position
            }
        }
        
        return lastPos == 0;  // Check if the first element is reachable
    }
};
