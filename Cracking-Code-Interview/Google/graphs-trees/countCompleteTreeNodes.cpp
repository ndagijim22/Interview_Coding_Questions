#include <iostream>
#include <cmath>

using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Find the height of the left subtree by traversing left nodes
    int findHeightLeft(TreeNode* root) {
        int count = 0;
        while (root) {
            count++;
            root = root->left;
        }
        return count;
    }

    // Find the height of the right subtree by traversing right nodes
    int findHeightRight(TreeNode* root) {
        int count = 0;
        while (root) {
            count++;
            root = root->right;
        }
        return count;
    }

    // Count the nodes in the binary tree
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        // Calculate the heights of the left and right subtrees
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        // If the heights are equal, the tree is complete, so return 2^h - 1 nodes
        if (lh == rh)
        /*
            1 << lh: This is a bitwise left shift operation. It shifts the binary 
            representation of 1 by lh positions to the left. Effectively, 
            it calculates 2^lh.
        */
            return (1 << lh) - 1;

        // If the heights are not equal, recursively count nodes in left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};