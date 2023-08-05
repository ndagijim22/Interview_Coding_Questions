//reverse a linkedlist

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution{
    public:
        ListNode* reverseList(ListNode* head){
            ListNode* prev = nullptr;
            ListNode* curr = head;

            while (curr != nullptr){
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            return prev;
        }
};