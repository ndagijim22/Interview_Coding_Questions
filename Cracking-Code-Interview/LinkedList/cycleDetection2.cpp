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

    int flag = 0; // A flag to indicate whether a cycle is detected

    // Loop until either fast reaches the end of the list (null) or fast's next is null (end of list)
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow one step forward and fast two steps forward in each iteration
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet, a cycle is detected
        if (slow == fast) {
            flag = 1;
            break;
        }
    }

    // If flag is still 0, there is no cycle, so return null
    if (flag == 0)
        return nullptr;

    // If flag is 1, there is a cycle, and fast is at the meeting point inside the cycle

    // Reset slow to the head of the linked list
    slow = head;

    // Use two pointers ptr1 and ptr2, both starting from the head
    ListNode* ptr1 = head;
    ListNode* ptr2 = fast;

    // Move ptr1 and ptr2 one step at a time until they meet at the starting node of the cycle
    while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // At this point, ptr1 and ptr2 meet at the starting node of the cycle

    // Return the starting node of the cycle
    return ptr1;
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

    // Print the value of the starting node of the cycle
    std::cout << "Starting node of the cycle: " << cycleStartNode->val << std::endl;

    // Deallocating memory
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
