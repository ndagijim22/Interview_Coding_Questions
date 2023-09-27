#include<iostream>

using namespace std;

int isEvenOrAdd(int a){
    return a & 1;
}

int main(){
    int a = 900;

    if(isEvenOrAdd(279)){
        cout << "The number is odd" << endl;
    } else{
        cout << "The number is even" << endl;
    }
    return 0;

}