/*
    Successor: Write an algorithm to find the next ndoe (i.e in-order successor)
    of a given node in a binary search tree. you may assume that each node has a link to its parent

*/
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

TreeNode* leftMostChild(TreeNode* n) {
    if (n == nullptr) {
        return nullptr;
    }

    while (n->left != nullptr) {
        n = n->left;
    }
    return n;
}

TreeNode* inorderSucc(TreeNode* n) {
    if (n == nullptr)
        return nullptr;

    // found right children -> return leftmost node of right subtree
    if (n->right != nullptr) {
        return leftMostChild(n->right);
    } else {
        TreeNode* q = n;
        TreeNode* x = q->parent;
        // go up until we're on the left instead of the right
        while (x != nullptr && x->left != q) {
            q = x;
            x = x->parent;
        }
        return x;
    }
}

//Driver code
int main() {
    // Test the functions with a sample binary search tree

    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->parent = root;
    root->right->parent = root;

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->left->left->parent = root->left;
    root->left->right->parent = root->left;

    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);
    root->right->left->parent = root->right;
    root->right->right->parent = root->right;

    TreeNode* node1 = root->left->right; // Node with value 15
    TreeNode* node2 = root->right->left; // Node with value 25

    // Testing inorderSucc
    TreeNode* succ1 = inorderSucc(node1);
    TreeNode* succ2 = inorderSucc(node2);

    std::cout << "Inorder successor of node with value 15: ";
    if (succ1 != nullptr)
        std::cout << succ1->val << std::endl;
    else
        std::cout << "null" << std::endl;

    std::cout << "Inorder successor of node with value 25: ";
    if (succ2 != nullptr)
        std::cout << succ2->val << std::endl;
    else
        std::cout << "null" << std::endl;

    // Clean up memory (don't forget to free allocated memory in your actual code)
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}


