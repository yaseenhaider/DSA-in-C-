#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// insert node at end (helper)
void insert_end(Node*& first, Node*& last, int value) {
    Node* p = new Node;
    p->data = value;
    p->next = NULL;

    if (first == NULL) {
        first = last = p;
    } else {
        last->next = p;
        last = p;
    }
}

// display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// merge two sorted linked lists
Node* merge_lists(Node* first1, Node* first2) {
    Node* first3 = NULL;
    Node* last3 = NULL;

    while (first1 != NULL && first2 != NULL) {
        if (first1->data <= first2->data) {
            insert_end(first3, last3, first1->data);
            first1 = first1->next;
        } else {
            insert_end(first3, last3, first2->data);
            first2 = first2->next;
        }
    }

    // copy remaining nodes
    while (first1 != NULL) {
        insert_end(first3, last3, first1->data);
        first1 = first1->next;
    }
    while (first2 != NULL) {
        insert_end(first3, last3, first2->data);
        first2 = first2->next;
    }

    return first3;  // head of merged list
}

int main() {
    Node* first1 = NULL; Node* last1 = NULL;
    Node* first2 = NULL; Node* last2 = NULL;

    // First list: 10 -> 30 -> 50
    insert_end(first1, last1, 10);
    insert_end(first1, last1, 30);
    insert_end(first1, last1, 50);

    // Second list: 20 -> 40 -> 60
    insert_end(first2, last2, 20);
    insert_end(first2, last2, 40);
    insert_end(first2, last2, 60);

    cout << "First List: ";
    display(first1);

    cout << "Second List: ";
    display(first2);

    Node* merged = merge_lists(first1, first2);

    cout << "Merged List: ";
    display(merged);

    return 0;
}
