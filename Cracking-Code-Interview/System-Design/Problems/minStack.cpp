/*
        DESIGN A MIN STACK
    - Design a stack that supports push, pop, top, and retrieving the minimum element 
        in constant time.
    - Implement the MinStack class:
        1. MinStack() initializes the stack object.
        2. void push(int val) pushes the element val onto the stack.
        3. void pop() removes the element on the top of the stack.
        4. int top() gets the top element of the stack.
        5. int getMin() retrieves the minimum element in the stack.
    - You must implement a solution with O(1) time complexity for each function

        ALGORITHM
    - Use the stack features to implement this
    - the trick here is to keep the min value on the top of the stack. 
    - Every time you push, you compare the min already on the top of the stack
        is less then it become the min value
    
    Time: O(1) for all operations
    Space: O(n) n is the number of elements
*/
#include <stack>
#include <algorithm> // For the min function

using namespace std;

class MinStack {
private:
    stack<pair<int, int>> stack; // Stack to hold pairs of (element, current_min)

public:
    MinStack() { }
    // Push an element onto the stack
    void push(int value) {
        if (stack.empty()) {
            // If the stack is empty, set the current min as value
            stack.push({value, value});
            return;
        }
        
        // Get the current minimum from the top of the stack
        int currentMin = stack.top().second;
        // Push a pair containing the element and the minimum of value and current min
        stack.push({value, min(value, currentMin)});
    }
    
    // Pop the top element from the stack
    void pop() {
        stack.pop();
    }
    
    // Get the top element from the stack
    int top() {
        return stack.top().first;
    }
    
    // Get the minimum element in the stack
    int getMin() {
        return stack.top().second;
    }
};
