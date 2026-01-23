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
void deleteelement(){
     cout<<"Enter position to delete the element: ";
        cin>>position;
        if (position>=size){
            cout<<"Invalid position!";
        }
        else{
            for(int i=position; i<size; i++){
                array[i]= array[i+1];
            }
            size--;

        }
}
void update_element(){
        int new_element;
        cout<<"Enter the position to be updated: ";
        cin>>position;
        cout<<"Enter new element: ";
        cin>>new_element;
        if (position>=size){
            cout<<"Invalid position!";
        }
        else{
           array[position]= new_element;
        }
    }
void searchelement(){
    int target;
    bool isfound;
isfound = false;
    cout<<"Enter target: ";
    cin>>target;
     for(int i=0; i<size; i++){
      if(array[i]==target){
        cout<<"Target is at: "<<i<<endl;
        isfound = true;
      }
    }
    if(isfound == false){
      cout<<"Not found!"<<endl;
    }
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
        cout<<"4.Delete the element from array"<<endl;
        cout<<"5.Update the element from an array"<<endl;
        cout<<"6.Search the element from an array"<<endl;
        cout<<"7.Print the elements of array "<<endl;
        cout<<"8.Exit "<<endl;
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
            obj.deleteelement();
            break;
            case 5:
            obj.update_element();
            break;
            case 6:
            obj.searchelement();
            break;
            case 7:
            obj.printarray();
            break;
            case 8:
            cout<<"Exiting the array!!!!!!"<<endl;
            default:    
            cout<<"Invalid choice! Please try again."<<endl;
            break;

        }

    }while(choice!=8);
}
