/*
    Given a sorted (increasing order) array with unique integer elements, write algo.
    to create a binary search tree with minimal height

            ALGORITHM
    - find mid elt in array, make the mid elt the root.
    - elts on left, become subtree, elts on right become subtree
    - Do this to all subsection of the array recursively
*/
#include <iostream>
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
//Algorithm
TreeNode* minimalTree(int* numArray, int start, int end){
    //base case
    if(end < start)
        return NULL;

    int mid = (start + end) /2;
    TreeNode* root = newNode(numArray[mid]);

    root->left = minimalTree(numArray, start, mid - 1);
    root->right = minimalTree(numArray, mid + 1, end);
    
    return root;
}

void preOrder(TreeNode* root){
    if(root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root){
    if(root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    /* Convert List to BST */
    TreeNode* root = minimalTree(arr, 0, n - 1);
    cout << "PreOrder Traversal of constructed BST \n";
    // inOrder(root);
    preOrder(root);
 
    return 0;
}