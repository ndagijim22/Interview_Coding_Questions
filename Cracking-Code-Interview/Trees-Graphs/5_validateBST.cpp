/*
    Validata BST: implement a function to check if a binary tree is a binary search tree
*/

#include <iostream>
#include <limits.h>

using namespace std;

class TreeNode{
    public:
        int data;
        struct TreeNode* left;
        struct TreeNode* right;
};

//create Node
TreeNode* newNode(int data){
    TreeNode* node = new TreeNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}
TreeNode* insertFunc(TreeNode* root, int value){
    //base case
    //it checks if the current node is nullptr, meaning we have reached the end of subtree
    if(!root)
        return newNode(value);
    
    if(value > root->data){
        root->right = insertFunc(root->right, value);
    }
    else {
        root->left = insertFunc(root->left, value);
    }

    return root;
}

//algorithm
//Source: https://www.youtube.com/watch?v=yEwSGhSsT0U

//helper functions
bool isSubtreeLesser(TreeNode* root, int value){

    if(root == NULL) return true;
    if(root->data <= value
        && isSubtreeLesser(root->left, value)
        && isSubtreeLesser(root->right, value))
        return true;
    else
        return false;

}
bool isSubtreeGreater(TreeNode* root, int value){

    if(root == NULL) return true;
    if(root->data > value
        && isSubtreeGreater(root->left, value)
        && isSubtreeGreater(root->right, value))
        return true;
    else
        return false;
}

bool isBST(TreeNode* root){

    if(root == NULL) return true;
    if(isSubtreeLesser(root->left, root->data) 
        && isSubtreeGreater(root->right, root->data)
        && isBST(root->left) && isBST(root->right))
        return true;
    else
        return false;
    
}

//Most efficient solution
//Algorithm
bool isBSTUtil(TreeNode* root, int minVal, int maxVal){
    if(root == NULL)
        return true;
    
    if(root->data < minVal && root->data > maxVal
        && isBSTUtil(root->left, minVal, root->data)
        && isBSTUtil(root->right, root->data, maxVal))
        return true;
    else 
        return false;
}

bool isBinarySearchTree(TreeNode* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

void preOrder(TreeNode* root){
    if(root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
//Driver code
int main(){
    TreeNode* root = NULL;
    root = newNode(34);
    
    insertFunc(root, 3);
    insertFunc(root, 40);
    insertFunc(root, 37);
    insertFunc(root, 35);
    insertFunc(root, 300);
    
    preOrder(root);
    cout << "Is BST or Not " << isBinarySearchTree(root) << endl;
    return 0;
}
