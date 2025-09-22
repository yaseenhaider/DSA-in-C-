#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert_end(int value) {
    Node* p = new Node;
    p->data = value;
    p->next = NULL;

    if (head == NULL) {
        head = p;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void delete_first() {
    if (head == NULL) {
        cout << "Empty linked list\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "First node deleted\n";
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insert_end(10);
    insert_end(20);
    insert_end(30);

    cout << "Before deletion:\n";
    display();

    delete_first();

    cout << "After deletion:\n";
    display();

    return 0;
}
