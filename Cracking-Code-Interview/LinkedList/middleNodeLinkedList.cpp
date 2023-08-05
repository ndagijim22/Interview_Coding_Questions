// Definition of a singly-linked list node
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// Function to find the middle node of a singly-linked list
Node* middleNode(Node* head) {
    // Initialize two pointers, slowPtr and fastPtr, both pointing to the head of the list
    Node* slowPtr = head;
    Node* fastPtr = head;

    // Traverse the list with two pointers, where fastPtr moves two steps at a time and slowPtr moves one step at a time
    // When fastPtr reaches the end (nullptr) or the node just before the end, slowPtr will be at the middle node
    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        slowPtr = slowPtr->next;             // Move slowPtr one step
        fastPtr = fastPtr->next->next;       // Move fastPtr two steps
    }

    // Return the middle node
    return slowPtr;
}
