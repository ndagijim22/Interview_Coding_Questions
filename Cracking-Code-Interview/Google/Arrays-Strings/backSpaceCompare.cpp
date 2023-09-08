#include <string>
#include <stack>
using namespace std;
/*
    Algo.: use two stacks for each string. While the string is '\0'
            add letter to the stack. if you see # remove the letter on top of 
            stack. Do this for both string then compare their size and their chars
            if not equal return false.
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ch;   // Create a stack to process string 's'
        stack<char> ch1;  // Create a stack to process string 't'
        
        int i = 0;
        // Process string 's'
        while(s[i] != '\0'){
            if(s[i] == '#' && ch.empty()){
                i++;
                continue;  // Skip if '#' encountered at the beginning or after backspacing
            }
            else if(s[i] == '#' && !ch.empty())
                ch.pop();  // Pop a character if '#' encountered
            else
                ch.push(s[i]);  // Push regular characters onto the stack
            i++;
        }
        
        i = 0;
        // Process string 't'
        while(t[i] != '\0'){
            if(t[i] == '#' && ch1.empty()){
                i++;
                continue;  // Skip if '#' encountered at the beginning or after backspacing
            }
            else if(t[i] == '#' && !ch1.empty())
                ch1.pop();  // Pop a character if '#' encountered
            else
                ch1.push(t[i]);  // Push regular characters onto the stack
            i++;
        }
        
        if(ch.size() != ch1.size())
            return false;  // If the processed stacks have different sizes, strings are not equal
        
        i = 0;
        // Compare the processed characters in the stacks
        while(i != ch.size()){
            if(ch.top() == ch1.top()){
                ch.pop();
                ch1.pop();
            }
            else
                return false;  // If characters at the top of the stacks are not equal, strings are not equal
        }      
        
        return true;  // If all characters match, strings are equal
    }
};
