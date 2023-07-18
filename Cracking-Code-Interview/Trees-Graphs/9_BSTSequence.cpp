/*
    BST sequence: A binary search tree was created by traversing through an array from left
    to right and inserting each element. Given a binary search tree with distinct elements
    print all possible arrays that could have led to this tree
*/
#include <iostream>
#include <vector>
#include <list>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void weaveLists(std::list<int>& first, std::list<int>& second, std::vector<std::list<int>>& results, std::list<int>& prefix);

std::vector<std::list<int>> allSequences(TreeNode* node) {
    std::vector<std::list<int>> result;

    if (node == nullptr) {
        result.push_back(std::list<int>());
        return result;
    }

    std::list<int> prefix;
    prefix.push_back(node->data);

    // Recurse on left and right subtrees.
    std::vector<std::list<int>> leftSeq = allSequences(node->left);
    std::vector<std::list<int>> rightSeq = allSequences(node->right);

    // Weave together each list from the left and right sides.
    for (const auto& left : leftSeq) {
        for (const auto& right : rightSeq) {
            std::vector<std::list<int>> weaved;
            weaveLists(left, right, weaved, prefix);
            result.insert(result.end(), weaved.begin(), weaved.end());
        }
    }

    return result;
}

// Weave lists together in all possible ways. This algorithm works by removing the head from
// one list, recursing, and then doing the same thing with the other list.
void weaveLists(std::list<int>& first, std::list<int>& second, std::vector<std::list<int>>& results, std::list<int>& prefix) {
    // One list is empty. Add the remainder to [a cloned] prefix and store the result.
    if (first.size() == 0 || second.size() == 0) {
        std::list<int> result = prefix;
        result.insert(result.end(), first.begin(), first.end());
        result.insert(result.end(), second.begin(), second.end());
        results.push_back(result);
        return;
    }

    // Recurse with the head of the first added to the prefix.
    // Removing the head will damage the first list, so we'll need to put it back where we found it afterward.
    int headFirst = first.front();
    first.pop_front();
    prefix.push_back(headFirst);
    weaveLists(first, second, results, prefix);
    prefix.pop_back();
    first.push_front(headFirst);

    // Do the same thing with the second, damaging, and then restoring the list.
    int headSecond = second.front();
    second.pop_front();
    prefix.push_back(headSecond);
    weaveLists(first, second, results, prefix);
    prefix.pop_back();
    second.push_front(headSecond);
}

// Helper function to delete the tree and free memory
void deleteTree(TreeNode* node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);

    std::vector<std::list<int>> sequences = allSequences(root);

    // Print the sequences
    for (const auto& seq : sequences) {
        for (int value : seq) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    // Don't forget to free the memory occupied by the tree
    deleteTree(root);

    return 0;
}
