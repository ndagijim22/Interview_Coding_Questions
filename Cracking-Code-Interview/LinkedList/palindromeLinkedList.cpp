#include <iostream>

using namespace std;

// Definition of a singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse a linked list
ListNode* reverseList(ListNode* head) {
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
//Find middle node in linked list
ListNode* findMid(ListNode* head) {
   
    ListNode* slowPtr = head;
    ListNode* fastPtr = head;


    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        slowPtr = slowPtr->next;            
        fastPtr = fastPtr->next->next;     
    }
    return slowPtr;
}

//      ******BRUTE FORCE (It uses extra space O(n))*******

// Function to check if a linked list is a palindrome
bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; // An empty list or a single node list is considered a palindrome
    }

    // Step 1: Create a new Linked List Copy (deep copy)
    ListNode* copyHead = new ListNode(head->val);
    ListNode* copyPtr = copyHead;
    ListNode* curr = head->next;

    while (curr != nullptr) {
        copyPtr->next = new ListNode(curr->val);
        copyPtr = copyPtr->next;
        curr = curr->next;
    }

    // Step 2: Reverse the Copy
    ListNode* reversedCopyHead = reverseList(copyHead);

    // Step 3: Traverse both the Lists simultaneously and check for equality
    curr = head;
    ListNode* reversedCurr = reversedCopyHead;
    while (curr != nullptr && reversedCurr != nullptr) {
        if (curr->val != reversedCurr->val) {
            return false; // If the values are not equal at any point, it is not a palindrome
        }
        curr = curr->next;
        reversedCurr = reversedCurr->next;
    }

    // Step 4: If we reach the end of both the lists, then it is a palindrome
    return true;
}

// ******* OPTIMIZED SOLUTION ******
bool isPalindrome1(ListNode* head) {
    // If the linked list is empty or has only one element, it is considered a palindrome
    if (head == nullptr || head->next == nullptr)
        return true;
    
    // Find the middle node of the linked list
    ListNode* mid = findMid(head);

    // Split the linked list into two halves, starting from the middle node
    ListNode* r = mid->next; // 'r' will be the head of the second half
    mid->next = nullptr;     // Set the next of the middle node to nullptr to separate the two halves
    ListNode* l = head;      // 'l' is the head of the first half

    // Reverse the second half of the linked list
    r = reverseList(r);

    // Compare the two halves of the linked list to check for palindrome
    bool result = true;
    while (l != nullptr && r != nullptr) {
        // If the values of corresponding nodes in the two halves are not equal, it's not a palindrome
        if (r->val != l->val)
            return false;
        
        // Move to the next nodes in both halves
        l = l->next;
        r = r->next;
    }

    // If the loop completes without returning false, the linked list is a palindrome
    return result;
}

// Function to delete the linked list to free memory
void deleteLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Example Usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    // head->next->next->next->next = new ListNode(1);

    bool isPalindromeResult = isPalindrome(head);
    cout << "Is llist palindrome? " << (isPalindromeResult ? "Yes" : "No")<< endl;
    cout << "***************\n";
    bool isPalindromeResult1 = isPalindrome1(head);
    cout << "Is llist palindrome? " << (isPalindromeResult1 ? "Yes" : "No")<< endl;

    // Clean up the linked list memory
    deleteLinkedList(head);

    return 0;
}

