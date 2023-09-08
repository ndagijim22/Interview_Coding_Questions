#include <vector>
#include <string>

using namespace std;
/*
    Algo: https://www.youtube.com/watch?v=1vZswirL8Y8
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int len1 = num1.size();
        int len2 = num2.size();

        vector<int> res(len1 + len2, 0);  // Initialize a vector to store the result
        reverse(num1.begin(), num1.end());  // Reverse num1 for easier digit access
        reverse(num2.begin(), num2.end());  // Reverse num2 for easier digit access

        // Perform multiplication
        for (int i1 = 0; i1 < len1; i1++) {
            for (int i2 = 0; i2 < len2; i2++) {
                int digit = (num1[i1] - '0') * (num2[i2] - '0');  // Convert characters to integers
                res[i1 + i2] += digit;
                res[i1 + i2 + 1] += res[i1 + i2] / 10;
                res[i1 + i2] %= 10;
            }
        }

        // Convert result to string
        int beg = 0;
        while (beg < res.size() && res[beg] == 0) {
            beg++;
        }

        string result = "";
        for (int i = res.size() - 1; i >= beg; i--) {
            result += to_string(res[i]);
        }

        return result;
    }
};