#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

//mask bits
uint8_t maskBits(uint8_t num){
    uint8_t mask = 0xF0; // 1111 0000
    uint8_t data = 0xAB; // 1010 1011
    return data & mask; // get rid of the 4 lower bits
}

//Set bits use OR bitwise
uint8_t setBits(uint8_t num){
    uint8_t data = 0x82; // 1000 0010
    uint8_t mask = 0x08; // 0000 1000 (sets the 4th bit)
    uint8_t res = data | mask;  //res = 0x8A: 1000 1010

    return num | mask;
}

//Clearing bits : use AND bitwise
uint8_t clearBits(uint8_t num){
    uint8_t mask = 0xF7; // 1111 0111 (clears the 4th bit)
    uint8_t data = 0x8A; // 1000 1010
    uint8_t res = data & mask; // res = 0b1000 0010, 0x82

    return num & data;
}

//toggling bits" use XOR bitwise
uint8_t toggleBits(uint8_t num){
    uint8_t data = 0x82; 
    uint8_t mask = 0x08;// 0b00001000 (toggles the 4th bit)
    uint8_t res = data ^ mask; // Result: 0x8A (Binary: 10001010)

    return num ^ mask;
}

//checking bit states: use AND bitwise
bool checkSetBit(uint8_t num){
    uint8_t data = 0x8A; // Binary: 10001010
    uint8_t mask = 0x08; // Binary: 00001000 (checks the 4th bit)
    bool isSet = (data & mask) != 0; //isSet is true

    return (num & mask) != 0;
}

//Bit shifting
uint8_t shiftBits(uint8_t num){
    uint8_t data = 0x0F; // 0000 1111
    uint8_t shiftedLeft = data << 2; //0b00111100: 0x3C
    uint8_t shiftedRight = data >> 1; //0000 0111: 0x07

    return shiftedLeft;
}

//Bit counting: use Brian kernighan Algorthm
int bitCounting(uint32_t num){
    int count = 0;
    while(num){
        num &= (num - 1);
        count++;
    }
    return count;
}


// Function to convert an integer to a binary string
//REVIEW THIS!!!
const char* intToBinary(uint8_t n) {
    static char binaryString[9]; // 8 bits + null-terminator
    for (int i = 7; i >= 0; i--) {
        binaryString[7 - i] = ((n >> i) & 1) ? '1' : '0';
    }
    binaryString[8] = '\0'; // Null-terminate the string
    return binaryString;
}

int main(){
    //
    uint8_t num = 0x0f;
    printf("Hex: %x\n", setBits(num));
    
    return 0;
}