#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

ListNode* reverse(ListNode* head) {
    // Reverse the linked list iteratively
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode* findMid(ListNode* head) {
    // Find the middle node of the linked list using slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void reorderList(ListNode* head) {
    // Check if the linked list is empty or has only one node
    if (head == nullptr || head->next == nullptr)
        return;

    ListNode* mid = findMid(head); // Find the middle node of the linked list

    ListNode* l2 = mid->next; // Separate the second half of the linked list starting from the middle node
    mid->next = nullptr; // Set the next of middle node to null to divide the list into two parts
    ListNode* l1 = head; // First half of the linked list (starting from the head)

    l2 = reverse(l2); // Reverse the second half of the linked list

    ListNode* ans = new ListNode(0); // Dummy node to simplify the code logic
    int dir = 0; // Direction flag: 0 for l1, 1 for l2

    while (l1 != nullptr || l2 != nullptr) {
        if (l1 == nullptr) {
            ans->next = l2;
            break;
        }

        if (l2 == nullptr) {
            ans->next = l1;
            break;
        }

        if (dir == 0) {
            ans->next = l1;
            l1 = l1->next;
            dir = 1;
        } else if (dir == 1) {
            ans->next = l2;
            l2 = l2->next;
            dir = 0;
        }

        ans = ans->next;
    }

    // Modify the original linked list to the reordered list
    head->next = ans->next;
}

int main() {
    // Create the linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Reorder the linked list: 1 -> 5 -> 2 -> 4 -> 3
    reorderList(head);

    // Print the reordered linked list
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    // Deallocating memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
