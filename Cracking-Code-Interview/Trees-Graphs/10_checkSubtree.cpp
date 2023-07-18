/*
    Check Subtree: T1 and T2 are two very large binary trees, with T1 much bigger than T2
    create an algorithm to determine if T2 is a subtree of T1.

    a tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n
    is identical to T2 that is if you cut off the tree at node n, the two trees would be identical

    ALGORITHM: search thru the larger tree t1. each time a node in t1 matches the root fo t2,
    call matchTree. The matchTree will compare the two subtrees to see if they are identical
*/

#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool containsTree(TreeNode* t1, TreeNode* t2);
bool subTree(TreeNode* r1, TreeNode* r2);
bool matchTree(TreeNode* r1, TreeNode* r2);

bool containsTree(TreeNode* t1, TreeNode* t2) {
    // Base case: Empty tree is always a subtree
    if (t2 == nullptr)
        return true;

    return subTree(t1, t2);
}

bool subTree(TreeNode* r1, TreeNode* r2) {
    if (r1 == nullptr) {
        return false; // Big tree empty & subtree not found
    } else if (r1->data == r2->data && matchTree(r1, r2)) {
        return true;
    }
    return subTree(r1->left, r2) || subTree(r1->right, r2);
}

bool matchTree(TreeNode* r1, TreeNode* r2) {
    if (r1 == nullptr && r2 == nullptr) {
        return true; // Nothing in the subtree
    } else if (r1 == nullptr || r2 == nullptr) {
        return false; // Exactly one tree is empty, therefore trees don't match
    } else if (r1->data != r2->data) {
        return false; // Data doesn't match
    } else {
        return matchTree(r1->left, r2->left) && matchTree(r1->right, r2->right);
    }
}

int main() {
    // Create the first tree
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->left->left = new TreeNode(4);
    t1->left->right = new TreeNode(5);
    t1->right->left = new TreeNode(6);
    t1->right->right = new TreeNode(7);

    // Create the second tree
    TreeNode* t2 = new TreeNode(2);
    t2->left = new TreeNode(4);
    t2->right = new TreeNode(5);

    // Check if t2 is a subtree of t1
    bool result = containsTree(t1, t2);

    // Output the result
    if (result) {
        std::cout << "t2 is a subtree of t1." << std::endl;
    } else {
        std::cout << "t2 is not a subtree of t1." << std::endl;
    }

    // Clean up memory (assuming there is no memory management elsewhere)
    delete t1->left->left;
    delete t1->left->right;
    delete t1->right->left;
    delete t1->right->right;
    delete t1->left;
    delete t1->right;
    delete t1;

    delete t2->left;
    delete t2->right;
    delete t2;

    return 0;
}
