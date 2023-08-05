//Given a linked list determine if it has a cycle in it
/*
    Algo:
    1. traverse the list using two pinters approach.
    2. At any time if the slow pointer has caught up to the fast pointer then the llist has a cycle
    3. Otherwise , if the fast pointer traverse the end of the list. then there is no cyle.
*/
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

bool hasCycle(Node* head) {
    if(head == nullptr || head->next == nullptr)
        return false;

    Node* slowPtr = head;
    Node* fastPtr = head;
    bool ans = false;

    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        slowPtr = slowPtr->next;             
        fastPtr = fastPtr->next->next;
        //detect cycle
        if(slowPtr == fastPtr){
            ans = true;
            break;
        }   
    }

    return ans;
}