/*
    Check permutation: given two strings, write a method to decide if one is a permutation of the other

    Algo: 
    permutation: two words with the same character count
    - create an array that somehow operates like a hash table, mapping each character to its frequncy
    - increment through the first string
    - then decrement through the second stirng
    - if the two strings are permutation, then the array will be all zeroes at the end
*/
#include <iostream>

using namespace std;

bool permutation(string s, string t){
    if(s.length() != t.length())
        return false;
    
    int letters[128] = {0};
    for(int i = 0; i < s.length(); i++){
        letters[s[i]]++;
    }

    for(int i = 0; i < s.length(); i++){
        letters[t[i]]--;
        if(letters[t[i]] < 0){
            return false;
        }
    }

    return true;
}

