#include <iostream>
using namespace std;
class node {
public:
    int value;
    node *next;
    node(int val) {
        value = val;
        next = NULL;
    }
};
class list {
public:
    node *head, *tail;
    list() {
        head = NULL;
        tail = NULL;
    }
    void create() {
        int n, val;
        cout << "Kitne elements add karne hain: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Element " << i + 1 << " enter karein: ";
            cin >> val;
            node *temp = new node(val);
            if (head == NULL) {
                head = temp;
                tail = temp;
                tail->next = head;
            } else {
                tail->next = temp;
                tail = temp;
                tail->next = head;
            }
        }
    }
    void display() {
        if (head == NULL) {
            cout << "List empty hai!" << endl;
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
        int new_value;
        cout << "Enter value at start: ";
        cin >> new_value;
        node *temp = new node(new_value);
        if (head == NULL) {
            head = tail = temp;
            temp->next = head;
        } else {
            temp->next = head;
            head = temp;
            tail->next = head; 
        }
    }
    void insertion_at_last() {
        int new_value;
        cout << "Enter value at end: ";
        cin >> new_value;
        node *temp = new node(new_value);
        if (head == NULL) {
            head = tail = temp;
            temp->next = head;
        } else {
            tail->next = temp;
            tail = temp;
            tail->next = head; 
        }
    }
    void insert_at_specific() {
        int position, val, count = 1;
        cout << "Enter position: ";
        cin >> position;
        if (position == 1) { insert_at_start();
             return; }      
        cout << "Enter value: ";
        cin >> val;
        node *temp = new node(val);
        node *curr = head;
        while (count < position - 1 && curr->next != head) {
            curr = curr->next;
            count++;
        }
        temp->next = curr->next;
        curr->next = temp;
        if (curr == tail) tail = temp;
    }
    void delete_at_start() {
    if (head == NULL) return;

    if (head == tail) {
        delete head;
        head = tail = NULL;
    } 
    else {
        node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }
}

void delete_at_end() {
    if (head == NULL) return;

    if (head == tail) {
        delete head;
        head = tail = NULL;
    } 
    else {
        node *curr = head;
        do {
            curr = curr->next;
        } while (curr->next != tail);

        delete tail;
        tail = curr;
        tail->next = head;
    }
}

void delete_at_specific() {
    if (head == NULL) return;

    int position;
    cout << "Enter position to delete: ";
    cin >> position;

    if (position == 1) {
        delete_at_start();
        return;
    }

    node *curr = head;
    node *prev = NULL;
    int count = 1;
    do {
        prev = curr;
        curr = curr->next;
        count++;

        if (count == position)
            break;

    } while (curr != head);
    if (count != position) {
        cout << "Invalid Position\n";
        return;
    }

    prev->next = curr->next;

    if (curr == tail)
        tail = prev;

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
        if (!isfound) cout << "Target not found!" << endl;
    }
};
int main() {
    list l;
    int choice;
       do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Create Circular Linked List\n";
        cout << "2. Insert Node\n";
        cout << "3. Delete Node\n";
        cout << "4. Display List\n";
        cout << "5. Search Value\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                l.create();
                break;
            case 2: {
                int insert_choice;
                do {
                    cout << "\n--- INSERT MENU ---\n";
                    cout << "1. Insert at Start\n";
                    cout << "2. Insert at End\n";
                    cout << "3. Insert at Position\n";
                    cout << "0. Back to Main Menu\n";
                    cout << "Enter choice: ";
                    cin >> insert_choice;

                    switch (insert_choice) {
                        case 1:
                            l.insert_at_start();
                            break;
                        case 2:
                            l.insertion_at_last();
                            break;
                        case 3:
                            l.insert_at_specific();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Invalid option!\n";
                    }
                } while (insert_choice != 0);
                break;
            }
            case 3: {
                int delete_choice;
                do {
                    cout << "\n--- DELETION MENU ---\n";
                    cout << "1. Delete at Start\n";
                    cout << "2. Delete at End\n";
                    cout << "3. Delete at specific Position\n";
                    cout << "0. Back to Main Menu\n";
                    cout << "Enter choice: ";
                    cin >> delete_choice;

                    switch (delete_choice) {
                        case 1:
                            l.delete_at_start();
                            break;
                        case 2:
                            l.delete_at_end();
                            break;
                        case 3:
                            l.delete_at_specific();
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
                l.display();
                break;
            case 5:
                l.search();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid option!\n";
        }
    } while (choice != 0);
    return 0;
}

