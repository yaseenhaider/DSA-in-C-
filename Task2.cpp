#include <iostream>
using namespace std;

#define MAX 100

class ArrayList {
private:
    int arr[MAX]{};
    int size;

public:
    ArrayList() { size = 0; }

    void insertAtEnd(int value) {
        if (size >= MAX) {
            cout << "List is full!" << endl;
            return;
        }
        arr[size++] = value;
    }


    void insertAtStart(int value) {
        if (size >= MAX) {
            cout << "List is full!" << endl;
            return;
        }
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        size++;
    }

    void insertAfterValue(int value, int after) {
        int pos = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == after) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << "Value " << after << " not found!" << endl;
            return;
        }
        if (size >= MAX) {
            cout << "List is full!" << endl;
            return;
        }
        for (int i = size; i > pos + 1; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos + 1] = value;
        size++;
    }


    void insertBeforeValue(int value, int before) {
        int pos = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == before) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << "Value " << before << " not found!" << endl;
            return;
        }
        if (size >= MAX) {
            cout << "List is full!" << endl;
            return;
        }
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
        size++;
    }

    void display() const;

    void deleteFromEnd() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        size--;
    }


    void deleteFromStart() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }


    void deleteValue(int value) {
        int pos = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << "Value " << value << " not found!" << endl;
            return;
        }
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
};

void ArrayList::display() const {
    if (size == 0) {
        cout << "List is empty!" << endl;
        return;
    }
    cout << "Array List: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    ArrayList list;
    int choice, value, ref;

    while (true) {
        cout << "\n--- Array List Menu ---\n";
        cout << "1. Insert at end\n";
        cout << "2. Insert at start\n";
        cout << "3. Insert after specific value\n";
        cout << "4. Insert before specific value\n";
        cout << "5. Display list\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete from start\n";
        cout << "8. Delete specific value\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtStart(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter value after which to insert: ";
                cin >> ref;
                list.insertAfterValue(value, ref);
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter value before which to insert: ";
                cin >> ref;
                list.insertBeforeValue(value, ref);
                break;
            case 5:
                list.display();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                list.deleteFromStart();
                break;
            case 8:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteValue(value);
                break;
            case 9:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}
