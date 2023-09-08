#include <iostream>
#include <unordered_map>

using namespace std;

// Function to calculate the nth Fibonacci number using memoization
int fibonacci(int n, unordered_map<int, int>& cache) {
	// Check if the value is already present in the cache
	if (cache.find(n) != cache.end()) {
		return cache[n]; // Return the cached value if found
	}
	
	int result;
	if (n == 0) {
		result = 0; // Base case: Fibonacci(0) is 0
	} else if (n == 1) {
		result = 1; // Base case: Fibonacci(1) is 1
	} else {
		// Recursive case: Calculate Fibonacci(n) using previously calculated values
		result = fibonacci(n-1, cache) + fibonacci(n-2, cache);
	}
	
	// Store the calculated value in the cache for future use
	cache[n] = result;
	
	return result; // Return the calculated Fibonacci number
}

