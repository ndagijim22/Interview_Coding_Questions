#include <iostream>

using namespace std;

class MyClass{
    public:
        void fun(int x){
            cout << "value of x is " << x << endl;
        }
        void fun(double x){
            cout << "value of x is " << x << endl;
        }

        void fun(int x, int y){
            cout << "value of x and y is " << x << ", " << y << endl;
        }
};

int main(){
    MyClass test;
    test.fun(4);
    test.fun(78.32);
    test.fun(89, 90);
    
    return 0;
}