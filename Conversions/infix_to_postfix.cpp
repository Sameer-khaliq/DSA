 // infix to postfix conversion using stack
#include <iostream>
using namespace std;
class conversion
{
    public:
    int top;   // declare top
    int stack[100];//declare stack using array
    conversion()
    {
        top = -1; // constructor to set the value to -1, stack is empty at start
    }
 void push(char ch){
    ++top;
    stack[top]= ch;// push function to add element in stack
 }
    bool isempty(){ //empty ka function stack ko check karega
        if(top==-1){
            return true;
        }        else{
            return false;
    }
}
    char pop(){    // stack se element ko remove karne ke liye pop function
        if(isempty()){
            cout<<"empty";
        }
        else{
            char c;
            c=stack[top];
            top--;
            return c;
        }
    }
    char topp(){ // stack ke top element ko return karega
         char c;
         c=stack[top];
         return c;

    }
 int precedence(char symbol){ // set precedence

        switch (symbol)
        {
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
int main()
{

    conversion s; //object of class conversion
    int i = 0; // index for infix expression
    int j = 0; // index for postfix expression
    char infix[100];    // array to store infix expression
    char postfix[100];  // array to store postfix expression
    char symbol, next;  // variables to store current symbol and next symbol
    cout << "enter the infix expression: ";
    cin >> infix;   // take infix expression as input
    while (infix[i] != '\0') // run loop until null value
{
        symbol = infix[i]; // store current symbol in variable

        switch (symbol)// check the type of symbol
        {

        case '(':
            s.push(symbol);
            break;
        case ')':
            while ((next = s.pop()) != '(')
            {                    // pop all characters until ( bracket
                postfix[j] = next;
                j++;
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!s.isempty() && s.precedence(s.topp()) >= s.precedence(symbol)) // check precedece til brackets
            {
                postfix[j] = s.pop();
                j++;
            }
            s.push(symbol);
            break;

        default:
            postfix[j] = symbol; // if it is an operand
            j++;
        }
        i++;
    }
    while (!s.isempty())
    {
        postfix[j] = s.pop();
        j++;
    }
    postfix[j] = '\0';
    cout << "postfix expression is: " << postfix;

    return 0;
}