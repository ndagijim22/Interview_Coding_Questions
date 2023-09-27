#include <iostream>

using namespace std;

int bitwise_add(int a , int b){
    //iterate until there is no carry left. (b becomes 0)
    while(b != 0){
        //calculate the carry
        int carry = a & b;
        //do the addition w/0 the carry
        a = a ^ b;
        //left shift the carry by 1 pos, to prepare it for the next iteration
        b = carry << 1;
    }
    //return the result of addition
    return a;
}

int main(){
    int sum = bitwise_add(100, 2);
    cout << "Sum is: " << sum << endl;

    return 0;
}