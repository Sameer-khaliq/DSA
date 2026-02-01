#include <iostream>
using namespace std;
int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    for (int i=0; i<size; i++){
        cout<<"enter element at index "<<i+1<<": ";
        cin>>arr[i];
    }
    int smallest= INT_MAX;
    int index;
    for (int i=0; i<size; i++){
        if (arr[i]<smallest)
        {
            smallest=arr[i];
            index=i;
        }
       
    }
     cout<<"The smallest element is: "<<smallest<<" at index: "<<index<<endl;
}
