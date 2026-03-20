#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int coeff;
    int exp;
    Node* next;

    Node(int c, int e) {
        coeff = c;
        exp = e;
        next = NULL;
    }
};

class Polynomial {
    Node* head;

public:
    Polynomial() {
        head = NULL;
    }

    void insert(int c, int e) {
        Node* newNode = new Node(c, e);

        if (head == NULL || head->exp < e) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            Node* prev = NULL;

            while (temp != NULL && temp->exp > e) {
                prev = temp;
                temp = temp->next;
            }

            if (temp != NULL && temp->exp == e) {
                temp->coeff += c;
                delete newNode;
            } else {
                newNode->next = temp;
                prev->next = newNode;
            }
        }
    }

    void input() {
        int n, c, e;
        cout << "Enter number of terms: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Term " << (i + 1) << "\n";
            cout << "  Enter coefficient: ";
            cin >> c;
            cout << "  Enter exponent: ";
            cin >> e;
            insert(c, e);
        }
    }

    void display() {
        if (head == NULL) {
            cout << "0";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->coeff << "x^" << temp->exp;
            if (temp->next != NULL)
                cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }

    Polynomial add(Polynomial p) {
        Polynomial result;
        Node* t1 = head;
        Node* t2 = p.head;

        while (t1 != NULL && t2 != NULL) {
            if (t1->exp == t2->exp) {
                result.insert(t1->coeff + t2->coeff, t1->exp);
                t1 = t1->next;
                t2 = t2->next;
            } else if (t1->exp > t2->exp) {
                result.insert(t1->coeff, t1->exp);
                t1 = t1->next;
            } else {
                result.insert(t2->coeff, t2->exp);
                t2 = t2->next;
            }
        }

        while (t1 != NULL) {
            result.insert(t1->coeff, t1->exp);
            t1 = t1->next;
        }

        while (t2 != NULL) {
            result.insert(t2->coeff, t2->exp);
            t2 = t2->next;
        }

        return result;
    }

    Polynomial subtract(Polynomial p) {
        Polynomial result;
        Node* t1 = head;
        Node* t2 = p.head;

        while (t1 != NULL && t2 != NULL) {
            if (t1->exp == t2->exp) {
                result.insert(t1->coeff - t2->coeff, t1->exp);
                t1 = t1->next;
                t2 = t2->next;
            } else if (t1->exp > t2->exp) {
                result.insert(t1->coeff, t1->exp);
                t1 = t1->next;
            } else {
                result.insert(-t2->coeff, t2->exp);
                t2 = t2->next;
            }
        }

        while (t1 != NULL) {
            result.insert(t1->coeff, t1->exp);
            t1 = t1->next;
        }

        while (t2 != NULL) {
            result.insert(-t2->coeff, t2->exp);
            t2 = t2->next;
        }

        return result;
    }

    Polynomial multiply(Polynomial p) {
        Polynomial result;
        Node* t1 = head;

        while (t1 != NULL) {
            Node* t2 = p.head;
            while (t2 != NULL) {
                result.insert(t1->coeff * t2->coeff, t1->exp + t2->exp);
                t2 = t2->next;
            }
            t1 = t1->next;
        }

        return result;
    }
};


int main() {
    int num;
    cout << "How many polynomials do you want to work with? ";
    cin >> num;
    if (num <= 0) {
        cout << "Number of polynomials must be positive.\n";
        return 0;
    }

    vector<Polynomial> polys(num);

    for (int i = 0; i < num; ++i) {
        cout << "\n--- Polynomial #" << (i + 1) << " ---\n";
        polys[i].input();
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display all polynomials\n";
        cout << "2. Add two polynomials\n";
        cout << "3. Subtract two polynomials (P1 - P2)\n";
        cout << "4. Multiply two polynomials\n";
        cout << "5. Add all polynomials\n";
        cout << "6. Multiply all polynomials\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int idx1, idx2;
        Polynomial result;

        switch (choice) {
        case 1:
            for (int i = 0; i < num; ++i) {
                cout << "Polynomial #" << (i + 1) << ": ";
                polys[i].display();
            }
            break;
        case 2:
            cout << "Enter index of first polynomial (1-" << num << "): ";
            cin >> idx1;
            cout << "Enter index of second polynomial (1-" << num << "): ";
            cin >> idx2;
            if (idx1 >= 1 && idx1 <= num && idx2 >= 1 && idx2 <= num) {
                result = polys[idx1 - 1].add(polys[idx2 - 1]);
                cout << "Result of addition: ";
                result.display();
            } else {
                cout << "Invalid indices\n";
            }
            break;
        case 3:
            cout << "Enter index of polynomial to subtract from (1-" << num << "): ";
            cin >> idx1;
            cout << "Enter index of polynomial to subtract (1-" << num << "): ";
            cin >> idx2;
            if (idx1 >= 1 && idx1 <= num && idx2 >= 1 && idx2 <= num) {
                result = polys[idx1 - 1].subtract(polys[idx2 - 1]);
                cout << "Result of subtraction: ";
                result.display();
            } else {
                cout << "Invalid indices\n";
            }
            break;
        case 4:
            cout << "Enter index of first polynomial (1-" << num << "): ";
            cin >> idx1;
            cout << "Enter index of second polynomial (1-" << num << "): ";
            cin >> idx2;
            if (idx1 >= 1 && idx1 <= num && idx2 >= 1 && idx2 <= num) {
                result = polys[idx1 - 1].multiply(polys[idx2 - 1]);
                cout << "Result of multiplication: ";
                result.display();
            } else {
                cout << "Invalid indices\n";
            }
            break;
        case 5:
            if (num > 0) {
                result = polys[0];
                for (int i = 1; i < num; ++i)
                    result = result.add(polys[i]);
                cout << "Result of adding all polynomials: ";
                result.display();
            }
            break;
        case 6:
            if (num > 0) {
                result = polys[0];
                for (int i = 1; i < num; ++i)
                    result = result.multiply(polys[i]);
                cout << "Result of multiplying all polynomials: ";
                result.display();
            }
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}