/*
    List of Depths: Given a binary tree, design an algorithm which creates a linked list of
    all the nodes at each depth (ex: if you have a tree with depth D, you'll have D linked lists)

    check this source: https://kodr.me/en/list-of-depths
*/
#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

vector<list<TreeNode*> > createLevelLinkedList(TreeNode* root) {
    vector<list<TreeNode*> > result;
    queue<TreeNode*> current;

    if (root != nullptr) {
        current.push(root);
    }

    while (!current.empty()) {
        //appends a new empty list to the end of "result" vector
        result.push_back(list<TreeNode*>());
        queue<TreeNode*> parents;
        swap(current, parents);

        while (!parents.empty()) {
            TreeNode* parent = parents.front();
            parents.pop();
            //result is a vector of lists. result.back() returns a ref to the last list in vector
            //then the push_back() function is called on that list.
            result.back().push_back(parent);

            if (parent->left != nullptr) {
                current.push(parent->left);
            }
            if (parent->right != nullptr) {
                current.push(parent->right);
            }
        }
    }

    return result;
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    // root->right->right = new TreeNode(7);

    // Create level-linked lists
    vector<list<TreeNode*> > lists = createLevelLinkedList(root);

    // Print the level-linked lists
    for (const auto& level : lists) {
        for (const auto& node : level) {
            cout << node->val << " ";
        }
        cout << endl;
    }

    return 0;
}

