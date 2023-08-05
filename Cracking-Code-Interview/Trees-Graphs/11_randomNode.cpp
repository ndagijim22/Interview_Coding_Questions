/*
    Random Node: you are implementing a binary search tree class from scratch, which
    in addition to insert, find, and delete has a method getRandomNode() which returns
    a random node from the tree. All nodes should be equally likes to be chosen. 
    design and implement an algorithm for getRandomNode, and explain how you would implement
    the rest of the method.
*/
#include <iostream>
#include <random>

using namespace std;

class TreeNode {
private:
    int data;
    TreeNode* left;
    TreeNode* right;
    int size;

public:
    TreeNode(int d) : data(d), left(nullptr), right(nullptr), size(1) {}

    //Returns a pointer to a randomly selected node from BST, with all the nodes
    // having equal probability of being chosen. This is achieved using reservoir sampling
    TreeNode* getRandomNode() {
        //calculates the size of left subtree rooted at the current node.
        //if left child left is nullptr, teh leftSize is set to 0.
        //otherwise, it is set to the size of teh left child
        int leftSize = (left == nullptr) ? 0 : left->size;
        //This creates a random number generator rd, which provides non-deterministic random
        // numbers from the hardware device
        random_device rd;

        //This creates a Mersenne Twister random number generator gen using 
        // the random numbers obtained fron rd
        mt19937 gen(rd());

        /*
            This creates a uniform distribution dist that generates integers in 
            the range [0, size - 1]. Here, size is the total number of nodes in
            the current subtree (including the current node).
        */
        uniform_int_distribution<int> dist(0, size - 1);

        /*
            This generates a random integer index in the range [0, size - 1] 
            using the uniform distribution dist and the Mersenne Twister generator gen.
        */
        int index = dist(gen);
        
        /*
            The function then proceeds to determine which node to return as 
            the random node based on the generated index:
        */
       //if generaded index < left size, this means the random node should come from
       // the left subtree. In this case, the f(x) calls getRandomNode() recursively on the
       // left childe 'left', effectively selecting a random node from the left subtree
        if (index < leftSize) {
            return left->getRandomNode();
        
        //if index is equal to leftsize. it means the random node should be the current node
        //so the function returns the current node. so the function returns 'this' i.e current node
        } else if (index == leftSize) {
            return this;
        
        //Else go to the right  subtree
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

    cout << "Random Node: " << root.getRandomNode()->getData() << endl;
    cout << "Random Node: " << root.getRandomNode()->getData() << endl;

    int target = 6;
    TreeNode* found = root.find(target);
    if (found) {
        cout << "Node with data " << target << " found." << endl;
    } else {
        cout << "Node with data " << target << " not found." << endl;
    }

    return 0;
}
