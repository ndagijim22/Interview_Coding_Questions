/*
    Validata BST: implement a function to check if a binary tree is a binary search tree
*/

#include <iostream>
#include <limits>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

bool checkBST(TreeNode* n) {
    return checkBST(n, nullptr, nullptr);
}

bool checkBST(TreeNode* n, int* min, int* max) {
    // Base case
    //an empty tree is considered a valid BST
    if (n == nullptr)
        return true;
    /*
        The purpose of this condition is to check if the value of the current node
        n->val violates the range boundaries specified by min and max. 
        if the value of the current node is outside the valid range for the current subtree
        it means that the tree is not a valid BST, and the function returns false
    */
    if ((min != nullptr && n->val <= *min) || (max != nullptr && n->val > *max)) {
        return false;
    }

    if (!checkBST(n->left, min, &(n->val)) || !checkBST(n->right, &(n->val), max)) {
        return false;
    }

    return true;
}

//Solution #2: In-order traversal: Only works when No duplicates in the tree
int index = 0;
void copyBST(TreeNode root, int[] array){
    if(root == nullptr)
        return;

    copyBST(root->left, array);
    arry[index] = root->data;
    index++;
    copyBST(root->right, array);
}

bool checkBST(TreeNode root){
    vector<int> array;
    copyBST(root, array);

    for(int i = 0; i < array.size(); i++){
        if(array[i] <= array[i - 1])
            return false;
    }

    return true;
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

    // Check if the tree is a valid BST
    bool isValidBST = checkBST(root);

    // Print the result
    cout << "Is the tree a valid BST? " << (isValidBST ? "Yes" : "No") << endl;

    return 0;
}
