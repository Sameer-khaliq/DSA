#include "iostream"
using namespace std;
class traverse{
    public:
    int arr[5];
    void inputarray(){
        cout<<"Enter 5 elements of the array: "<<endl;
        for(int i=0; i<5; i++){
            cout<<"Element "<<i+1<<": ";
            cin>>arr[i];
        }
    }
    void traversearray(){
        cout<<"The elements of the array are: "<<endl;
        for(int i=0; i<5; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    traverse obj;
    obj.inputarray();
    obj.traversearray();

}