#include "iostream"
using namespace std;
class insertion{
public:
int size;
int array[10];
int position;
int element;
void inputsize(){
    cout<<"Enter the size of array (max 09): ";
    cin>>size;
    if (size>9){
        cout<<"Size exceeds maximum limit. Please enter a size less than or equal to 9."<<endl;
        inputsize();
    }
}
void inputarray(){
    cout<<"Enter the elements of array: "<<endl;
    for (int i=0; i<size; i++){
        cout<<"enter the element for index "<<i<<" :";
        cin>>array[i];
    }
}
void inputelement(){
    cout<<"Enter position of element: ";
    cin>>position;
    cout<<"Enter the element to be inserted: ";
    cin>>element;
    if (position > size || position<0){
        cout<<"invalid position!"<<endl;
        inputelement();
    }
  for(int i=size; i>position; i--){
    array[i]=array[i-1];
  }
  array[position]=element;
  size++;
}
void printarray(){
    cout<<"The new array is: "<<endl;
    for (int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
};
int main(){
    insertion obj;
    int choice;
    do{
        cout<<"\n----Menu----"<<endl;
        cout<<"1.Input the size of array "<<endl;
        cout<<"2.Input the elements of array "<<endl;
        cout<<"3.Insert the element into array "<<endl;
        cout<<"4.Print the elements of array "<<endl;
        cout<<"5.Exit "<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice){
            case 1:
            obj.inputsize();
            break;
            case 2:
            obj.inputarray();
            break;  
            case 3:
            obj.inputelement();
            break;
            case 4:
            obj.printarray();
            break;
            case 5:
            cout<<"Exiting the program."<<endl;
            break;
            default:    
            cout<<"Invalid choice! Please try again."<<endl;
            break;

        }

    }while(choice!=5);
}
