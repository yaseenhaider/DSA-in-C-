#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* first = NULL;
Node* last = NULL;

void insert_start() {
    Node* p = new Node;
    cout << "Enter value: ";
    cin >> p->data;
    p->next = NULL;

    if (first == NULL) {
        first = last = p;
    } else {
        p->next = first;
        first = p;
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
int main() {
    insert_start();
    insert_start();
    insert_start();
    display();
    return 0;
}
