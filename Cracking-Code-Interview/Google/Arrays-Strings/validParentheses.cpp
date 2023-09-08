#include <unordered_map>
#include <stack>
#include <string>

/*
    Algo: use a map to map a closing bracket(key) and open bracket(value)
    init a stack to help us remove the unmatching. if we see a closing bracket,
    check if there is an open bracket on the stack that matches if not return false
    if you see an open bracket add it to the stack
*/

using namespace std;

class Solution {
public:
    // Initialize hash map with mappings in the constructor.
    public:
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