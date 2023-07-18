/*
    First Common Ancestor: design an algorithm and write code to find the first common ancestor
    of two nodes in a binary tree. Avoid storing additional nodes in a data structure
    NOTE: thsi is not necessarily a binary search tree
*/
#include <iostream>
#include <vector>

struct BinaryTreeNode {
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode* parent;
    BinaryTreeNode(int val) : val(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

/*
    SOLUTION #1: Using a data structure
*/
BinaryTreeNode* solution1(BinaryTreeNode* p, BinaryTreeNode* q) {
    std::vector<BinaryTreeNode*> pList;
    std::vector<BinaryTreeNode*> qList;

    while (p->parent != nullptr) {
        p = p->parent;
        pList.push_back(p);
    }

    while (q->parent != nullptr) {
        q = q->parent;
        qList.push_back(q);
    }

    for (BinaryTreeNode* binaryTreeNode : pList) {
        if (std::find(qList.begin(), qList.end(), binaryTreeNode) != qList.end())
            return binaryTreeNode;
    }

    return nullptr;
}

/*
    SOLUTION #2: No data structure and we know that the nodes link to the parent
    Algorithm: first we get the depth of both nodes, the difference between these 2 will tell 
    us how much we need to move the lowest one up. Once we know that we can move each of them up 
    until we found the common ancestor, if no ancestor is found we just return null
*/
BinaryTreeNode* moveUp(BinaryTreeNode* node, int difference) {
    while (difference != 0) {
        node = node->parent;
        difference--;
    }
    return node;
}

int depth(BinaryTreeNode* n) {
    int c = 0;
    while (n->parent != nullptr) {
        c++;
        n = n->parent;
    }
    return c;
}

BinaryTreeNode* solution(BinaryTreeNode* p, BinaryTreeNode* q) {
    int difference = depth(p) - depth(q);
    BinaryTreeNode* first = difference > 0 ? p : q; // lowest depth
    BinaryTreeNode* second = difference < 0 ? p : q;
    first = moveUp(first, difference);

    while (first != second && first->parent != nullptr && second->parent != nullptr) {
        first = first->parent;
        second = second->parent;
    }

    return (first == nullptr || second == nullptr) ? nullptr : first;
}


int main() {
    // Example usage
    BinaryTreeNode* node1 = new BinaryTreeNode(1);
    BinaryTreeNode* node2 = new BinaryTreeNode(2);
    BinaryTreeNode* node3 = new BinaryTreeNode(3);
    BinaryTreeNode* node4 = new BinaryTreeNode(4);
    BinaryTreeNode* node5 = new BinaryTreeNode(5);
    BinaryTreeNode* node6 = new BinaryTreeNode(6);
    BinaryTreeNode* node7 = new BinaryTreeNode(7);

    // Creating a sample binary tree
    node1->left = node2;
    node1->right = node3;
    node2->parent = node1;
    node3->parent = node1;

    node2->left = node4;
    node2->right = node5;
    node4->parent = node2;
    node5->parent = node2;

    node3->left = node6;
    node3->right = node7;
    node6->parent = node3;
    node7->parent = node3;

    BinaryTreeNode* commonAncestor = solution(node4, node6);
    if (commonAncestor != nullptr) {
        std::cout << "Common Ancestor: " << commonAncestor->val << std::endl;
    } else {
        std::cout << "No Common Ancestor found." << std::endl;
    }

    // Don't forget to clean up the allocated memory (assuming it's not part of a more extensive data structure handling).
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;

    return 0;
}