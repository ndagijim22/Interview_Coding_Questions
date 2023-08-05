/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
    determine if the input string is valid

    an input string is valid if:
        1. open brackets must be closed by the same type of brackets
        2. open brackets must be closed in the correct order
        3. Every close bracket has a corresponding open bracket of the same type.

    Ex: input: s = "()"         
        Output: true
    
    Ex2: Input: s = "()[]{}"
         Output: true

    Algo:
    1. init a stack S
    2. process each bracket of the expression one at a time
    3. if we encounter an opening bracket, we simply push it into the stack.
        this means we will process it later, let us move onto the sub expression ahead
    4. if we encouter a closing bracket, then we check the element on top of the stack. 
        if teh element at the top of the stack is an opening bracket of the same type,
        then we pop it off the stack adn continue processing. Else this implies
            an invalid expression
    5. In the end, if we are left with a stack still having elements, then this implies an invalid
        expression.

    time: O(n)
    space: O(n)
*/
#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

class Solution {
private:
    // Hash table that takes care of the mappings.
    unordered_map<char, char> mappings;

public:
    // Initialize hash map with mappings in the constructor.
    private:
        unordered_map<char, char> mappings = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

    bool isValid(string s) {
        // Initialize a stack to be used in the algorithm.
        stack<char> stack;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            // If the current character is a closing bracket.
            if (this->mappings.find(c) != this->mappings.end()) {

                // Get the top element of the stack. If the stack is empty, set a dummy value of '#'.
                char topElement = stack.empty() ? '#' : stack.top();

                // If the mapping for this bracket doesn't match the stack's top element, return false.
                if (topElement != this->mappings[c]) {
                    return false;
                }

                // Remove the matched opening bracket from the stack.
                stack.pop();
            } else {
                // If it is an opening bracket, push it to the stack.
                stack.push(c);
            }
        }

        // If the stack still contains elements, then it is an invalid expression.
        return stack.empty();
    }
};

