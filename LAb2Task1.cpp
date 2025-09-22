#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* first = NULL;
Node* last = NULL;

void insert_end(int value) {
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

void display() {
    Node* temp = first;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void display_reverse_loop() {
    if (first == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = first;
    int arr[100];
    int n = 0;

    while (temp != NULL) {
        arr[n++] = temp->data;
        temp = temp->next;
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " -> ";
    }
    cout << "NULL\n";
}

void display_reverse_recursive(Node* p) {
    if (p == NULL) return;
    display_reverse_recursive(p->next);
    cout << p->data << " -> ";
}

int main() {
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);

    cout << "Normal List:\n";
    display();

    cout << "\nReverse using loop:\n";
    display_reverse_loop();

    cout << "\nReverse using recursion:\n";
    display_reverse_recursive(first);
    cout << "NULL\n";

    return 0;
}
