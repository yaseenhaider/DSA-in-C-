#include <iostream>
using namespace std;

struct Nodetype {
    int data;
    Nodetype* next;
};

Nodetype* first = NULL;
Nodetype* last = NULL;

void insert_end() {

    Nodetype* p = new Nodetype;
    cout << "Enter the data in node: ";
    cin >> p->data;
    p->next = NULL;

    if (first == NULL) {
        first = last = p;
    }
    else {
        last->next = p;
        last = p;
    }
}
