/*
    First Common Ancestor: design an algorithm and write code to find the first common ancestor
    of two nodes in a binary tree. Avoid storing additional nodes in a data structure
    NOTE: thsi is not necessarily a binary search tree

    ALGORITHM: 
    1. Search the two nodes in the Binary tree
    2. if (node found)
            return node
        else
            return NULL;
    3. When some node receives both left and right pinter as not NULL, then it is LCA
       else return what it receives
*/
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};

TreeNode* firstCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    //basic check
    if(root == nullptr)
        return nullptr;

    //Searching of the node. 
    if(root == q || root == p)
        return root;
    
    //The inorder traversal. Traverse the tree when you find the node return it
    //while traversing we're checking the above if stment. when we get the need we return it
    TreeNode* left = firstCommonAncestor(root->left, p, q);
    TreeNode* right = firstCommonAncestor(root->right, p, q);

    //check if both right and left node are not null
    //this is the case when right and left child have both nodes
    //which automatically shows that the root is the first common ancestor
    if(left != nullptr && right != nullptr){
        return root;
    }
    else{
        //if left node is returned and right node is empty return left
        //otherwise return right node
        return (left ? left : right);
    }
}

//Driver code
int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(55);
    root->left->right = new TreeNode(15);
    root->left->right->right = new TreeNode(17);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(35);

    // Test the solution
    TreeNode* p = root->left->left->left;
    TreeNode* q = root->left->right->right;
    TreeNode* result = firstCommonAncestor(root, nullptr, nullptr);
    if (result != nullptr) {
        std::cout << "Lowest Common Ancestor: " << result->val << std::endl;
    } else {
        std::cout << "One or both nodes not found in the tree." << std::endl;
    }

    // Free the allocated memory (optional if not using smart pointers)
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;


    return 0;
}