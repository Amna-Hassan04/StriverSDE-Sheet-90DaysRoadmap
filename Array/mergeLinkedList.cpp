#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
};

class LinkedList {
public:
    Node *head = NULL;

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
    void insertLast(int val) {
        Node* new_node = new Node();
        Node* last = head;

        new_node->value = val;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            return;
        }
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
    }

    LinkedList merge(LinkedList first, LinkedList second, Node* hf, Node* hs) {
        Node* f = hf;
        Node* s = hs;

        LinkedList ans;
        while (f != NULL && s != NULL) {
            if (f->value < s->value) {
                ans.insertLast(f->value);
                f = f->next;
            }
            else {
                ans.insertLast(s->value);
                s = s->next;
            }
        }

        while (f != NULL) {
            ans.insertLast(f->value);
            f = f->next;
        }
        while (s != NULL) {
            ans.insertLast(s->value);
            s = s->next;
        }

        return ans;
    }

    void sortList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node* current = head;
    Node* index = NULL;
    int temp;

    while (current != NULL) {
        index = current->next;

        while (index != NULL) {
            if (current->value > index->value) {
                temp = current->value;
                current->value = index->value;
                index->value = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}
};


int main() {
    Node* head = NULL;
    LinkedList* list = new LinkedList();

    LinkedList* list1 = new LinkedList();
    LinkedList* list2 = new LinkedList();

    /*list->pushNode(&head, 4);
    list->pushNode(&head, 4);
    list->pushNode(&head, 4);
    list->pushNode(&head, 5);
    list->pushNode(&head, 32); */

    list1->pushNode(&(list1->head), 3);
    list1->pushNode(&(list1->head), 7);
    list1->pushNode(&(list1->head), 4);

    list2->pushNode(&(list2->head), 2);
    list2->pushNode(&(list2->head), 9);
    list2->pushNode(&(list2->head), 6);


    cout << "\nMerge lists: ";
    LinkedList ans = list->merge(*list1, *list2, list1->head, list2->head);
    ans.sortList(ans.head);
    ans.printList(ans.head);

    return 0;
}