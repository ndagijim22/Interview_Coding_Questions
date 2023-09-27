#include <iostream>

using namespace std;

int countSetBits(int n){
    //this keep counts of the set bits
    int count = 0;
    //continue to loop until n becomes 0
    while(n){
        //clear the least significant bit (the rightmost) using AND bitwise
        //this effectively reduces the count fo set bits by 1
        n = n & n - 1;
        //increment the count to keep track of the cleared set bit
        count++;
    }
    return count;
}

int main(){
    cout << countSetBits(100000000) << endl;

    return 0;
}