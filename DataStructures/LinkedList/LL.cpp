#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Insert at the head
void insertAtHead(Node*& head, int val) {
    Node* n = new Node(val);
    n->next = head;
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
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = n;
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
    temp->next = n;
}

// Delete from the head
void deleteAtHead(Node*& head) {
    if (head == nullptr) return;

    Node* toDelete = head;
    head = head->next;
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
    while (temp->next->next != nullptr) { // Traverse to second last node
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
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

    while (count < pos - 1 && temp->next != nullptr) {
        temp = temp->next;
        count++;
    }

    if (temp->next == nullptr) {
        cout << "Position out of range.\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// Delete by Value
void deleteByValue(Node*& head, int val) {
    if (head == nullptr) return;

    // If head node needs to be deleted
    if (head->data == val) {
        deleteAtHead(head);
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Value " << val << " not found in the list.\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
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

    cout << "Singly Linked List: ";
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

    deleteByValue(head, 15);
    cout << "After deleting node with value 15: ";
    display(head);

    return 0;
}

