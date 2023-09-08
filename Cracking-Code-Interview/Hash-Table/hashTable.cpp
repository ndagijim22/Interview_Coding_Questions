/*
    Design and implement a hash table which uses chaining (linked lists) to handle
    collisions
*/
#include <iostream>
#include <vector>

using namespace std;

//define the node structure for the linked list
struct Node {
    int key;
    int value;
    Node* next;

    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable{
    private:
        int tableSize;
        vector<Node*> buckets;

        //hash function to calculate the index
        int hashFunction(int key){
            return key % tableSize;
        }

    public:
        //constructor to init the hash table with a given size
        HashTable(int size): tableSize(size){
            buckets.resize(tableSize, nullptr);
        }

        //insert a key-value pair into the hash table
        void insert(int key, int value){
            int index = hashFunction(key);
            Node* newNode = new Node(key, value);

            if(buckets[index] == nullptr){
                //no collision occured, insert node as first elt
                Node* curr = buckets[index];
            } else{
                //collision occured, add the new node at the end of linked list
                Node* curr = buckets[index];
                while(curr->next != nullptr){
                    curr = curr->next;
                }
                curr->next = newNode;
            }
        }

        //Retrieve the value associated witha  given key
        int get(int key){
            int index = hashFunction(key);
            Node* curr = buckets[index];
            while(curr != nullptr){
                if(curr->key == key){
                    return curr->value;
                }
                curr = curr->next;
            }

            //key not found
            return -1;
        }

        //Remove a key-value pair from the hash table
        void remove(int key){
            int index = hashFunction(key);
            Node* curr = buckets[index];
            Node* prev = nullptr;

            while(curr != nullptr){
                if(curr->key == key){
                    if(prev == nullptr){
                        //the node to be removed is the head
                        buckets[index] = curr->next;
                    } else {
                        //the node to be removed is in the middle or end of list
                        prev->next = curr->next;
                    }
                    //Free the memory of the removed node
                    delete curr;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
        }
        // Destructor to free the memory used by the hash table
    ~HashTable() {
        for (int i = 0; i < tableSize; i++) {
            Node* curr = buckets[i];
            while (curr != nullptr) {
                Node* temp = curr;
                curr = curr->next;
                // Free the memory of each node in the linked list
                delete temp;
            }
        }
    }


};

int main() {
    HashTable hashTable(10);

    hashTable.insert(5, 42);
    hashTable.insert(15, 84);
    hashTable.insert(25, 67);

    std::cout << "Value associated with key 5: " << hashTable.get(5) << std::endl;
    std::cout << "Value associated with key 15: " << hashTable.get(15) << std::endl;
    std::cout << "Value associated with key 25: " << hashTable.get(25) << std::endl;

    hashTable.remove(15);

    std::cout << "Value associated with key 15 after removal: " << hashTable.get(15) << std::endl;

    return 0;
}


        // GENERIC CODE USING TEMPLATE IN C++
// #include <iostream>
// #include <vector>

// template <typename K, typename V>
// struct Node {
//     K key;
//     V value;
//     Node* next;

//     Node(K k, V v) : key(k), value(v), next(nullptr) {}
// };

// template <typename K, typename V>
// class HashTable {
// private:
//     int tableSize;
//     std::vector<Node<K, V>*> buckets;

//     // Hash function to calculate the index
//     int hashFunction(K key) {
//         return key % tableSize;
//     }

// public:
//     // Constructor to initialize the hash table with a given size
//     HashTable(int size) : tableSize(size) {
//         buckets.resize(tableSize, nullptr);
//     }

//     // Insert a key-value pair into the hash table
//     void insert(K key, V value) {
//         int index = hashFunction(key);
//         Node<K, V>* newNode = new Node<K, V>(key, value);

//         if (buckets[index] == nullptr) {
//             // No collision occurred, insert node as the first element
//             buckets[index] = newNode;
//         } else {
//             // Collision occurred, add the new node at the end of the linked list
//             Node<K, V>* curr = buckets[index];
//             while (curr->next != nullptr) {
//                 curr = curr->next;
//             }
//             curr->next = newNode;
//         }
//     }

//     // Retrieve the value associated with a given key
//     V get(K key) {
//         int index = hashFunction(key);
//         Node<K, V>* curr = buckets[index];
//         while (curr != nullptr) {
//             if (curr->key == key) {
//                 return curr->value;
//             }
//             curr = curr->next;
//         }

//         // Key not found
//         return V{}; // Return a default-constructed value (0 for numeric types, empty string for strings, etc.)
//     }

//     // Remove a key-value pair from the hash table
//     void remove(K key) {
//         int index = hashFunction(key);
//         Node<K, V>* curr = buckets[index];
//         Node<K, V>* prev = nullptr;

//         while (curr != nullptr) {
//             if (curr->key == key) {
//                 if (prev == nullptr) {
//                     // The node to be removed is the head
//                     buckets[index] = curr->next;
//                 } else {
//                     // The node to be removed is in the middle or end of the list
//                     prev->next = curr->next;
//                 }
//                 // Free the memory of the removed node
//                 delete curr;
//                 return;
//             }
//             prev = curr;
//             curr = curr->next;
//         }
//     }

//     // Destructor to free the memory used by the hash table
//     ~HashTable() {
//         for (int i = 0; i < tableSize; i++) {
//             Node<K, V>* curr = buckets[i];
//             while (curr != nullptr) {
//                 Node<K, V>* temp = curr;
//                 curr = curr->next;
//                 // Free the memory of each node in the linked list
//                 delete temp;
//             }
//         }
//     }
// };

// int main() {
//     HashTable<int, int> hashTable(10);

//     hashTable.insert(5, 42);
//     hashTable.insert(15, 84);
//     hashTable.insert(25, 67);

//     std::cout << "Value associated with key 5: " << hashTable.get(5) << std::endl;
//     std::cout << "Value associated with key 15: " << hashTable.get(15) << std::endl;
//     std::cout << "Value associated with key 25: " << hashTable.get(25) << std::endl;

//     hashTable.remove(15);

//     std::cout << "Value associated with key 15 after removal: " << hashTable.get(15) << std::endl;

//     return 0;
// }
