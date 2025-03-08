#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Insert at the head
void insertAtHead(Node*& head, int val) {
    Node* n = new Node(val);
    
    if (head == nullptr) { // If list is empty
        head = n;
        return;
    }

    n->next = head;
    head->prev = n;
    head = n;
}

// Insert at the tail
void insertAtTail(Node*& head, int val) {
    if (head == nullptr) {
        insertAtHead(head, val);
        return;
    }

    Node* n = new Node(val);
    Node* temp = head;

    while (temp->next != nullptr) { // Traverse to the last node
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}

// Insert at a specific position (1-based index)
void insertAt(Node*& head, int pos, int val) {
    if (pos == 1) {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < pos - 1 && temp != nullptr) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of range.\n";
        return;
    }

    Node* n = new Node(val);
    n->next = temp->next;
    n->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = n;
    }
    
    temp->next = n;
}

// Delete from the head
void deleteAtHead(Node*& head) {
    if (head == nullptr) return;

    Node* toDelete = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete toDelete;
}

// Delete from the tail
void deleteAtTail(Node*& head) {
    if (head == nullptr) return;

    if (head->next == nullptr) { // Only one node
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) { // Traverse to the last node
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

// Delete at a specific position (1-based index)
void deleteAt(Node*& head, int pos) {
    if (head == nullptr) return;

    if (pos == 1) {
        deleteAtHead(head);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < pos && temp != nullptr) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of range.\n";
        return;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

    delete temp;
}

// Display the list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtHead(head, 5);

    cout << "Doubly Linked List: ";
    display(head);

    insertAt(head, 3, 15);  // Insert 15 at position 3
    cout << "After inserting 15 at position 3: ";
    display(head);

    deleteAt(head, 2);  // Delete node at position 2
    cout << "After deleting node at position 2: ";
    display(head);

    deleteAtHead(head);
    cout << "After deleting head: ";
    display(head);

    deleteAtTail(head);
    cout << "After deleting tail: ";
    display(head);

    return 0;
}

