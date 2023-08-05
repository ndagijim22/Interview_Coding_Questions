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

bool subTree(TreeNode* r1, TreeNode* r2);
bool matchTree(TreeNode* r1, TreeNode* r2);
bool containsTree(TreeNode* t1, TreeNode* t2);
void getOrderString(TreeNode* node, std::string& sb);


bool subTree(TreeNode* r1, TreeNode* r2) {
        //base case
    if(r2 == nullptr)
        return true;

    if(r1 == nullptr)
        return false;
    
    //check the tree with root as current node
    if(matchTree(r1, r2))
        return true;
    
    //if the tree with root as current node doesn't match then try left and right
    //subtrees one by one
    bool leftTree = subTree(r1->left, r2);
    bool rightTree = subTree(r1->right, r2);
    // return subTree(r1->left, r2) || subTree(r1->right, r2);
    return leftTree || rightTree;
}

bool matchTree(TreeNode* r1, TreeNode* r2) {
    //base case
    if(r1 == nullptr && r2 == nullptr)
        return true;
    
    if(r1 == nullptr || r2 == nullptr)
        return false;
    
    //check if the data of both roots is same and data of left and right subtrees
    // are also the same
    bool leftTree = matchTree(r1->left, r2->left) ;
    bool rightTree = matchTree(r1->right, r2->right);
    // return (r1->data == r2->data && matchTree(r1->left, r2->left) 
                                //  && matchTree(r1->right, r2->right));
    return r1->data == r2->data && leftTree && rightTree;

}

            // SOLUTION # 2
//this functions checks if the tree t2 is a subtree of t1 by comparing
//their preorder traversal
bool containsTree(TreeNode* t1, TreeNode* t2) {
    std::string string1;
    std::string string2;

    getOrderString(t1, string1);
    getOrderString(t2, string2);

    return string1.find(string2) != std::string::npos;
}

/*
    This function generates the preorder of the tree and stores it in a string

*/
void getOrderString(TreeNode* node, std::string& sb) {
    if (node == nullptr) {
        sb.append("X"); // add null indicator
        return;
    }
    sb += std::to_string(node->data) + " "; // Add root
    getOrderString(node->left, sb); // Add left
    getOrderString(node->right, sb); // Add right
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
    bool result = subTree(t1, t2);
    // bool result = containsTree(t1, t2);

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
