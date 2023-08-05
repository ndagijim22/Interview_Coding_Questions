#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;

    Node(int value) : data(value), next(NULL) {} // Constructor
}Node;

// Prints linked list
void printList(Node* n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

//Delete from Beginning of list
void deleterFromBeginning(Node** headref){
    if(*headref == nullptr)
        return;
    
    Node* temp = *headref;
    *headref = (*headref)->next;
    delete temp;
}

//Delete from the end of the list
void deleteFromEnd(Node** headref){
    if(*headref == nullptr)
        return;
    
    //list has only one node
    if((*headref)->next == nullptr){
        delete (*headref);
        *headref = nullptr;
        return;
    }

    //list has more than one node
    Node* lastNode = *headref;
    Node* prev = nullptr;

    while(lastNode->next != nullptr){
        lastNode = lastNode->next;
        prev = lastNode;
    }

    prev->next = nullptr;
    delete lastNode;

}
        //     1. DELETE 

//Delete from the Middle of Linked list
void deleteFromMiddle(Node** headref, int val){
    if(*headref == nullptr)
        return;
    
    Node* curr = *headref;
    Node* prev = nullptr;

    while(curr->next != nullptr && curr->data != val){
        prev = curr;
        curr = curr->next;
    }

    //node with value not found
    if(curr == nullptr)
        return;
    
    //node with value is at the beginning
    if(prev == nullptr){
        *headref = curr->next;
    } else{
        prev->next = curr->next;
    }
    delete curr;
}

//Delete from the middle by position
void deleteFromMiddle(Node** headref, int pos){
    if(*headref == nullptr)
        return;
    
    Node* curr = *headref;
    Node* prev = nullptr;
    int currPos = 1;

    while(curr->next != nullptr && currPos != pos){
        prev = curr;
        curr = curr->next;
        currPos++;
    }

    //node with value not found
    if(curr == nullptr)
        return;
    
    //node with value is at the beginning
    if(prev == nullptr){
        *headref = curr->next;
    } else{
        prev->next = curr->next;
    }
    delete curr;
}
        //  2. INSERT

// insert at the front of the linked list
void insertFront(Node** headref, int newData){
     Node* newNode = new Node(newData);
     newNode->next = (*headref);
     (*headref) = newNode;
}

//insert at the end of the linked list
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

//insert after a given data
void insertAfterGivenNodeData(Node** headref, int newData){
    Node* newNode = new Node(newData);
    Node* currNode = *headref;
    Node* nextNode = nullptr;

    while(currNode->data != newData){
        currNode = currNode->next;
        nextNode = currNode->next;
    }

    currNode->next = newNode;
    newNode->next = nextNode;
}

//Insert after a given Node
void insertAfterGivenNode(Node** headref, Node* newNode){
    Node* currNode = *headref;
    Node* nextNode = nullptr;

    while(currNode->data != newNode->data){
        currNode = currNode->next;
        nextNode = currNode->next;
    }

    currNode->next = newNode;
    newNode->next = nextNode;
}

//insert in ascending order
void insertAscendingOrder(Node** headref, int newData){
    Node* newNode = new Node(newData);
    Node* currNode = *headref;
    Node* nextNode = nullptr;

    //loop
    while(currNode->data < newData){
        currNode = currNode->next;
        nextNode = currNode->next;
    }

    currNode->next = newNode;
    newNode->next = nextNode;

}

//Search in Linkedlist
void searchElement(Node* headref, int element){
    Node* curr = headref;
    //loop
    while(curr != nullptr){
        if(curr->data == element){
            cout << "Found it: " << curr->data << endl;
        }
        curr = curr->next;
    }
}

int main() {
    // Creating nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    // Linking the nodes to form a linked list
    head->next = second;
    second->next = third;

    // Printing the linked list
    cout << "Linked List: ";
    printList(head);

    // Deallocating memory
    delete head;
    delete second;
    delete third;

    return 0;
}
