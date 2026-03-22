    // // swapping two numbers with using a third variable
    #include "iostream"
    using namespace std;
    int main(){
        int a = 10;
        int b = 20;
        int temp;
        temp= a;
        a = 20;
        b = temp;
        cout<<"a: "<<a<<endl;
        cout<<"b: "<<b<<endl;
    }
    // swapping two numbers without using a third variable
#include "iostream"
#include "algorithm"
using namespace std;
int main(){
    int a= 10, b = 20;
    swap(a,b);
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
}
// reverse a char array without using any header file, without using any function
#include "iostream"
using namespace std;
int main(){
   char arr[100];
   cout<<"Enter expression:";
   cin>>arr;
   //check length of the array
    int length = 0;
    for (int i = 0; arr[i] != '\0'; i++){
        length++;
    }
    //reverse the array and store it in the same array
    for (int i = 0; i < length / 2; i++){
        char temp = arr[i];
        arr[i] = arr[length - 1 - i];
        arr[length - 1 - i] = temp;
    }
    //print the reversed array
    for (int i = 0; i < length; i++){
        cout<<arr[i];
    }
   
}
