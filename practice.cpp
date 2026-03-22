//infix to prefix conversion
#include "iostream"
using namespace std;
class conversion{
        public:
        char stack[100];
        int top;
        conversion(){
            top=-1;
        }
    void push(char x){
        top++;
        stack[top]= x;
    }

    char pop(){
        char c = stack [top];
        top--;
        return c;
    }

    bool isempty(){
        if(top== -1){
            return true;
        }
        else return false;
    }

    char topp(){
        char c = stack[top];
        return c;
    }

    int precedence(char symbol){
        switch (symbol)
        {
        case '^':
            return 3;
            break;
        case '/':
        case '*':
            return 2;
            break;    
        case '+':
        case '-':
            return 1;
        default:
            return 0;
            break;
        }
    }



};
int main(){
    conversion c;
    char symbol, next;
    int i=0, j=0;
    char infix[100], prefix[100];
    cout<<"Enter the infix Expression: ";
    cin>>infix;
    //reversing the infix expression
    int n=0;
    while(infix[n]!= '\0'){
        n++;
    }
    for(int i=0; i<n/2; i++){
        char temp= infix[i];
        infix[i]= infix[n-1-i];
        infix[n-1-i]= temp;
    }

    for(int i=0; i<n; i++){
     if(infix[i]=='('){
        infix[i]=')';
     }
     else if(infix[i]==')'){
        infix[i] ='(';
     }
    }
    
    while(infix[i]!='\0'){
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
         c.push(symbol);
        break;

        case ')':
         while(!c.isempty() && (next = c.pop())!= '('){
         prefix[j]= next;
         j++;
         }
         break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        while (!c.isempty() && c.precedence(c.topp())>= c.precedence(symbol)){
            prefix[j]= c.topp();
            j++;
            c.pop();
        }
        c.push(symbol);
        break;
        default:
        prefix[j]= symbol;
        j++;
            break;
        }i++;
    }
    while(!c.isempty()){
        prefix[j]= c.pop();
        j++;
    }
    //reverse the prefix expression
    for(int i=0; i<j/2; i++){
        char temp= prefix[i];
        prefix[i]= prefix[j-1-i];
        prefix[j-1-i]= temp;
    }
    prefix[j]='\0';
    cout<<"The prefix expression is: "<<prefix<<endl;

}