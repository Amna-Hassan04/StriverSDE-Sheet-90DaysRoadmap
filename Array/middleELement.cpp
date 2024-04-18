#include <iostream>
using namespace std;





class Node {
public:
    int value;
    Node* next;
};

class LinkedList {
public:
    
    void pushNode(Node** headref, int val) {
        Node* newNode = new Node();
        newNode->value = val;
        newNode->next = *headref;
        *headref = newNode;
    }

    void printList(Node* headref) {
        while (headref != NULL) {
            cout << headref->value << " -> ";
            headref = headref->next;
        }
        cout << "NULL ";
    }

    void printMiddle(Node* head) {
        Node* slowPtr = head;
        Node* fastPtr = head;

        while (fastPtr != NULL && fastPtr->next != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        cout << "The middle element is: " << slowPtr->value << endl;
    }

    void removeDuplicates(Node *head){
        Node *node = head;
    
         while(node->next != NULL){
        if(node->value == node->next->value){
            node->next = node->next->next;
        }
        else{
            node = node->next;
        }
    }
    
    }

    
};

int main() {
    Node* head = NULL;
    LinkedList* list = new LinkedList();

    list->pushNode(&head, 4);
    list->pushNode(&head, 4);
    list->pushNode(&head, 4);

    list->pushNode(&head, 4);
    list->pushNode(&head, 4);

    list->pushNode(&head, 4);
    list->pushNode(&head, 4);
    list->pushNode(&head, 5);
    list->pushNode(&head, 32);

    cout << "Original linked list: ";
    list->printList(head);

    cout << "\nMiddle element: ";
    list->removeDuplicates(head);
    list->printMiddle(head);
    list->printList(head);




    return 0;
}