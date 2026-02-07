//doubly linked list
//it has three parts: previous, value and next
//previous stores the address of previous node and next stores address of next node
#include <iostream>
using namespace std;
class node{
    public:
 int value;
 node *previous;
 node *next;
 node(int val){
    value = val;
    next= NULL;
    previous= NULL;
 }
};
class doublylinkedlist{
  public:
  node *head, *tail;
  doublylinkedlist(){
    head= NULL;
    tail= NULL;
  }
  void create(){
    int value;
    int n;
    cout<<"How much elements to add??: ";
    cin>>n;
    for (int i=0;i<n; i++){
        cout<<"Enter value for node "<<i+1<<": ";
        cin>>value;
        node *temp = new node(value);
         if(head == NULL){
        head= temp;
        tail= temp;
    }
    else{
        tail->next=temp;
        temp->previous=tail;
        temp->next= NULL;
        tail= temp;
    }
    }
   
  }
  void display(){
    node *temp = head;
    while(temp!= NULL){
        cout<<temp->value<<" ";
        temp= temp->next;
    }
  }
  void insert_at_start(){
    int value;
    cout<<"Enter value to insert at start: ";
    cin >>value;
    node *temp= new node(value);
    head->previous= temp;
    temp->next= head;
    temp->previous= NULL;
    head= temp;
  }
  void insert_at_end(){
    int value;
    cout<<"Enter value to insert at last: ";
    cin >>value;
    node *temp = new node(value);
    tail->next= temp;
    temp->previous= tail;
    temp->next=NULL;
    tail= temp;
  }
  void insert_at_specific(){
    int position, value, count=0;
    cout<<"Enter position where you want to add new element: ";
    cin>>position;
    cout<<"Enter the element you want to enter: ";
    cin>>value;
    node* before, *after;
    before = NULL;
    after = head;
    while(count != position){
        
        before= after;
        after= after->next;
        count++;
    }
    if (count == position){
        node* temp = new node(value);
        before->next= temp;
        temp->previous= before;
        temp->next= after;
        after->previous= temp;
    }
  }
  void delete_at_start(){
    node * temp = head;
    temp->next->previous= NULL;
    head= temp->next;
    delete temp;
  }
  void delete_at_end(){
    node* temp= tail;
    temp->previous->next= NULL;
    tail= temp->previous;
    delete temp;
  }
  void delete_at_specific(){
    //handle the edge cases of deleting first and last node in this function

    node*before,*after;
    before= NULL;
    after = head;
    int position, count=1;
    cout<<"Enter position where you want to delete: ";
    cin>> position;
    if(position==1){
        delete_at_start();
        return;
    }
     
    while( count!= position){
      before= after;
      after= after->next;
      count++;
    }
     if(position== count){
        delete_at_end();
        return;
    }
    if(count== position){
        before->next= after->next;
        after->next->previous= before;
        delete after;

    }
  }
  void search(){
        int target, position=1;
        bool isfound= false;
        cout<<"Enter the value you want to search: ";
        cin>>target;
        node* temp= head;
        while(temp!= NULL){
            if(temp->value== target){
                cout<<"Target is found at position: "<<position<<endl;
                isfound= true;
            }
            position++;
            temp= temp->next;
        }
        if(isfound== false){  
            cout<<"Target not found!!!!!";
        }}
};
int main(){
    doublylinkedlist d;
   //menu

    int choice;
    do{
        cout<<"\n--- MAIN MENU ---\n";
        cout<<"1. Create List\n";
        cout<<"2. Insertion\n";
        cout<<"3. Deletion\n";
        cout<<"4. Display\n";
        cout<<"5. Search\n";
        cout<<"0. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                d.create();
                break;
            case 2:
            int insert_choice;
            do
            {
                cout << "\n--- INSERTION MENU ---\n";
                cout << "1. Insert at Start\n";
                cout << "2. Insert at End\n";
                cout << "3. Insert at specific Position\n";
                cout << "0. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> insert_choice;
                switch (insert_choice)
                {
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
                        cout << "Invalid choice!" << endl;
                }
            } while (insert_choice != 0);
            break;
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
                        cout << "Invalid choice!" << endl;
                }
            } while (delete_choice != 0);
            break;
            case 4:
                d.display();
                break;
            case 5:
                d.search();
                break;
            case 0:
                cout<<"Aaj k liye itna e kaafi hai !!!!!!";
        }
    } while (choice != 0);

    

}