#include <unordered_map>

using namespace std;

/*
    Algo:
    1. Adding node to the back of the linked list
        a. we add the head of llist every time when we add a new key or update 
                an existing one. add(ListNode node) will be implemented as a helper for this
        b.this can be done like this:
            1. Get current node at the end of llist(tail->prev), call it previousEnd
            2. node is being inserted, so set prevousNode->next = node
            3. now we set the ptrs of node. first, node->prev = previousEnd
            4. next, set it as the tail, node->next = tail;
            5. Finally we update tail->prev = node

    2. Removing a node from the linked list
        a. remove when we updata/fetch a key or when exceeds capacity
                remove(ListNode node) will be implemented as helper to remove from
        b. This can be done like this:
            1. let's call nextNode = node.next and prevNode = node.prev. currently, 
                nextNode.prev = node and preveNode.next = node. To remove node from the linked list
                we need to reassign nextNode.prev = prevNode and prevNode.next = nextNode
            2. similarly we can do it like this without declaring new nodes
                a. node.prev.next = node.next
                b. node.next.prev = node.prev
                
    3. The get(int key) method
        a. chekc if key exists in map if not return -1
        b. get the node associated with the key from the hash map
        c. move it to the back of llist. call remove(node) and add(node)
        d. return the valuse associated with key, whihc is node.val

    4. The put(int key, int value) method
        a. updates the key:value if exists, otherwise inserts. if insert causes the 
            map to overflow, remove the Lease recenlty used key which is the head of llist
        b. This can be implemented like this:
            1. first check if key is in map. if it does find node associated with it and call
                remove() on it. we are going to need remove the key to the back of the queue, 
                so we need to remove it from the llist first.
            2. Create a new node using key, value.
            3. Set key: node in the hash map
            4. add node to the back of the llist with add(node)
            5. Finally check if the data structure has exceeded capacity by using the hash
                map's size.
                    - if it has, get the nodeToDelete as head.next
                    - delete the node with remove(nodeToDelete)
                    - Delete the key from the hash map. the key is nodeTodelete.key
    Time: O(1) all functions
    Space: O(n): n is the capacity of the map

*/
// Definition of a Node structure
struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};

// Implementation of an LRUCache using a doubly linked list and a hash map
class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> dic; // Hash map to store key-node pairs
    Node *head = new Node(-1, -1); // Dummy head node for the linked list
    Node *tail = new Node(-1, -1); // Dummy tail node for the linked list

    // Constructor to initialize the LRUCache
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Get the value associated with a key
    int get(int key) {
        if (dic.find(key) == dic.end()) {
            return -1; // Key not found in the cache
        }

        Node *node = dic[key];
        remove(node); // Remove the node from its current position
        add(node);    // Move the node to the end of the linked list
        return node->val;
    }

    // Put a key-value pair in the cache
    void put(int key, int value) {
        if (dic.find(key) != dic.end()) {
            Node *oldNode = dic[key];
            remove(oldNode); // Remove the old node from the linked list
        }

        Node *node = new Node(key, value); // Create a new node
        dic[key] = node;                   // Update the hash map
        add(node);                         // Add the new node to the end of the linked list

        if (dic.size() > capacity) {
            Node *nodeToDelete = head->next;
            remove(nodeToDelete); // Remove the least recently used node from the linked list
            dic.erase(nodeToDelete->key); // Remove the corresponding entry from the hash map
        }
    }

    // Add a node to the end of the linked list
    void add(Node *node) {
        Node *previousEnd = tail->prev;
        previousEnd->next = node;
        node->prev = previousEnd;
        node->next = tail;
        tail->prev = node;
    }

    // Remove a node from the linked list
    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
