/*
    Triple Step: a child is runing up a staircase with n steps and can hop either 1 step, 
    2 steps, or 3 steps at a time. Implement a method to count how many possible ways 
    the child can run up the stairs

    Algo: recursion, top down. since there are overlapping problems. we use memoization 
    to reduce time complexity from exponential to linear
*/
#include <unordered_map>

using namespace std;

//Brute Force
//Time complexity: O(3^n)since each call branches out to three more calls
int countWays(int n){
    //base case
    if(n < 0){
        return 0;
    } else if(n == 0){
        return 1;
    } else{
        return countWays(n - 3) + countWays(n - 2) + countWays(n - 3);
    }
}

//Optimized solution using memoization
//time complexity: O(n)
//Basic idea: if we've seen the value of n before, we return it. Otherwise we compute
// a fresh value and cache it.
int countWays(int n){
    unordered_map <int, int> memo(n + 1, -1);
    return countWaysUtil(n, memo);
}
int countWaysUtil(int n, unordered_map <int, int>& memo){
    if(memo.find(n) != memo.end()){
        return memo[n];
    }
    //base case
    if(n < 0){
        return 0;
    } else if(n == 0){
        return 1;
    } 
    else if(memo[n] > -1){
        return memo[n];
    }
    else{
        memo[n] = countWaysUtil(n - 3, memo) + countWaysUtil(n - 2, memo) + countWaysUtil(n - 3, memo);
    }
    return memo[n];
}

