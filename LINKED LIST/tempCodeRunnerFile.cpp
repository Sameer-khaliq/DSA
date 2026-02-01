#include <iostream> //ye 2 lines toa aati e hain ham ko
using namespace std;

class node // node naam ki class banaayi aik yaahan just bana lo
{
public:         // do parts hain linked list k : data and next node ka address written as next
    int value;  // data part
    node *next; // next wala part jahaan AGLE NODE KA ADDRESS store hoga; type iski node iss liye hai k ye apne jaisi hi node ko point kar raha hai

    node(int val) // constructor to store the value in single node
    {
        value = val;
        next = NULL;
    }
};

class list
{ // list ki class banaayi
public:
    node *head, *tail; // do pointer head aur tail k bnaay, head is starting point and tail is ending point

    list()
    {
        head = NULL; // initially head aur tail donoo null hain
        tail = NULL;
    }

    void create()
    { // create ka function new node ko jorrne k liye
        int n, val;
        cout << "Kitne elements add karne hain: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Element " << i + 1 << " enter karein: ";
            cin >> val;
            node *temp = new node(val); // temp ki node bnaayi new ka keyword use kiya aur constructor k through value store hui
            if (head == NULL)
            { // agr head null ho toa pehle node exist ni kar rahi aur jo hum bana rahe wohi head aur tail hogi
                head = temp;
                tail = temp;
            }
            else
            {                      // agr head null ni matlab pehle nodes hain toa.. neeche dekho
                tail->next = temp; // jo pehle list exist karti uss ki tail k next waaale portion main temp wla node ka address store karo
                tail = temp;       // aur tail ab nayi aanay waali node temp ban jaayegi
            }
        }
    }

    void display()
    {                      // linked list ko display karein ge ab
        node *temp = head; // temp naam ka pointer banaaya aur head se check karna shroo karein ge
        while (temp != NULL)
        {                               // jab tak temp null na ho jaaye
            cout << temp->value << " "; // print karo temp waale ki stored value
            temp = temp->next;          // show karne k baad temp jo hai wo temp k next node k equal ho jaaygi
        }
        cout << endl;
    }

    void insert_at_start()
    {
        if (head == NULL)
        { // Check kiya k list bani bhi hai ya nahi
            cout << "Pehle jaa k list banaao!!!!" << endl;
            return;
        }
        int new_value;
        cout << "Enter value you want to enter at start: ";
        cin >> new_value;
        node *temp = new node(new_value); // new node banaayi
        temp->next = head;                // temp k next ko existing head k equal kiya matlab k new node k next main existing head ka data store ho jaay
        head = temp;                      // head ab temp ban jaay ga
    }

    void insertion_at_last()
    {
        if (head == NULL)
        { // Check kiya k list bani bhi hai ya nahi
            cout << "Pehle jaa k list banaao!!!!" << endl;
            return;
        }
        int new_value;
        cout << "Enter value you want to enter at end: ";
        cin >> new_value;
        node *temp = new node(new_value); // nayi node banayi temp naam se
        tail->next = temp;                // tail k next main ab nayi node (temp) ka address daal dia
        tail = temp;                      // aur ab tail khud temp ban gayi
    }

    void insert_at_specific()
    {
        if (head == NULL)
        { // Check kiya k list bani bhi hai ya nahi
            cout << "Pehle jaa k list banaao!!!!" << endl;
            return;
        }
        node *previous, *current; // do pointers liye tracking k liye
        int position, count = 1, new_value;
        cout << "Enter position where you want to enter new node: ";
        cin >> position;
        cout << "Enter value to enter at " << position << ": ";
        cin >> new_value;
        node *temp = new node(new_value); // wo node jo insert karni hai
        previous = NULL;                  // start main previous null hoga
        current = head;                   // current ko head se start karenge
        while (count != position)
        {                            // jab tak count position k barabar na ho jaye
            previous = current;      // peeche wala pointer current pe aa gaya
            current = current->next; // current wala agay nikal gaya
            count++;                 // position count barhti gayi
        }
        if (count == position)
        {                          // jab position mil jaye
            previous->next = temp; // peeche wali node ko nayi node (temp) se jorr dia
            temp->next = current;  // nayi node k next main current (agay wali node) ka address daal dia
        }
    }
    void delete_at_start()
    {
        if (head == NULL)
        {
            cout << "Pehle list create karo!!!!!!!";
            return;
        }
        node *temp = head; //aik node temp create ki aur uss main current head ko rakha jo delete karna hai
        head = head->next; //head ko head ki agli node k equal kar diya
        delete temp; //temp ko delete karein ge toa first  node del ho jaay gi 
    }
    void delete_at_specific()
    {
        if (head == NULL)
        {
            cout << "Pehle list create karo!!!!!!!";
            return;
        }
        node *previous, *current;  //same logic like insert at specific position
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
        if (count == position) //agr count required position k equal ho jaay
        {
            previous->next = current->next; //previous k next ko current k next k saath jorr doa jis se current azaad ho jaayga
            delete current; //current ko del kar diya
        }
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
        while (current != tail)//jab tak current tail k equal na ho
        {
            previous = current; //previous aur current ko aik aik step aagay karte jaayein ge
            current = current->next;
        }
        if (current == tail)//jab current tail ban jaay
        {
            tail = previous; //previous labeled node ko tail bana dein ge aur tail k next ko null kar diya
            tail->next = NULL;
            delete current;//pehle jo tail thee wo current k equal and current is deleted 
        }
    }
    void search(){
        int target,position=1;
        bool isfound = false;
        cout<<"Enter target: ";
        cin>>target;
        node* temp= head;
        while(temp != NULL){
            if(temp ->value== target){
                cout<<"Target is found at position: "<<position;
                isfound = true;
            }
            position++;
            temp = temp->next;
            
        }
        if(isfound == false){
            cout<<"target not found!!!!!";
        }
        
    }
};

int main()
{
    list l; // list ka object l
    int choice;
    do
    {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Create Linked List\n";
        cout << "2. Insert Node\n";
        cout << "3. Display List\n";
        cout << "4. Delete node\n";
        cout<< "5. Search value\n";
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
                cout << "0. Back to Main Menu\n";
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
                case 0:
                    break;
                default:
                    cout << "Invalid option!\n";
                }
            } while (insert_choice != 0);
            break;
        }

        case 3:
            int delete_choice;
            do
            {
                cout << "\n--- DELETION MENU ---\n";
                cout << "1. Delete at Start\n";
                cout << "2. Delete at End\n";
                cout << "3. Delete at specific Position\n";
                cout << "0. Back to Main Menu\n";
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
                case 0:
                    break;
                default:
                    cout << "Invalid option!\n";
                }
            } while (delete_choice != 0);
            break;
        case 4:
            l.display();
            break;
        case 5:
            l.search();
            break;
        case 0:
            cout << "aaj k liye itna e kaafi hai aap ki tarah hum b maayoos hain!!!!!!...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);
}