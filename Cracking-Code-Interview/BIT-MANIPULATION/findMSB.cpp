#include <iostream>

using namespace std;

int findMSB(int n){
    //This stores the value fo MSB
    int msb = 0;

    //Base case: if the input is zero, return 0
    if(n == 0)
        return 0;
    
    //use the loop to find the pos of MSB
    while(n > 1){
        //Right shift the number by 1 to check the next bit towards MSB
        n = n >> 1;
        //increment the MSB pos to keep track of the bit's location
        msb++;
    }
    //create a result integet with only the MSB bit set to 1
    //THis is achieved by left shifting 1 by the value of msb
    return 1 << msb; 
    
}

int main(){
    cout << findMSB(11) << endl;

    return 0;
}