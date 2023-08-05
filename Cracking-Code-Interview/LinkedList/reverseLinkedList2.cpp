/*
    Reverse linked list from position m to n. Do it in one pass
    ex:
        input: 1->2->3->4->5->NULL, m = 2, n = 4
        output: 1->4->3->2->5->NULL
*/
#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next;
    
    Node(int val): data(val), next(nullptr) {}
};

// Reverses the portion of the linked list from m-th node to n-th node and 
//returns the new head
Node* reverseNode2(Node* head, int m, int n) {
    Node* curr = head; // Pointer to traverse the linked list
    Node* start = nullptr; // Pointer to store the node before the m-th node

    // Move the curr pointer to the m-th node and update m and n accordingly
    while (m > 1) {
        start = curr;
        curr = curr->next;
        m--;
        n--;
    }

    Node* tail = curr; // Pointer to store the node after the n-th node
    Node* prev = nullptr; // Pointer to keep track of the previous node during reversal

    // Reverse the portion of the linked list from m-th node to n-th node
    // cout << "Value of n before while loop: " << n << endl;
    while (n > 0) {
        Node* next = curr->next; // Store the next node
        curr->next = prev; // Reverse the link, pointing to the previous node
        prev = curr; // Move prev one step forward
        curr = next; // Move curr one step forward
        n--;
    }

    // If start is not null, it means m is greater than 1, so update 
    //the next pointer of the node before m-th node
    // Otherwise, update the head to be the new head after the reversal
    if (start != nullptr)
        start->next = prev;
    else
        head = prev;

    tail->next = curr; // Connect the n-th node to the node after the reversed portion

    return head; // Return the new head of the linked list after reversal
}

//print the linked list
void printList(Node* head){
    Node* current = head;
    while(current != nullptr){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
//Insert Node
void insertEnd(Node** headref, int newData){
    Node* newNode = new Node(newData);

    //if list empty
    if(*headref == nullptr){
        (*headref) = newNode;
    }
    else {
        Node* lastNode = *headref;
        //loop thru search for the last node in the list
        while(lastNode->next != nullptr){
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

//Driver code
int main() {
    // Creating nodes
    Node* head = new Node{1};
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);

    // Printing the original linked list
    cout << "Original Linked List: ";
    printList(head);

    int m = 2; // Starting index for reversal
    int n = 4; // Ending index for reversal

    // Reversing the linked list from m-th node to n-th node
    head = reverseNode2(head, m, n);

    // Printing the updated linked list
    cout << "Updated Linked List: ";
    printList(head);

    //Deallocating memory
    while(head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
