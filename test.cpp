#include <iostream> //ye 2 lines toa aati e hain ham ko
using namespace std;

class node //node naam ki class banaayi aik yaahan just bana lo
{
public:  //do parts hain linked list k : data and next node ka address written as next
    int value;   //data part
    node *next; //next wala part jahaan AGLE NODE KA ADDRESS store hoga; type iski node iss liye hai k ye apne jaisi hi node ko point kar raha hai
    
    node(int val)//constructor to store the value in single node
    {
        value = val;
        next = NULL;
    }
};

class list{ //list ki class banaayi
 public:
    node* head, *tail; //do pointer head aur tail k bnaay, head is starting point and tail is ending point
    
    list(){
        head = NULL; //initially head aur tail donoo null hain
        tail = NULL;
    }

    void create(){ // create ka function new node ko jorrne k liye
         int n,val;
        cout << "Kitne elements add karne hain: ";
        cin >> n;
     for(int i = 0; i < n; i++) { 
        cout << "Element " << i+1 << " enter karein: ";
        cin >> val;
         node* temp = new node(val);//temp ki node bnaayi new ka keyword use kiya aur constructor k through value store hui
        if(head == NULL){//agr head null ho toa pehle node exist ni kar rahi aur jo hum bana rahe wohi head aur tail hogi
            head = temp;
            tail = temp;
        }
        else{ // agr head null ni matlab pehle nodes hain toa.. neeche dekho 
            tail->next = temp;//jo pehle list exist karti uss ki tail k next waaale portion main temp wla node ka address store karo
            tail = temp;// aur tail ab nayi aanay waali node temp ban jaayegi
        }
    }
    }

    void display(){ // linked list ko display karein ge ab
        node* temp = head; //temp naam ka pointer banaaya aur head se check karna shroo karein ge
        while (temp != NULL){//jab tak temp null na ho jaaye
            cout << temp->value << " "; // print karo temp waale ki stored value
            temp = temp->next;// show karne k baad temp jo hai wo temp k next node k equal ho jaaygi
        }
        cout << endl;
    }

    void insert_at_start(){
        if (head == NULL){ // check kiya k list bani hai ya nahi
            cout << "Pehle jaa k list banaao!!!!" << endl;
            return;
        }
        int new_value;
        cout<<"Enter value you want to enter at start: ";
        cin >> new_value;
        node* temp= new node(new_value); // new node banaayi
        temp->next= head; //temp k next ko existing head k equal kiya matlab k new node k next main existing head ka data store ho jaay
        head = temp; //head ab temp ban jaay ga
    }

    void insertion_at_last()
    {  
        if (head == NULL){ // check kiya k list bani hai ya nahi
            cout << "Pehle jaa k list banaao!!!!" << endl;
            return;
        }
        int new_value;
        cout<<"Enter value you want to enter at end: ";
        cin>>new_value;
        node* temp= new node(new_value); // nayi node banayi temp naam se
        tail->next= temp; // tail k next main ab nayi node (temp) ka address daal dia
        tail = temp; // aur ab tail khud temp ban gayi
    }

    void insert_at_specific(){
        if (head == NULL){ // check kiya k list bani hai ya nahi
            cout << "Pehle jaa k list banaao!!!!" << endl;
            return;
        }
        node* previous, *current; // do pointers liye tracking k liye
        int position,count=1,new_value;
        cout<<"Enter position where you want to enter new node: ";
        cin>>position;
        cout<<"Enter value to enter at "<<position<<": ";
        cin>>new_value;
        node *temp= new node(new_value); // wo node jo insert karni hai
        previous = NULL; // start main previous null hoga
        current= head; // current ko head se start karenge
        while(count!= position){ // jab tak count position k barabar na ho jaye
            previous = current; // peeche wala pointer current pe aa gaya
            current= current->next; // current wala agay nikal gaya
            count++; // position count barhti gayi
        }
        if (count==position){ // jab position mil jaye
            previous->next= temp; // peeche wali node ko nayi node (temp) se jorr dia
            temp->next=current; // nayi node k next main current (agay wali node) ka address daal dia
        }
    }

    void delete_at_start(){ // start se node delete karne k liye
        if(head == NULL){ cout << "Pehle jaa k list banaao!!!!" << endl; return; }
        node* temp = head; // temp main purana head rakha
        head = head->next; // head ko agli node pe shift kar dia
        delete temp; // purani node memory se khatam
    }

    void delete_at_end(){ // end se node delete karne k liye
        if(head == NULL){ cout << "Pehle jaa k list banaao!!!!" << endl; return; }
        if(head == tail){ // agar sirf aik hi node ho
            delete head;
            head = tail = NULL;
        } else {
            node* temp = head;
            while(temp->next != tail){ // tail se aik pehle wali node tak pohnchna hai
                temp = temp->next;
            }
            delete tail; // akhri node delete ki
            tail = temp; // tail ko peeche move kar dia
            tail->next = NULL; // nai tail ka next null kar dia
        }
    }

    void delete_at_specific(){ // kisi khaas position se delete karne k liye
        if (head == NULL){ cout << "Pehle jaa k list banaao!!!!" << endl; return; }
        node* previous, *current;
        int position, count = 1;
        cout << "Enter position to delete: ";
        cin >> position;

        if(position == 1){ // agar pehli hi node delete karni ho
            delete_at_start();
            return;
        }

        previous = NULL;
        current = head;
        while(count != position){ // desired position tak pohncho
            previous = current;
            current = current->next;
            count++;
        }

        if(count == position){ // position mil gayi
            previous->next = current->next; // peeche wali node ka link agay wali se jorr dia
            if(current == tail) tail = previous; // agar akhri node delete hui toa tail update ki
            delete current; // node delete kar di
        }
    }
};

int main(){
    list l; //list ka object l
    int choice;
    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Create Linked List\n";
        cout << "2. Insert Node\n";
        cout << "3. Display List\n";
        cout << "4. Delete Node\n";
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

        case 3:
            l.display();
            break;

        case 4: {
            int delete_choice;
            do {
                cout << "\n--- DELETE MENU ---\n";
                cout << "1. Delete from Start\n";
                cout << "2. Delete from End\n";
                cout << "3. Delete from Position\n";
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

        case 0:
            cout << "AAJ k liye itna e aap ki tarah hum b mayoos hain!!!!!!...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

}