#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <vector>

using namespace std;
/*
    This function is used to check is a number is a power of 2. 
    if a number is a power of 2, it will have only one bit set to 1 in its binary 
    representation
*/
bool isPowerOfTwo(int n){
    //n > 0, checks if n is positive b/c negative nums cannot be powers of 2
    // n & (n - 1) == 0, this expression clears the lowest set bit of n and checks if
    // the results is equal to 0. if it's 0, then there was only one bit set in n indicating that 
    // it is a power of 2
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main(){
    vector<int> nums2 {1,2,3,4,5,6,7,8,9,10,16,32,64,128,256};
    vector<int> nums {1,2,4,8,16,32,64,128,256};

    for(int i = 0; i < nums.size(); i++ ){
        if(isPowerOfTwo(nums[i])){
            cout << nums[i] << " Power\n";
        } else {
            cout << nums[i] << " Not Power\n";
        }
    }

    return 0;
}