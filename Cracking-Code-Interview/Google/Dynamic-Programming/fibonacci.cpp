// C++ program for Fibonacci Series
// using Dynamic Programming
#include <iostream>
#include <vector>

using namespace std;

class GFG {

public:
	int fib(int n)
	{

		// Declare an array to store
		// Fibonacci numbers.
        vector<int> memo;
		int i;

		// 0th and 1st number of the
		// series are 0 and 1
        memo.push_back(0);
        memo.push_back(1);

		for (i = 2; i <= n; i++) {

			// Add the previous 2 numbers
			// in the series and store it
			memo[i] = memo[i - 1] + memo[i - 2];
		}
		return memo[n];
	}
};

// Driver code
int main()
{
	GFG g;
	int n = 5;
    cout << g.fib(n);
	return 0;
}

// This code is contributed by SoumikMondal
