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
    
    if (head == nullptr) {  // If list is empty
        head = n;
        head->next = head;
        head->prev = head;
        return;
    }

    Node* tail = head->prev;  // Get the last node
    n->next = head;
    n->prev = tail;
    tail->next = n;
    head->prev = n;
    head = n;  // Update head to new node
}

// Insert at the tail
void insertAtTail(Node*& head, int val) {
    if (head == nullptr) {
        insertAtHead(head, val);
        return;
    }

    Node* n = new Node(val);
    Node* tail = head->prev;

    tail->next = n;
    n->prev = tail;
    n->next = head;
    head->prev = n;
}

// Insert at a specific position (1-based index)
void insertAt(Node*& head, int pos, int val) {
    if (pos == 1) {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    int count = 1;

    // Traverse to the position before the desired position
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
    n->prev = temp;
    temp->next->prev = n;
    temp->next = n;
}

// Delete from the head
void deleteAtHead(Node*& head) {
    if (head == nullptr) return;

    if (head->next == head) {  // Only one node in list
        delete head;
        head = nullptr;
        return;
    }

    Node* tail = head->prev;
    Node* newHead = head->next;

    tail->next = newHead;
    newHead->prev = tail;

    delete head;
    head = newHead;  // Update head
}

// Delete from the tail
void deleteAtTail(Node*& head) {
    if (head == nullptr) return;

    if (head->next == head) {  // Only one node in list
        delete head;
        head = nullptr;
        return;
    }

    Node* tail = head->prev;
    Node* newTail = tail->prev;

    newTail->next = head;
    head->prev = newTail;

    delete tail;
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

    // Traverse to the node at the given position
    while (count < pos && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != pos) {
        cout << "Position out of range.\n";
        return;
    }

    Node* prevNode = temp->prev;
    Node* nextNode = temp->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete temp;
}

// Display the list
void display(Node* head) {
    if (head == nullptr) {
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
    Node* head = nullptr;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtHead(head, 5);

    cout << "Circular Doubly Linked List: ";
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

