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

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // 1. INSERT AT START (Head)
    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at the start.\n";
    }

    // 2. INSERT AT END (Tail)
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted " << val << " at the end.\n";
    }

    // 3. INSERT AT SPECIFIC POSITION
    void insertAtPosition(int val, int pos) {
        if (pos < 1) {
            cout << "Invalid position!\n";
            return;
        }

        if (pos == 1) {
            insertAtStart(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        // Move to the node at (pos - 1)
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of bounds!\n";
            delete newNode; // Clean up memory
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << val << " at position " << pos << ".\n";
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);     // 10
    list.insertAtEnd(20);     // 10 -> 20
    list.insertAtStart(5);    // 5 -> 10 -> 20
    list.insertAtPosition(15, 3); // 5 -> 10 -> 15 -> 20

    cout << "Final List: ";
    list.display();

    return 0;
}