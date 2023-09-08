#include <iostream>

using namespace std;

int fact(int n){
    //base case
    if(n == 1)
        return 1;
    else
        return n * fact(n-1);
}

// An example of tail recursive function

static void print(int n){
	if (n <= 0)
		return;
	cout << " " << n;

	// The last executed statement is recursive call
	print(n-1);
}

void printFun(int test)
{
    if (test < 1)
        return;
    else {
        cout << test << " ";
        printFun(test - 1); // statement 2
        cout << test << " ";
        return;
    }
}


int main(){
    cout << fact(5) << endl;
    print(5);
    cout << endl;
}