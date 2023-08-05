/*
    Given an array of strings strs, group the anagrams together. 
    You can return the answer in any order.
    An Anagram is a word or phrase formed by rearranging the letters of a 
    different word or phrase, typically using all the original letters exactly once.

    Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

*/
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

    /*      SOLUTION 1: Categorize by sorted string
        Intuition: Two strings are anagrams if and only if their sorted strings are equal
        Algo: Maintain a mpa ans: {string -> List} where each key K is a sorted string, and
        each value is the list fo the strings from the initial input that when sorted is equal to K

        ex: "aet" : ["eat", "tea", "ate"]
        time: O(NKlogK), where N is the length of strs, and K is the maximum length of 
        a string in strs. The outer loop has complexity O(N)O(N)O(N) as we iterate through 
        each string. Then, we sort each string in O(Klog⁡K)O(K \log K)O(KlogK) time.

        space: O(NK), the total information content stored in ans.
        
    
    */
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};

        unordered_map<string, vector<string>> ans;
        for (const auto& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            ans[key].push_back(s);
        }

        vector<vector<string>> result;
        for (const auto& pair : ans) {
            result.push_back(pair.second);
        }

        return result;
    }
    /*
        OPTIMIZED SOLUTION: categorize by count
            - Key becomes how many letters in a string
                - Ex: "eat": a:1, e:1, t:1 (There are 26 letters since they are all in lower case)

    */
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // If the input vector is empty, return an empty vector of vectors
    if (strs.empty()) return {};

    // Create an unordered_map to store anagrams groups
    // The key will be a string representation of character counts in each word,
    // and the value will be a vector of words that have the same character counts.
    unordered_map<string, vector<string>> ans;

    // Iterate through each word in the input vector
    for (const string& s : strs) {
        // Create a vector of integers to count the occurrences of characters in the current word
        vector<int> count(26, 0);

        // Count the occurrences of each character in the current word
        for (char c : s) {
            count[c - 'a']++;
        }

        // Create a key string using '#' to separate each character count
        // For example, if the word is "eat", the key will be "#1#0#0#1#0#0...#0" (representing character counts)
        string key;
        for (int i = 0; i < 26; i++) {
            key += '#';
            key += to_string(count[i]);
        }

        // Add the current word to the corresponding anagram group in the unordered_map
        ans[key].push_back(s);
    }

    // Create a vector of vectors to store the final result of grouped anagrams
    vector<vector<string>> result;

    // Iterate through each pair in the unordered_map (key-value pairs)
    for (const auto& pair : ans) {
        // Add the vector of anagrams for each key to the result vector
        result.push_back(pair.second);
    }

    // Return the final result containing grouped anagrams
    return result;
}


