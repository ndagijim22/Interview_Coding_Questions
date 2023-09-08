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

