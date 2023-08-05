/*
    ALGO:
    - create a map to store each char and its frequency
    - loop thru one string incrementing frequency in the map
    - loop thru the other string decrementing frequency in the map
    - If all frequencies are zero, the two strings are anagram otherwise they are not

    Time: O(n)
    space: O(n)
*/
#include <string>
#include <unordered_map>

using namespace  std;

bool isAnagram(string s, string t){
    unordered_map<char, int> map;
    

    //count the frequency of characters in string s
    for(auto character: s){
        map[character]++;
    }

    //decrement the frequency of characters in string t
    for(auto character: t){
        map[character]--;
    }

    //check if any character has non-zero frequency
    for(auto character: map){
        if(character.second != 0){
            return false;
        }
    }

    return true;
}