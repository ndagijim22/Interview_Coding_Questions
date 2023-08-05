#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create a dummy node (sentinel node) to simplify the code logic
    ListNode* sen = new ListNode(0);
    sen->next = head;

    ListNode* first = head; // Pointer to traverse the linked list
    // Move the 'first' pointer 'n' steps ahead in the linked list
    while (n > 0) {
        first = first->next;
        n--;
    }

    ListNode* second = sen; // Pointer to keep track of the node that will be removed

    // Move both 'first' and 'second' pointers until 'first' reaches the end of the linked list
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    // Remove the node by updating the 'next' pointer of the previous node
    second->next = second->next->next;

    // Return the head of the updated linked list (exclude the dummy node)
    return sen->next;
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    // Remove the nth node from the end of the linked list
    ListNode* updatedList = removeNthFromEnd(head, n);

    // Print the updated linked list
    ListNode* temp = updatedList;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    // Deallocating memory
    while (updatedList != nullptr) {
        ListNode* temp = updatedList;
        updatedList = updatedList->next;
        delete temp;
    }

    return 0;
}
