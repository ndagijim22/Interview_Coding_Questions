/*
    Random Node: you are implementing a binary search tree class from scratch, which
    in addition to insert, find, and delete has a method getRandomNode() which returns
    a random node from the tree. All nodes should be equally likes to be chosen. 
    design and implement an algorithm for getRandomNode, and explain how you would implement
    the rest of the method.
*/
#include <iostream>
#include <random>

class TreeNode {
private:
    int data;
    TreeNode* left;
    TreeNode* right;
    int size;

public:
    TreeNode(int d) : data(d), left(nullptr), right(nullptr), size(1) {}

    TreeNode* getRandomNode() {
        int leftSize = (left == nullptr) ? 0 : left->size;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, size - 1);
        int index = dist(gen);
        
        if (index < leftSize) {
            return left->getRandomNode();
        } else if (index == leftSize) {
            return this;
        } else {
            return right->getRandomNode();
        }
    }

    void insertInOrder(int d) {
        if (d <= data) {
            if (left == nullptr) {
                left = new TreeNode(d);
            } else {
                left->insertInOrder(d);
            }
        } else {
            if (right == nullptr) {
                right = new TreeNode(d);
            } else {
                right->insertInOrder(d);
            }
        }
        size++;
    }

    int getSize() {
        return size;
    }

    int getData() {
        return data;
    }

    TreeNode* find(int d) {
        if (d == data) {
            return this;
        } else if (d <= data) {
            return (left != nullptr) ? left->find(d) : nullptr;
        } else if (d > data) {
            return (right != nullptr) ? right->find(d) : nullptr;
        }
        return nullptr;
    }
};

int main() {
    TreeNode root(5);
    root.insertInOrder(3);
    root.insertInOrder(7);
    root.insertInOrder(2);
    root.insertInOrder(4);
    root.insertInOrder(6);
    root.insertInOrder(8);

    std::cout << "Random Node: " << root.getRandomNode()->getData() << std::endl;
    std::cout << "Random Node: " << root.getRandomNode()->getData() << std::endl;

    int target = 6;
    TreeNode* found = root.find(target);
    if (found) {
        std::cout << "Node with data " << target << " found." << std::endl;
    } else {
        std::cout << "Node with data " << target << " not found." << std::endl;
    }

    return 0;
}
