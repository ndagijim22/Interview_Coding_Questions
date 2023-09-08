/*
    Power Set: Write a method to return all subsets of a set

    Algo: if you build one set and gets it's all subsets. When you want to find a subsets of 
    bigger sets. you add the different elt to all subsets of the smaller set and then
    combine both results.
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to generate all subsets of a given set
vector<vector<int>> getSubsets(vector<int>& set, int index) {
    vector<vector<int>> allsubsets;
    
    // Base case: Add an empty set
    if (set.size() == index) {
        allsubsets = vector<vector<int>>(1, vector<int>());
    } else {
        // Recursive case: Get subsets excluding the current element
        allsubsets = getSubsets(set, index + 1);
        
        // Include the current element in subsets
        int item = set[index];
        vector<vector<int>> moresubsets;
        for (vector<int>& subset : allsubsets) {
            vector<int> newsubset = subset;
            newsubset.push_back(item);
            moresubsets.push_back(newsubset);
        }
        
        // Add the newly generated subsets to the result
        allsubsets.insert(allsubsets.end(), moresubsets.begin(), moresubsets.end());
    }
    
    return allsubsets;
}

int main() {
    vector<int> set = {1, 2, 3};
    
    // Get all subsets of the given set
    vector<vector<int>> subsets = getSubsets(set, 0);
    
    // Print the generated subsets
    for (const vector<int>& subset : subsets) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
