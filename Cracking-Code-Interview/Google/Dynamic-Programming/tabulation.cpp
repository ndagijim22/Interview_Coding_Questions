#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the nth Fibonacci number using dynamic programming (bottom-up approach)
int fibonacci(int n) {
	if (n == 0) {
		return 0; // Base case: Fibonacci(0) is 0
	} else if (n == 1) {
		return 1; // Base case: Fibonacci(1) is 1
	} else {
		// Create a vector to store Fibonacci values up to n
		vector<int> table(n + 1, 0);
		table[0] = 0; // Base case: Fibonacci(0) is 0
		table[1] = 1; // Base case: Fibonacci(1) is 1
		
		// Fill in the table using a bottom-up approach
		for (int i = 2; i <= n; i++) {
			table[i] = table[i-1] + table[i-2]; // Calculate Fibonacci(i) using previous values
		}
		
		return table[n]; // Return the calculated Fibonacci number for n
	}
}
