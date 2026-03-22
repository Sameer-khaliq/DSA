//infix to prefix conversion
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;
class conversion{
    public:
    int top;
    conversion(){
        top = -1;
    }
   char stack [100];
   void push(char x){
    top++;
    stack[top] =x;
   }

   char pop(){
    char c = stack[top];
     top--; 
    return c;
   
   }
   
   bool isempty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
   }

   void display(){
    for (int i= top; i>=0; i--){
        cout<<stack[i]<<" ";
    }
   }

   char topp(){
    char c  =stack[top];
    return c;
   }

   int precedence(char symbol){
    switch (symbol){
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
   }
};
int main(){
    conversion c;
    string infix, prefix;
    cout<<"enter infix expression: ";
    cin>>infix;
    // reverse the infix expression
    reverse(infix.begin(), infix.end());
    for(int i =0; i<infix.length(); i++){
        if(infix[i]=='('){
            infix[i] = ')';
        }
        else if(infix[i]==')'){
            infix[i] = '(';
        }
    }
    int i = 0;
    char symbol, next;
    while (i < infix.length()){
        symbol = infix[i];
        switch (symbol){
            case '(':
                c.push(symbol);
                break;
            case ')':
            while (!c.isempty() && (next = c.topp()) != '('){
                prefix.push_back(next);
                c.pop();
            }
            if (!c.isempty()) c.pop(); 
            break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            while (!c.isempty() && c.precedence(symbol) < c.precedence(c.topp())){
                prefix.push_back(c.topp());
                c.pop();
            }
            c.push(symbol);
            break;
            default:
            prefix.push_back(symbol);
            break;

        }
        i++;

    }
    while (!c.isempty()){
        prefix.push_back(c.topp());
        c.pop();
    }
    // reverse the prefix expression
    reverse(prefix.begin(), prefix.end());
    cout<<"prefix expression is: "<<prefix;
    


}