/*
    write a program to swap odd and even bits in an integer with as few instruction as possible
    eg: bit 0 and bit 1 are swapped, bit 2 and 3 are swapped and so on
*/
#include "bitutils.cpp"
#include <iostream>

using namespace std;

int swapOddEvenBit(int x){
     // Mask to extract even bits (0xaaaaaaaa represents alternating 1s and 0s in binary)
     // Mask to extract odd bits (0x55555555 represents alternating 0s and 1s in binary)
    return (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
}

int main(){
    int myBit = swapOddEvenBit(10);
    cout << bits<decltype(myBit), 8>(myBit) << endl;

    return 0;
}