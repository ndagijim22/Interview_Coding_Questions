#include<iostream>
#include "bitutils.cpp"

using namespace std;

int swapNible(int x){
    // return ((x & 0xF0) >> 4 | (x & 0x0F) << 4);
    // return ( (x & 0x0F) << 4 | (x & 0xF0) >> 4 );
    return (x >> 4) | (x << 4);
}
int main(){
    int x = 100;
    cout << bits<decltype(x), 8>(x) << endl;
    int y = swapNible(x);
    cout << bits<decltype(y), 8>(y) << endl;
}