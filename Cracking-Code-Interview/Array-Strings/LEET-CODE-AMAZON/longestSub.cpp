/*
    Given a string s, find the length of the longest substring without repeating characters.
    Ex: 
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> chars; // Map to store characters and their counts

        int left = 0; // Left pointer of sliding window
        int right = 0; // Right pointer of sliding window

        int res = 0; // Variable to store the result

        // Iterate through the string using a sliding window approach
        while (right < s.length()) {
            char r = s[right]; // Character at the right pointer
            chars[r]++; // Increment the count of the character in the map

            // While the count of a character is greater than 1 (i.e., repeated)
            while (chars[r] > 1) {
                char l = s[left]; // Character at the left pointer
                chars[l]--; // Decrement the count of the character in the map
                left++; // Move the left pointer to the right
            }

            // Update the result with the maximum length of non-repeated substring
            res = max(res, right - left + 1);

            right++; // Move the right pointer to the right
        }

        return res; // Return the length of the longest substring without repeating characters
    }
};
