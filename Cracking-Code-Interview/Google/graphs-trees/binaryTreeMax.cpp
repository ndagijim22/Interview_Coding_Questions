/*
        Solution: https://www.youtube.com/watch?v=Hr5cWUld4vU
    Algo:
        Main function
    1. init global var maxSum to INT_MIN
    2. call DFS function on root of tree
    3. Return the maxSum

        DFS function
    1. base case: if root == null, return 0
    2. Call DFS on left and right subtree
    3. if either is negative set it to zero
    4. update the max path sum by comparing it to the sum of left, right and root
    5. Return sum contributed by the subtree. This is the max of the two values
        a. root + gain from left
        b. root + gain from right
    
    time: O(n): each node is visited once and we perform constant time operation during the visit
    space: O(h): h is the heigh of the tree, this is for the recursive call stack
*/
#include <iostream>
#include <algorithm> // For max

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // Initialize the maximum sum with a very small value
        DFS(root, maxSum); // Start the depth-first search with the root node
        return maxSum; // Return the calculated maximum path sum
    }
    
    // Depth-First Search function to calculate the maximum path sum recursively
    int DFS(TreeNode* root, int& maxSum) {
        if (root == nullptr) {
            return 0; // Base case: if the node is null, the path sum is 0
        }
        
        // Calculate the maximum path sum for the left and right subtrees
        int left = DFS(root->left, maxSum);
        int right = DFS(root->right, maxSum);
 
        int leftMax = max(0, left); // Negative sums are ignored
        int rightMax = max(0, right); // Negative sums are ignored
        
        // Update the maximum sum if the current path sum is greater
        maxSum = max(maxSum, leftMax + rightMax + root->val);
        
        // Return the maximum of left and right paths plus the value of the current node
        return max(leftMax, rightMax) + root->val;
    }
};

