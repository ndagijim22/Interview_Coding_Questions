#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Create a dummy node (initially points to 0) to simplify the code logic
    ListNode* ans = new ListNode(0);

    // Create a pointer 'a' to the dummy node to keep track of the head of the merged list
    ListNode* a = ans;

    // Merge the two sorted linked lists 'l1' and 'l2'
    while (l1 != nullptr || l2 != nullptr) {
        // If 'l1' is null, append the remaining elements of 'l2' to the merged list and break the loop
        if (l1 == nullptr) {
            ans->next = l2;
            break;
        }

        // If 'l2' is null, append the remaining elements of 'l1' to the merged list and break the loop
        if (l2 == nullptr) {
            ans->next = l1;
            break;
        }

        // Compare the values of 'l1' and 'l2'
        if (l1->val <= l2->val) {
            // If the value of 'l1' is less than or equal to 'l2', append 'l1' to the merged list
            ans->next = l1;

            // Move 'l1' to the next node in 'l1'
            l1 = l1->next;
        } else {
            // If the value of 'l2' is less than 'l1', append 'l2' to the merged list
            ans->next = l2;

            // Move 'l2' to the next node in 'l2'
            l2 = l2->next;
        }

        // Move 'ans' to the next node in the merged list
        ans = ans->next;
    }

    // Return the head of the merged list (exclude the dummy node)
    return a->next;
}

int main() {
    // Create linked list l1: 1 -> 2 -> 4
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    // Create linked list l2: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // Merge l1 and l2 into a new sorted linked list
    ListNode* mergedList = mergeTwoLists(l1, l2);

    // Print the merged list
    ListNode* temp = mergedList;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    // Deallocating memory
    while (mergedList != nullptr) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    delete l1->next->next;
    delete l1->next;
    delete l1;

    delete l2->next->next;
    delete l2->next;
    delete l2;

    return 0;
}
