#include <stdint.h>
#include <stdio.h>
    /* write a function that changes the order of bytes in a uint32_t
       in = 0x12345678
       out = 0x78563412
       */

// uint32_t change_byte_order(uint32_t in){
    
//     uint32_t mask = 0xFF;
//     uint32_t out = 0;
//     uint32_t lastByte = in & mask;
//     out = lastByte << 24; //0x780000000

//     mask = 0xFF00;
//     uint32_t out1 = 0;
//     lastByte = in & mask;
//     out1 = lastByte << 8; //0x005600000
//     uint32_t ans = out1 | out; //0x785600000

//     mask = 0xFF0000;
//     uint32_t out2 = 0;
//     lastByte = in & mask;
//     out2 = lastByte >> 8; //0x0003400
//     uint32_t ans1 = out2 | ans; //0x785634000

//     mask = 0xFF000000;
//     uint32_t out3 = 0;
//     lastByte = in & mask;
//     out3 = lastByte >> 24; //0x0000012
//     uint32_t ans2 = out3 | ans1; //0x785634000

//     return ans1;

// }
uint32_t change_byte_order(uint32_t in){
    uint32_t out = ((in >> 24) & 0xFF) //Move the first byte to the last
                    | ((in >> 8) & 0xFF00) // Move the second byte to the second last
                    | ((in << 8) & 0xFF0000) // Move the third byte to the second byte
                    | ((in << 24) & 0xFF000000); //Move the last byte to the first byte

    return out;
} 

int main() {
    uint32_t in = 0x12345678;
    uint32_t out = change_byte_order(in);
    
    printf("Original: 0x%08X\n", in);
    printf("Reversed: 0x%08X\n", out);
    
    return 0;
}