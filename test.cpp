#include <iostream> 
#include <fstream>  
using namespace std;

class node
{
public:
    int value;
    node *next;

    node(int val)
    {
        value = val;
        next = NULL;
    }
};

class list
{
public:
    node *head, *tail;

    list()
    {
        head = NULL;
        tail = NULL;
        loadFromFile(); // file se data load
    }

    void saveToFile()
    {
        ofstream fout("file.txt");
        node *temp = head;
        while (temp != NULL)
        {
            fout << temp->value << " ";
            temp = temp->next;
        }
        fout.close();
    }

    void loadFromFile()
    {
        ifstream fin("file.txt");
        int val;
        while (fin >> val)
        {
            node *temp = new node(val);
            if (head == NULL)
            {
                head = tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
        fin.close();
    }

    void create()
    {
        int n, val;
        cout << "Kitne elements add karne hain: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Element " << i + 1 << " enter karein: ";
            cin >> val;
            node *temp = new node(val);
            if (head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
        saveToFile();
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert_at_start()
    {
        if (head == NULL)
        {
            cout << "Pehle jaa k list banaao!!!!" << endl;
            return;
        }
        int new_value;
        cout << "Enter value you want to enter at start: ";
        cin >> new_value;
        node *temp = new node(new_value);
        temp->next = head;
        head = temp;

        saveToFile();
    }

    void insertion_at_last()
    {
        if (head == NULL)
        {
            cout << "Pehle jaa k list banaao!!!!" << endl;
            return;
        }
        int new_value;
        cout << "Enter value you want to enter at end: ";
        cin >> new_value;
        node *temp = new node(new_value);
        tail->next = temp;
        tail = temp;

        saveToFile();
    }

    void insert_at_specific()
    {
        if (head == NULL)
        {
            cout << "Pehle jaa k list banaao!!!!" << endl;
            return;
        }
        node *previous, *current;
        int position, count = 1, new_value;
        cout << "Enter position where you want to enter new node: ";
        cin >> position;
        cout << "Enter value to enter at " << position << ": ";
        cin >> new_value;
        node *temp = new node(new_value);
        previous = NULL;
        current = head;
        while (count != position)
        {
            previous = current;
            current = current->next;
            count++;
        }
        if (count == position)
        {
            previous->next = temp;
            temp->next = current;
        }

        saveToFile();
    }

    void delete_at_start()
    {
        if (head == NULL)
        {
            cout << "Pehle list create karo!!!!!!!";
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;

        saveToFile();
    }

    void delete_at_specific()
    {
        if (head == NULL)
        {
            cout << "Pehle list create karo!!!!!!!";
            return;
        }
        node *previous, *current;
        int position, count = 1;
        cout << "Enter position to delete: ";
        cin >> position;
        previous = NULL;
        current = head;
        while (count != position)
        {
            previous = current;
            current = current->next;
            count++;
        }
        if (count == position)
        {
            previous->next = current->next;
            delete current;
        }

        saveToFile();
    }

    void delete_at_end()
    {
        if (head == NULL)
        {
            cout << "Pehle list create karo!!!!!!!";
            return;
        }
        node *current, *previous;
        current = head;
        previous = NULL;
        while (current != tail)
        {
            previous = current;
            current = current->next;
        }
        if (current == tail)
        {
            tail = previous;
            tail->next = NULL;
            delete current;
        }

        saveToFile();
    }

    void search()
    {
        int target, position = 1;
        bool isfound = false;
        cout << "Enter target: ";
        cin >> target;
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->value == target)
            {
                cout << "Target is found at position: " << position << endl;
                isfound = true;
            }
            position++;
            temp = temp->next;
        }
        if (isfound == false)
        {
            cout << "target not found!!!!!" << endl;
        }
    }
};

int main()
{
    list l;
    int choice;

    do
    {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Create Linked List\n";
        cout << "2. Insert Node\n";
        cout << "3. Delete Node\n";
        cout << "4. Display List\n";
        cout << "5. Search Value\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            l.create();
            break;

        case 2:
        {
            int insert_choice;
            do
            {
                cout << "\n--- INSERT MENU ---\n";
                cout << "1. Insert at Start\n";
                cout << "2. Insert at End\n";
                cout << "3. Insert at Position\n";
                cout << "0. Back\n";
                cout << "Enter choice: ";
                cin >> insert_choice;

                switch (insert_choice)
                {
                case 1:
                    l.insert_at_start();
                    break;
                case 2:
                    l.insertion_at_last();
                    break;
                case 3:
                    l.insert_at_specific();
                    break;
                }
            } while (insert_choice != 0);
            break;
        }

        case 3:
        {
            int delete_choice;
            do
            {
                cout << "\n--- DELETE MENU ---\n";
                cout << "1. Delete at Start\n";
                cout << "2. Delete at End\n";
                cout << "3. Delete at Position\n";
                cout << "0. Back\n";
                cout << "Enter choice: ";
                cin >> delete_choice;

                switch (delete_choice)
                {
                case 1:
                    l.delete_at_start();
                    break;
                case 2:
                    l.delete_at_end();
                    break;
                case 3:
                    l.delete_at_specific();
                    break;
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
            cout << "bohat ho gaya program aaj k liye itna e kaafi hai!!! \n";
            break;
        }

    } while (choice != 0);
}
