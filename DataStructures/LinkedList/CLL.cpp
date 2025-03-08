#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert at the head
void insertAtHead(Node*& head, int val) {
    Node* n = new Node(val);
    
    if (head == NULL) {  // If list is empty
        n->next = n;
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {  // Traverse to the last node
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;  // Update head
}

// Insert at the tail
void insertAtTail(Node*& head, int val) {
    if (head == NULL) {
        insertAtHead(head, val);
        return;
    }

    Node* n = new Node(val);
    Node* temp = head;

    while (temp->next != head) {  // Traverse to the last node
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

// Insert at a specific position (1-based index)
void insertAt(Node*& head, int pos, int val) {
    if (pos == 1) {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        cout << "Position out of range.\n";
        return;
    }

    Node* n = new Node(val);
    n->next = temp->next;
    temp->next = n;
}

// Delete from the head
void deleteAtHead(Node*& head) {
    if (head == NULL) return;

    if (head->next == head) {  // Only one node
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {  // Find last node
        temp = temp->next;
    }

    Node* toDelete = head;
    temp->next = head->next;
    head = head->next;

    delete toDelete;
}

// Delete from the tail
void deleteAtTail(Node*& head) {
    if (head == NULL) return;

    if (head->next == head) {  // Only one node
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != head) {  // Find second last node
        temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = head;
    delete toDelete;
}

// Delete at a specific position (1-based index)
void deleteAt(Node*& head, int pos) {
    if (head == NULL) return;

    if (pos == 1) {
        deleteAtHead(head);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1 || temp->next == head) {
        cout << "Position out of range.\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// Display the list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtHead(head, 5);

    cout << "Singly Circular Linked List: ";
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

