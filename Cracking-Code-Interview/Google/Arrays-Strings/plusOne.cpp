#include <vector>
using namespace std;

/*
    algo:
    loop thru if you get to the last elt, increment. if result = 10. set the current 
    digit to 0 if it's not the first number, add 1 to th number before. 
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();  // Get the number of digits in the vector
        
        // Loop through the digits in reverse order
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1)
                digits[i]++;  // Increment the last digit by 1
            
            // If the current digit becomes 10, handle the carry
            if(digits[i] == 10){
                digits[i] = 0;  // Set the current digit to 0
                
                // If it's not the leftmost digit, propagate the carry
                if(i != 0){
                    digits[i - 1]++;  // Increment the previous digit
                } else {
                    digits[i] = 1;    // Set the leftmost digit to 1
                    digits.push_back(0);  // Add a new digit '0' at the end
                }
            }
        }
        
        return digits;  // Return the updated vector
    }
};
