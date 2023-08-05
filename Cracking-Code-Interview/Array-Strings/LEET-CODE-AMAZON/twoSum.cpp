/*
    Given an array of integers nums and an integer target, return indices of the two 
    numbers such that they add up to target. You may assume that each input would have 
    exactly one solution, and you may not use the same element twice.
    You can return the answer in any order.
*/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

//brute force solution
// Time complexity: 0(n^2), for each elt will thru the array to find its compliment
// Space complexity: O(1), it does not depend on array given
vector<int> twoSum(vector<int>& nums, int target){
    int i, j;
    vector<int> res;
    for(i = 0; i < nums.size(); i++){
        for(j = i + 1; j < nums.size(); j++){
            if(nums[j] == target - nums[i]){
                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    return res;
}

//optimal solution
/*
    Algo: It turns out we can do it in one-pass. While we are iterating and 
    inserting elements into the hash table, we also look back to check 
    if current element's complement already exists in the hash table. 
    If it exists, we have found a solution and return the indices immediately.

    Time complexity: O(n), we traverse vector of n elts once. each lookup in table 
    is O(1)
    Space complexity: O(n), we stored at most n elts on the hash table
*/
vector<int> twoSum(vector<int>& nums, int target){
   unordered_map<int, int> map;
   for(int i = 0; i < nums.size(); i++){
    int complement = target - nums[i];
    
    if(map.find(complement) != map.end()){
        return {map[complement], i};
    }
    map[nums[i]] = i;
   }
   //if no solution return empyt vector
   return {};

}
