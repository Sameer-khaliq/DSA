#include "iostream"
using namespace std;
class updation{
    public:
    int size;
    int position;
    int arr[10];
    void inputsize(){
        cout<<"enter the size of array (max 10): ";
        cin>>size;
        if (size<0 || size>10){
            cout<<"The size is invalid!"<<endl;
            inputsize();
        }
    }
    void inputarray(){
        cout<<"Enter the elements of array: "<<endl;
        for(int i=0; i<size ; i++){
            cout<<"Enter the element for index "<<i<<": ";        
            cin>>arr[i];
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
           arr[position]= arr[new_element];
        }
    }
void showarray(){
    cout<<"The array after update"<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

};
 int main(){
    updation obj;
    obj.inputsize();
    obj.inputarray();
    obj.update_element();
    obj.showarray();    
 }