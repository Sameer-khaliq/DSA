#include <iostream>
using namespace std;

class node {
public:
    int value;
    node *previous;
    node *next;
    node(int val) {
        value = val;
        next = NULL;
        previous = NULL;
    }
};

class doublycircularlist {
public:
    node *head, *tail;
    doublycircularlist() {
        head = NULL;
        tail = NULL;
    }

    void create() {
        int value, n;
        cout << "How many elements to add??: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Enter value for node " << i + 1 << ": ";
            cin >> value;
            node *temp = new node(value);
            if (head == NULL) {
                head = tail = temp;
                head->next = head;
                head->previous = head;
            } else {
                tail->next = temp;
                temp->previous = tail;
                temp->next = head;   // Circular Link
                head->previous = temp; // Circular Link
                tail = temp;
            }
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!";
            return;
        }
        node *temp = head;
        do {
            cout << temp->value << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void insert_at_start() {
        int value;
        cout << "Enter value at start: ";
        cin >> value;
        node *temp = new node(value);
        if (head == NULL) {
            head = tail = temp;
            head->next = head;
            head->previous = head;
        } else {
            temp->next = head;
            temp->previous = tail;
            head->previous = temp;
            tail->next = temp;
            head = temp;
        }
    }

    void insert_at_end() {
        int value;
        cout << "Enter value at end: ";
        cin >> value;
        node *temp = new node(value);
        if (head == NULL) {
            head = tail = temp;
            head->next = head;
            head->previous = head;
        } else {
            tail->next = temp;
            temp->previous = tail;
            temp->next = head;
            head->previous = temp;
            tail = temp;
        }
    }

    void insert_at_specific() {
        int position, value, count = 1;
        cout << "Enter position: "; cin >> position;
        if (position == 1) { insert_at_start(); return; }

        cout << "Enter value: "; cin >> value;
        node *temp = new node(value);
        node *curr = head;
        
        while (count < position - 1 && curr->next != head) {
            curr = curr->next;
            count++;
        }
        
        temp->next = curr->next;
        temp->previous = curr;
        curr->next->previous = temp;
        curr->next = temp;
        
        if (curr == tail) tail = temp;
    }

   void delete_at_start() {
    if (head == NULL) return;
    node *temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        node *curr = head;
        do {
            curr = curr->next;
        } while (curr != head);

        head = head->next;
        head->previous = tail;
        tail->next = head;
    }
    delete temp;
}

void delete_at_end() {
    if (head == NULL) return;
    node *temp = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        node *curr = head;
        do {
            curr = curr->next;
        } while (curr->next != head);

        tail = curr->previous;
        tail->next = head;
        head->previous = tail;
    }
    delete temp;
}

void delete_at_specific() {
    if (head == NULL) return;
    int position, count = 1;
    cout << "Enter position to delete: ";
    cin >> position;
    if (position == 1) { 
        delete_at_start(); 
        return; 
    }

    node *curr = head;
    do {
        curr = curr->next;
        count++;
    } while (count < position && curr != head);

    if (curr == head) return;

    if (curr == tail) { 
        delete_at_end(); 
        return; 
    }

    curr->previous->next = curr->next;
    curr->next->previous = curr->previous;
    delete curr;
}


    void search() {
        if (head == NULL) return;
        int target, position = 1;
        bool isfound = false;
        cout << "Enter target: ";
        cin >> target;
        node* temp = head;
        do {
            if (temp->value == target) {
                cout << "Target found at position: " << position << endl;
                isfound = true;
            }
            temp = temp->next;
            position++;
        } while (temp != head);
        if (!isfound) cout << "Target not found!";
    }
};

int main() {
    doublycircularlist d;
    int choice;
        do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Create Doubly Circular Linked List\n";
        cout << "2. Insert Node\n";
        cout << "3. Delete Node\n";
        cout << "4. Display List\n";
        cout << "5. Search in List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                d.create();
                break;
            case 2:
                int insert_choice;
                do {
                    cout << "\n--- INSERTION MENU ---\n";
                    cout << "1. Insert at Start\n";
                    cout << "2. Insert at End\n";
                    cout << "3. Insert at Specific Position\n";
                    cout << "0. Back to Main Menu\n";
                    cout << "Enter choice: ";
                    cin >> insert_choice;

                    switch (insert_choice) {
                        case 1:
                            d.insert_at_start();
                            break;
                        case 2:
                            d.insert_at_end();
                            break;
                        case 3:
                            d.insert_at_specific();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Invalid option!\n";
                    }
                } while (insert_choice != 0);
                break;
            case 3: {
                int delete_choice;
                do {
                    cout << "\n--- DELETION MENU ---\n";
                    cout << "1. Delete at Start\n";
                    cout << "2. Delete at End\n";
                    cout << "3. Delete at Specific Position\n";
                    cout << "0. Back to Main Menu\n";
                    cout << "Enter choice: ";
                    cin >> delete_choice;

                    switch (delete_choice) {
                        case 1:
                            d.delete_at_start();
                            break;
                        case 2:
                            d.delete_at_end();
                            break;
                        case 3:
                            d.delete_at_specific();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Invalid option!\n";
                    }
                } while (delete_choice != 0);
                break;
            }
            case 4:
                d.display();
                break;
            case 5:
                d.search();
                break;
            case 0:
                cout << "Exiting program.... bye!";
                break;
            default:
                cout << "Invalid option!";
        }
    } while (choice != 0);
    return 0;
}

