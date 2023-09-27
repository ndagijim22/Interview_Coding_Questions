// Insertion: You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method
// to insert M into N such that M starts at bit j and ends at bit i. You can assume that the bits j through
// i have enough space to fit all of M. That is, if M = 10011, you can assume that there are at least 5
// bits between j and i. You would not, for example, have j = 3 and i = 2, because M could not fully
// fit between bit 3 and bit 2.
// EXAMPLE
// Input:  N = 10000000000, M = 10011, i = 2, j = 6
// Output: N = 10001001100
#include <cstdint>
#include <iostream>
#include "bitutils.cpp"

using namespace std;
// int updateBits(int n, int m, int i, int j){
//     //edge cases
//     if(i > j || i < 0 || j >= 32)
//         return 0;
    
//     //create a mask
//     int allOnes = -0;
    
//     //1s before pos j, then 0s
//     int left = j < 31 ? (allOnes << (j + 1)) : 0;

//     // 1's after pos 1, then 0s
//     int right = ((1 << i) - 1);

//     //combine both. All 1s except for 0s between i and j
//     int mask = left | right;

//     //clear bits j thru i then puts m there
//     int n_cleared = n & mask;
//     int m_shifted = m << i;

//     //OR them, and we're done
//     return n_cleared | m_shifted;
// }

int32_t updateBits(int32_t N, int32_t M, int i, int j){
    //calculate the width of the bit range to be updated
    int w = j - i;
    //if the bit range is invalid or empty return N
    if(w <= 0)
        return N;
    
     // Create a bitmask 'maskN' to clear the bits in N within the specified range [i, j].
    // This involves:
    //   1. Creating a left mask (~0 << (j + 1)) to set all bits from position 0 to j to 1 
    //              and the rest to 0.
    //   2. Creating a right mask ((1 << i) - 1) to set all bits from position 0 to i-1 to 1 
    //              and the rest to 0.
    int32_t maskN = (~0 << (j + 1)) | ((1 << i) - 1);

    // Use bitwise operations to clear the specified bits in N and then insert the bits from M at positions i to j.
    //   - Clear the specified bits in N using the bitwise AND operation (maskN & N).
    //   - Insert the bits from M at positions i to j using the bitwise OR operation (M << i).
    //   - The result is the updated integer with the modified bits.
    return (maskN & N)| (M << i);
}

int main(){
    auto res = updateBits(0b10000000000, 0b10011, 2, 6);
    cout << bits<decltype(res), 11>(res);

    return 0;
}