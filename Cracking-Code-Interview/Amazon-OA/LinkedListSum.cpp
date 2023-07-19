/*
    Link:https://leetcode.com/discuss/interview-question/1546673/Amazon-or-OA-or-LinkedListSum
    Given a singly linkedlist like:
    1->4->3->2
    You have to calculate the sum of first and last elements like:
    1+2 = 3
    4+3 = 7
    Then output the maximum sum. Here maximum sum is 7.

    Space complexity should be O(1).
    No constraint on time complexity.
*/
// #include <iostream>
// #include <climits> 

// using namespace std;
// struct ListNode {
//     int val;
//     struct ListNode* next;

//     ListNode(int val) : val(val), next(nullptr) {}
// }; 

// int max_val;
// ListNode* tmp;

// void maxPair(ListNode* p) {
//     if (p == NULL) {
//         return;
//     }
//     maxPair(p->next);
//     max_val = max(max_val, p->val + tmp->val);
//     tmp = tmp->next;
// }

// void solve(ListNode* head) {
//     max_val = INT_MIN;
//     tmp = head;
//     maxPair(head);
//     cout << "Result is " << max_val << "\n";
// }

// int main() {
//     ListNode* head = new ListNode(1);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(3);
//     head->next->next->next = new ListNode(4);
//     head->next->next->next->next = new ListNode(9);
//     head->next->next->next->next->next = new ListNode(11);
//     solve(head);

//     return 0;
// }

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

int maxLinkedListSum(ListNode* list) {
    if (list == nullptr) 
        return 0;

    if (list->next == nullptr) 
        return list->val;

    ListNode* slow = list;
    ListNode* fast = list;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* first = list;
    
    // Reverse here because you don't want to save this result in a variable as it's O(1) space needed.
    ListNode* prev = nullptr;
    while (slow != nullptr) {
        ListNode* nextNode = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nextNode;
    }

    int maxSum = INT_MIN;
    while (first != nullptr && prev != nullptr) {
        maxSum = max(maxSum, first->val + prev->val);
        first = first->next;
        prev = prev->next;
    }
    return maxSum;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(11);

    int result = maxLinkedListSum(head);
    cout << "Max Linked List Sum: " << result << endl;

    return 0;
}
