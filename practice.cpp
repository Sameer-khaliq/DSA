#include "iostream"
using namespace std;
class node{
    public:
    int value;
    node* next;
    node(int val){
        value = val;
        next= NULL;
    }
};
class list{
    public:
    node *head, *tail;
    list(){
        head= NULL;
        tail= NULL;
    }
 void create(int val){
    node *temp= new node(val);
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next= temp;
        tail = temp;
    }
 }
 void display(){
    node* temp= head;
    while( temp != NULL){
        cout<<temp->value<<" ";
        temp= temp->next;
    }
 }
};
int main(){
    list l;
    int value,n;
    cout<<"Enter number of elements: ";
    cin>>n;
    for(int i=0; i<n ;i++){
        cout<<"Enter the element "<<i+1<<": "<<endl;
        cin>>value;
        l.create(value);
    }
    cout<<"The elements in the linked list are: ";
    l.display();
}