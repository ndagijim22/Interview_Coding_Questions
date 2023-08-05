#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

ListNode* detectCycle(ListNode* head) {
    // Initialize two pointers slow and fast to the head of the linked list
    ListNode* slow = head;
    ListNode* fast = head;

    // Traverse the linked list using slow and fast pointers
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow one step forward and fast two steps forward in each iteration
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet, a cycle is detected
        if (slow == fast) {
            // Reset either slow or fast pointer to the head of the linked list
            slow = head;

            // Move both pointers one step at a time until they meet again
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            // At this point, slow and fast meet at the starting node of the cycle
            return slow;
        }
    }

    // If the loop is terminated because the fast pointer or its next node is null, there is no cycle
    return nullptr;
}

int main() {
    // Creating nodes
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Creating a cycle, -4 points back to 2

    // Detect the cycle and get the starting node of the cycle (3 in this example)
    ListNode* cycleStartNode = detectCycle(head);

    if (cycleStartNode != nullptr) {
        // Print the value of the starting node of the cycle
        std::cout << "Starting node of the cycle: " << cycleStartNode->val << std::endl;
    } else {
        std::cout << "No cycle found in the linked list." << std::endl;
    }

    // Deallocating memory
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
