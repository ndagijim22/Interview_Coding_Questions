#include <iostream>

using namespace std;
/*
    write a function to determine the number fo bits you would need to flip to convert integer
    A to integer B
*/
// int bitSwapRequired(int a, int b){
//     int numBits = 0;

//     while(a != 0){
//         //extract the last bits
//         int bitA = a & 1;
//         int bitB = b & 1;

//         //compare them
//         if(bitA != bitB)
//             numBits++;
        
//         //move to the next bit
//         a >>= 1;
//         b >>= 1;
//     }
//     return numBits;
// }

// BOOK ANSWER
// This function calculates the number of bits that need to be swapped
// in order to convert integer 'a' to integer 'b'.

int bitSwapRequired(int a, int b) {
    // Initialize a counter to keep track of the number of bit differences.
    int count = 0;
    
    // Calculate the bitwise XOR of 'a' and 'b'. 
    // This will result in a number where each set bit represents a difference between 
    //'a' and 'b'.
    int c = a ^ b;

    // Use a loop to count the set bits in 'c', which represent the differing bits 
    //between 'a' and 'b'.
    while (c != 0) {
        // Check the least significant bit of 'c' and add it to the count if it's set.
        count += c & 1;
        
        // Right shift 'c' by 1 bit to process the next bit.
        c >>= 1;
    }

    // Return the count, which represents the number of bit swaps required to convert 
    //'a' to 'b'.
    return count;
}

int main(){
    int a = 7;
    int b = 0;
    cout << bitSwapRequired(a, b) << endl;

    return 0;
}