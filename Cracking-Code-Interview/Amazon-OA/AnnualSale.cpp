/*
    LINK: https://leetcode.com/discuss/interview-experience/1470686/amazon-online-assessment
    Follow link for description of the problem
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<int> find_valid_codes(const vector<string>& discounts) {
    vector<int> output;

    for (const string& discount : discounts) {
        if (discount.empty()) {
            output.push_back(1);
        } else if (discount.length() % 2 != 0) {
            output.push_back(0);
        } else {
            stack<char> charStack;
            for (char c : discount) {
                if (charStack.empty() || charStack.top() != c) {
                    charStack.push(c);
                } else {
                    charStack.pop();
                }
            }
            
            if (charStack.empty()) {
                output.push_back(1);
            } else {
                output.push_back(0);
            }
        }
    }

    return output;
}

int main() {
    // Example usage:
    vector<string> discounts = {""};
    vector<int> validCodes = find_valid_codes(discounts);

    cout << "Valid Codes: ";
    for (int code : validCodes) {
        cout << code << " ";
    }
    cout << endl;

    return 0;
}
