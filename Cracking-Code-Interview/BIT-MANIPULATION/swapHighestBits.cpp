/*
    write a function that swaps the highest bits in each nibble of the byte
    ex: 0bAxxxBxxx ==> 0bBxxxAxxx
*/
#include <cstdint>
#include <iostream>
#include "bitutils.cpp"

using namespace std;

// uint8_t swapBits(uint8_t n){
//     //extract the bits
//     uint8_t bitA = n >> 7;
//     uint8_t bitB = (n & (1 << 3)) >> 3;

//     //shift them in their pos
//     bitA = bitA << 3;
//     bitB = bitB << 7;

//     //update the bits
//     uint8_t mask = n & 0x77; //clear the bits

//     return mask | bitA | bitB;

// }
uint8_t swapBits(uint8_t n, int i, int j){
    // Extract the values of the bits at positions 'i' and 'j' by shifting 'n' 
    // and using bitwise AND
   uint8_t bitA = (n >> i) & 1;
   uint8_t bitB = (n >> j) & 1;

    //check if the two bits are different
   if(bitA != bitB){
    // Swap the bits by flipping them using XOR (^) with masks (1 << i) and (1 << j).
        //   - Toggle the bit at position 'i' to its opposite value.
        //   - Toggle the bit at position 'j' to its opposite value.
        n ^= 1 << i;
        n ^= 1 << j;
   }
   //return the updated int
   return n;
}

int main(){
    uint8_t myBit = swapBits(0b11110000, 0, 6);
    cout << bits<decltype(myBit), 8>(myBit) << endl;

    return 0;
}