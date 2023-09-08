/*
            Serialize and Deserialize Binary Tree
    Design an algorithm to serialize and deserialize a binary tree. There is no restriction 
    on how your serialization/deserialization algorithm should work. You just need to ensure
     that a binary tree can be serialized to a string and this string can be deserialized to 
     the original tree structure.

     Algo:
     1. Serialization
       - use DFS preorder to traverse the tree
     2. Deserialization
        - loop thru the string
        - initiate the node value and then
        - calls itself to construct its left and right child nodes
*/
#include <string> 
#include <sstream>
#include <vector>

using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Recursive serialization
    string rserialize(TreeNode* root, string str) {
        if (root == nullptr) {
            str += "null,";
        } else {
            str += to_string(root->val) + ",";
            str = rserialize(root->left, str);
            str = rserialize(root->right, str);
        }
        return str;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return rserialize(root, "");
    }

        //DESERIALIZATION
    // Recursive deserialization
    TreeNode* rdeserialize(std::vector<std::string>& l) {
        // Base case: if the list is empty or contains "null"
        if (l[0] == "null") {
            l.erase(l.begin());
            return nullptr;
        }

        // Create a TreeNode with the value from the list
        TreeNode* root = new TreeNode(stoi(l[0]));
        l.erase(l.begin());

        // Recursively deserialize left and right subtrees
        root->left = rdeserialize(l);
        root->right = rdeserialize(l);

        return root;
    }

    // Decodes your encoded data to a tree.
    TreeNode* deserialize(string data) {
        // Split the input data string into a vector of strings
        vector<string> data_vector;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            data_vector.push_back(token);
        }

        return rdeserialize(data_vector);
    }
};
