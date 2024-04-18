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

    // Reverse a linked list
    void reverse(Node **head) {
        Node* current = *head;
        Node* prev = NULL;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *head = prev;
    }

    
};

int main() {
    Node* head = NULL;
    LinkedList* list = new LinkedList();

    list->pushNode(&head, 4);
    list->pushNode(&head, 5);
    list->pushNode(&head, 32);

    cout << "Original linked list: ";
    list->printList(head);

    cout << "\nMiddle element: ";
    list->printMiddle(head);

    cout << "Reversed linked list: ";
    list->reverse(&head);
    list->printList(head);


    return 0;
}