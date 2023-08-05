#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    // Check if either of the input linked lists is empty
    if (headA == nullptr || headB == nullptr)
        return nullptr;

    ListNode* a = headA; // Pointer for traversing linked list A
    ListNode* b = headB; // Pointer for traversing linked list B

    // Traverse both linked lists until they intersect (a == b)
    while (a != b) {
        // If a reaches the end of list A, move it to the head of list B, otherwise move to the next node in list A
        a = a == nullptr ? headB : a->next;

        // If b reaches the end of list B, move it to the head of list A, otherwise move to the next node in list B
        b = b == nullptr ? headA : b->next;
    }

    // Return the intersection node (a or b) or nullptr if no intersection is found
    return a;
}

int main() {
    // Creating linked list A: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    // Creating linked list B: 6 -> 7 -> 8
    ListNode* headB = new ListNode(6);
    headB->next = new ListNode(7);
    headB->next->next = new ListNode(8);

    // Making them intersect at node with value 4
    headB->next->next->next = headA->next->next->next;

    // Finding the intersection node
    ListNode* intersectionNode = getIntersectionNode(headA, headB);

    if (intersectionNode != nullptr) {
        std::cout << "Intersection node value: " << intersectionNode->val << std::endl;
    } else {
        std::cout << "No intersection found." << std::endl;
    }

    // Deallocating memory
    delete headA->next->next->next->next;
    delete headA->next->next->next;
    delete headA->next->next;
    delete headA->next;
    delete headA;

    delete headB->next->next;
    delete headB->next;
    delete headB;

    return 0;
}
