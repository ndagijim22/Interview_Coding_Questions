/*
    List of Depths: Given a binary tree, design an algorithm which creates a linked list of
    all the nodes at each depth (ex: if you have a tree with depth D, you'll have D linked lists)

    check this source: https://kodr.me/en/list-of-depths
*/
#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node
struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

vector<vector<int>> solution(BinaryTreeNode* head) {
    int counter = 0;
    vector<vector<int>> listOfLists;
    traverseAndAppend(listOfLists, head, counter);
    return listOfLists;
}

void traverseAndAppend(vector<vector<int>>& list, BinaryTreeNode* node, int counter) {
    if (node != nullptr) {
        addToList(list, counter, node->data);
        traverseAndAppend(list, node->left, counter + 1);
        traverseAndAppend(list, node->right, counter + 1);
    }
}

void addToList(vector<vector<int>>& list, int counter, int value) {
    try {
        list[counter].push_back(value);
    } catch (const out_of_range& error) {
        list.push_back(vector<int>());
        list[counter].push_back(value);
    }
}

int main() {
    // Create a binary tree
    BinaryTreeNode* root = new BinaryTreeNode(4);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(6);
    root->left->left = new BinaryTreeNode(1);
    root->left->right = new BinaryTreeNode(3);
    root->right->left = new BinaryTreeNode(5);
    root->right->right = new BinaryTreeNode(7);

    // Create list of lists of nodes at each depth
    vector<vector<int>> lists = solution(root);

    // Print the list of lists
    for (const auto& innerList : lists) {
        for (const auto& value : innerList) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
