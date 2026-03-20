#include "iostream"
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next= NULL;
    }
};
class stack{
    public:
    node* top;
    stack(){
        top = NULL;
    }
    int isempty(){
        if(top == NULL){
            return 1;
        }
        else{
            return 0;
        }
    }
    void push(){
        int val;
        cout<<"Enter the value to be pushed: ";
        cin>>val;
        node* temp = new node(val);
        if(top == NULL){
            top = temp;
            return;
        }
        temp->next= top;
        top = temp;
    }
    void pop(){
        if(isempty()){
            cout<<"Stack underflow"<<endl;
            return;
        }
        node* temp = top;
        top = top->next;
        delete temp;
    }
    void display(){
        if(isempty()){
            cout<<"ISmein hai e kuch ni!!";
        }
        else{
            node *temp= top;
            while( temp!= NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
    }
    void peak(){
        if (isempty()){
            cout<<"Khaali a Khaali!!"<<endl;
        }
        else{
            cout<<"Top element is: "<<top->data<<endl;
        }
    }
};
int main(){
     stack s;
    int choice;
    do{ cout<<"\n-----Menu-----"<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Peak"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                 s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peak();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout<<"Khatam";
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }while(choice!=5);
    return 0;
}