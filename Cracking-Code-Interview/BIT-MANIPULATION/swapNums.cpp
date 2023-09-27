#include <iostream>

using namespace std;

void swapNums(int& a, int& b){
    //Step 1: swap 'a' nd 'b' using XOR to store the result in 'a'
    //'a' now contains the XOR of the original 'a' nd 'b'
    a = a ^ b;
    
    //Step 2: swap 'a' nd 'b' using XOR to store the result in 'b'
    //'b' now contains the original value of 'a'
    b = a ^ b;

    //Step 3: swap 'a' nd 'b' using XOR to store the result in 'a'
    //'a' now contains the original value of 'b'
    a = a ^ b;
}

int main(){
    int a = 900;
    int b = 300;
    cout << "a = " << a << " b = " << b << endl;

    swapNums(a, b);
    cout << "After swap" << endl;
    cout << "a = " << a << " b = " << b << endl;
    return 0;
}