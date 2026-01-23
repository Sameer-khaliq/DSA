#include <iostream> //ye 2 lines toa aati e hoon gi sa ko
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

    void create(int val){ // create ka function new node ko jorrne k liye
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

    void display(){ // linked list ko display karein ge ab
        node* temp = head; //temp naam ka pointer banaaya aur head se check karna shroo karein ge
        while (temp != NULL){//jab tak temp null na ho jaaye
            cout << temp->value << " "; // print karo temp waale ki stored value
            temp = temp->next;// show karne k baad temp jo hai wo temp k next node k equal ho jaaygi
        }
        cout << endl;
    }
};

int main(){
    list l; //list ka object l
    
    int n, val;
    cout << "Kitne elements add karne hain? ";
    cin >> n; // user bataye ga k kitni nodes banani hain

    for(int i = 0; i < n; i++) { // loop chalay ga jitne n elements hain
        cout << "Element " << i+1 << " enter karein: ";
        cin >> val; // user se value li
        l.create(val); // create function ko call kiya value store karne k liye
    }

    cout << "\nAap ki Linked List ye hai: ";
    l.display(); // display KAR DOA jo jo hai linked list mein

    return 0;
}