#include <iostream>
#include <vector>

using namespace std;

// Helper function for calculating the number of ways to make change
int makeChangeHelper(int total, vector<int>& denoms, int index) {
    int coin = denoms[index];
    
    // Base case: One denom left, check if remaining amount is a multiple of the coin
    if (index == denoms.size() - 1) {
        int remaining = total % coin;
        return remaining == 0 ? 1 : 0; // 1 way if remaining is 0, 0 ways otherwise
    }
    
    int ways = 0;
    
    // Iterate through possible amounts of the current coin
    for (int amount = 0; amount <= total; amount += coin) {
        // Recursively calculate ways for the remaining amount using next denoms
        ways += makeChangeHelper(total - amount, denoms, index + 1); 
    }
    
    return ways;
}

// Main function to calculate the number of ways to make change
int makeChange(int amount, vector<int>& denoms) {
    return makeChangeHelper(amount, denoms, 0);
}

int main() {
    int amount = 10;
    vector<int> denoms = {1, 2, 5}; // Example denominations
    
    int ways = makeChange(amount, denoms);
    cout << "Number of ways to make change: " << ways << endl;
    
    return 0;
}
