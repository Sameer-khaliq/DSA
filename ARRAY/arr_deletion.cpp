#include "iostream"
using namespace std;
class deletion{
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
    void delete_element(){
        cout<<"Enter position to delete the element: ";
        cin>>position;
        if (position>=size){
            cout<<"Invalid position!";
        }
        else{
            for(int i=position; i<size; i++){
                arr[i]= arr[i+1];
            }
            size--;

        }
    }
void showarray(){
    cout<<"The array after deletion"<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

};
 int main(){
    deletion obj;
    obj.inputsize();
    obj.inputarray();
    obj.delete_element();
    obj.showarray();
 }