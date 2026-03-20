#include "iostream"
using namespace std;
class stack{
    public:
    int top;
    int size;
    int arr[4];
    stack(){
        top=-1;
        size=4;
    }
     int isEmpty(){
        if(top==-1){
            return 1;
        }
        return 0;
    }
    

    void display(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int isFull(){
        if(top==size-1){
            return 1;
        }
        return 0;
    }
    void push(int x){
        if(isFull()){
            cout<<"Stack overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack underflow"<<endl;
            return;
        }
        top--;
    }
    int peak(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
    

};
int main(){
    stack s;
    int choice;
    do{ cout<<"-----Menu-----"<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Peak"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                int x;
                cout<<"Enter element to be pushed: ";
                cin>>x;
                s.push(x);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout<<"Peak element is: "<<s.peak()<<endl;
                break;
            case 4:
                s.display();
                break;
            case 0:
                exit(0);
            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(choice!=0);
    return 0;
}
