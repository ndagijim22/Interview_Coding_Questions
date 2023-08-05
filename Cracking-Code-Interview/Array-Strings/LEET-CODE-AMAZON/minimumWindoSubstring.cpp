/*
    Given two strings s and t of lengths m and n respectively, return the minimum window
    substring of s such that every character in t (including duplicates)is included in the window
    if there is no such substring, return the empty string ""

    Ex: input: S = "ABAACBAB" T = "ABC"
        output: "ACB"
    
    Algorithm: sliding window technique
    1. we start with 2 pointers left and right both starts at the beginning of string s
    2. We use the right ptr to expand the window unitl we get a desireable window
            i.e: a window that contains all fo the charaters fo T
    3. Once we have a window with all the chars, we can move the left ptr ahead one by one.
    if the window is still a desirable one we keep on updating the min window size
    4. if the window is not desirable any more, we repeat step 2 onwards
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // If the input vector is empty, return an empty vector of vectors
        if (strs.empty()) return {}; 
        // Create an unordered_map to store grouped anagrams
        unordered_map<string, vector<string>> ans; 

        for (const string& s : strs) {
            // Initialize a vector to count the occurrences of characters (a-z) in the current string
            vector<int> count(26, 0); 

            for (char c : s) {
                // Count the occurrences of each character in the current string
                count[c - 'a']++; 
            }
            // Initialize a key string to represent the unique key for the anagram group
            string key; 

            for (int i = 0; i < 26; i++) {
                key += '#'; // Add '#' as a separator for each character count
                // Append the count of the current character to the key string
                key += to_string(count[i]); 
            }
            // Add the current string to the appropriate anagram group based on the key
            ans[key].push_back(s); 
        }

        vector<vector<string>> result; // Initialize the final result vector of vectors

        for (const auto& pair : ans) {
            // Add each anagram group to the final result vector
            result.push_back(pair.second); 
        }

        return result; // Return the vector of grouped anagram vectors
    }
};

