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

// function to find multiple occurrences
void find_occurrences(Node* head, int key) {
    Node* temp = head;
    int pos = 1;
    bool found = false;

    cout << "Searching for " << key << "...\n";
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found at position: " << pos << endl;
            found = true;
        }
        temp = temp->next;
        pos++;
    }

    if (!found) {
        cout << "Value " << key << " not found in the list.\n";
    }
}

int main() {
    Node* first = NULL, *last = NULL;

    // list: 10 -> 20 -> 30 -> 20 -> 40 -> 20
    insert_end(first, last, 10);
    insert_end(first, last, 20);
    insert_end(first, last, 30);
    insert_end(first, last, 20);
    insert_end(first, last, 40);
    insert_end(first, last, 20);

    cout << "Linked List: ";
    display(first);

    find_occurrences(first, 20);
    find_occurrences(first, 50);

    return 0;
}
