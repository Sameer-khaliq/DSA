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
  
};
int main(){
    doublylinkedlist d;
    d.create();
    // d.display();
    // cout<<endl;
    // d.insert_at_start();
    //  d.display();
     d.insert_at_specific();
     d.display();
}