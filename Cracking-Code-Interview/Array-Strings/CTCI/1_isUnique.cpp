/*
    Implement an algorithm to determine if a string has all unique characters
    what if you cannot use additional data structure

    Algo: use fo extra data structure : assume ASCII char set (8 bits). The idea is to maintain
          a boolean array of characters. The 256 indices represent 256 chars. All the array elts
          are initially set to false. as we iterate over the string, set true at the index 
          equal to the int value of the character. if at any time, we encouter that the array
          value is already true, it means the character with that int value is repeated.
*/
#include <string>
using namespace std;

const int MAX_CHAR = 256;

bool isUnique(string str){
    if(str.length() > MAX_CHAR)
        return false;

    bool chars[MAX_CHAR] = {0};
    for(int i = 0; i < str.length(); i++){
        if(chars[int(str[i])] == true)
            return false;
        chars[int(str[i])] == true;
    }
    return true;
}