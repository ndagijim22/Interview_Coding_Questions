/*
    Paths with Sum: you are given a binary tree in which each node contains an integer
    value (which might be positive or negative).Design an algorithm to count the number of 
    paths that sum to a given value. The path does not need to start or end at the root 
    or a leaf but it must go downwards (traveling only from parent nodes to child nodes)
*/
#include <iostream>
#include <unordered_map>

// TreeNode definition
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int countPathsWithSum(TreeNode* node, int targetSum, int runningSum,
                      std::unordered_map<int, int>& pathCount);

void incrementHashTable(std::unordered_map<int, int>& hashTable, int key, int delta);

int countPathsWithSum(TreeNode* node, int targetSum, int runningSum, 
                      std::unordered_map<int, int>& pathCount) {
    // base case
    if (node == nullptr) return 0;

    // count paths with sum ending at the current node
    runningSum += node->data;
    int sum = runningSum - targetSum;
    int totalPaths = pathCount[sum];

    // if runningSum equals targetSum, then one additional path starts at root.
    // Add in this path
    if (runningSum == targetSum) {
        totalPaths++;
    }

    // increment pathCount, recurse, then decrement pathCount
    incrementHashTable(pathCount, runningSum, 1); // increment pathCount
    totalPaths += countPathsWithSum(node->left, targetSum, runningSum, pathCount);
    totalPaths += countPathsWithSum(node->right, targetSum, runningSum, pathCount);
    incrementHashTable(pathCount, runningSum, -1); // decrement pathCount

    return totalPaths;
}

void incrementHashTable(std::unordered_map<int, int>& hashTable, int key, int delta) {
    int newcount = hashTable[key] + delta;
    // remove when zero to reduce space
    if (newcount == 0) {
        hashTable.erase(key);
    } else {
        hashTable[key] = newcount;
    }
}

// Example usage:
int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(1);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->right->right = new TreeNode(11);

    std::unordered_map<int, int> pathCount;
    int targetSum = 8;
    int runningSum = 0;

    int result = countPathsWithSum(root, targetSum, runningSum, pathCount);
    std::cout << "Total paths with sum " << targetSum << ": " << result << std::endl;

    // Clean up the dynamically allocated memory (Don't forget to deallocate the tree)
    delete root->left->left->right;
    delete root->left->left->left;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
