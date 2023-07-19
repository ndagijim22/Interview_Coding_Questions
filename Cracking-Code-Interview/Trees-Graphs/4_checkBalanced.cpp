/*
   Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of 
    this question, a balanced tree is defined to be a tree such that the heights
    of the two subtrees of any node never differ by more than one.

        ALGORITHM
    - Use the fact that two subtrees are balanced if their heights never differ by more than 1
    - recurse thru the entire tree, and for each node, compute height of its subtree
*/

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

//Time complexity: O(N log N) we go thru the entire subtrees. each node is touched once
//This is not optimal. See below optimal solution
int getHeight(TreeNode* root) {
    // Base case
    if (root == nullptr)
        return -1;
    //we add 1, to include the root node.
    //By doing this, we count the edge from the current node to its child nodes
    //empty tree has a height of -1
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

bool isBalanced1(TreeNode* root) {
    if (root == nullptr)
        return true;

    int heightDiff = getHeight(root->left) - getHeight(root->right);
    if (abs(heightDiff) > 1) {
        return false;
    } else {
        // Recursevely check left and right of each subtree in the the tree
        //we did not return true, b/c we want to check all the subtrees
        return isBalanced1(root->left) && isBalanced1(root->right);
    }
}

//Optimal solution: use getHeight to check is the tree is balanced at the same time as it's checking heights
//retrun error when the tree is not balanced
//This code runs in O(N) time and O(H) space, where H is the height of the tree
int checkHeight(TreeNode* root) {
    if (root == nullptr)
        return -1;
    //we can return -1 as an error instead of numeric_limits<int>::min()
    int leftHeight = checkHeight(root->left);
    if (leftHeight == numeric_limits<int>::min())
        return numeric_limits<int>::min(); // pass error up

    int rightHeight = checkHeight(root->right);
    if (rightHeight == numeric_limits<int>::min())
        return numeric_limits<int>::min(); // pass error up

    int heightDiff = leftHeight - rightHeight;
    if (abs(heightDiff) > 1) {
        return numeric_limits<int>::min(); // found error -> pass it back
    } else {
        return max(leftHeight, rightHeight) + 1;
    }
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != numeric_limits<int>::min();
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    // Check if the tree is balanced
    bool balanced = isBalanced(root);

    // Print the result
    cout << "Is the tree balanced? " << (balanced ? "Yes" : "No") << endl;

    return 0;
}
