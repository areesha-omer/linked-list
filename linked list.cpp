#include <iostream>
#include <cstddef> // For nullptr
using namespace std;

// Node structure definition
struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

// Function prototypes
void insert_begin(Node*& head, int d);
void insert_end(Node*& head, int d);
void insert_at(Node*& head, int d, int position);
void delete_begin(Node*& head);
void delete_end(Node*& head);
void delete_at(Node*& head, int position);
void delete_data(Node*& head, int d);
void traverse(Node* head);
Node* search(Node* head, int d);
void reverse(Node*& head);
void sort(Node*& head);
int size(Node* head);

int main() {
    Node* head = nullptr; // Initialize the linked list
    int choice, data, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete at position\n";
        cout << "7. Delete by data\n";
        cout << "8. Traverse\n";
        cout << "9. Search\n";
        cout << "10. Reverse\n";
        cout << "11. Sort\n";
        cout << "12. Size\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                insert_begin(head, data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                insert_end(head, data);
                break;
            case 3:
                cout << "Enter data: ";
cin >> data;
                cout << "Enter position: ";
                cin >> position;
                insert_at(head, data, position);
                break;
            case 4:
                delete_begin(head);
                break;
            case 5:
                delete_end(head);
                break;
            case 6:
                cout << "Enter position: ";
                cin >> position;
                delete_at(head, position);
                break;
            case 7:
                cout << "Enter data to delete: ";
                cin >> data;
                delete_data(head, data);
                break;
            case 8:
                traverse(head);
                break;
            case 9:
                cout << "Enter data to search: ";
                cin >> data;
                if (Node* result = search(head, data)) {
                    cout << "Data found at address: " << result << endl;
                } else {
                	cout << "Data not found." << endl;
                }
                break;
            case 10:
                reverse(head);
                break;
            case 11:
                sort(head);
                break;
            case 12:
                cout << "Size of linked list: " << size(head) << endl;
                break;
            case 13:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 13);

    return 0;
}

// Function implementations
void insert_begin(Node*& head, int d) {
    Node* new_node = new Node(d);
    new_node->next = head;
    head = new_node;
}
void insert_end(Node*& head, int d) {
    Node* new_node = new Node(d);
    if (!head) {
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert_at(Node*& head, int d, int position) {
    if (position <= 0 || !head) {
        insert_begin(head, d);
        return;
    }
    Node* new_node = new Node(d);
    Node* temp = head;
    for (int i = 1; temp && i < position; ++i) {
        temp = temp->next;
    }
    if (!temp) {
        cout << "Position out of bounds, inserting at end.\n";
        insert_end(head, d);
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_begin(Node*& head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void delete_end(Node*& head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void delete_at(Node*& head, int position) {
    if (position <= 0 || !head) {
        delete_begin(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp->next && i < position; ++i) {
        temp = temp->next;
    }
    if (!temp->next) {
        cout << "Position out of bounds.\n";
        return;
    }
        Node* to_delete = temp->next;
    temp->next = to_delete->next;
    delete to_delete;
}

void delete_data(Node*& head, int d) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == d) {
        delete_begin(head);
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != d) {
        temp = temp->next;
    }
    if (!temp->next) {
        cout << "Data not found.\n";
        return;
    }
    Node* to_delete = temp->next;
    temp->next = to_delete->next;
    delete to_delete;
}

void traverse(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
        }
    cout << "NULL\n";
}

Node* search(Node* head, int d) {
    while (head) {
        if (head->data == d) {
            return head;
        }
        head = head->next;
    }
    return nullptr;
}

void reverse(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void sort(Node*& head) {
    if (!head || !head->next) return;
    for (Node* i = head; i; i = i->next) {
        for (Node* j = i->next; j; j = j->next) {
            if (i->data > j->data) {
                swap(i->data, j->data);
            }
        }
         }
}

int size(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

