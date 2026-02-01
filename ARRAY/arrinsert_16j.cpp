#include <iostream>
using namespace std;

class insertion
{
public:
    int size ;
    int array[10];
   
    int position;
    int element;
     void inputsize(){
        cout<<"Enter current size of array (max 9): ";
        cin>>size;
     }
    void input()
    {
        cout << "Enter data of array:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "enter element at index " << i << ": ";
            cin >> array[i];
        }
    }

    void insert()
    {
        if (size >= 10)
        {
            cout << "Array is full" << endl;
        }
        else if(size < 0)
        {
            cout << "Array is empty" << endl;
        }   
        else
        {
            cout << "Enter position to insert element: ";
            cin >> position;
            cout << "Enter element to insert: ";
            cin >> element;

            if (position < 0 || position > size)
            {
                cout << "Invalid position!" << endl;
            }
            else
            {
                for (int i = size; i > position; i--)
                {
                    array[i] = array[i - 1];
                }
                
                array[position] = element;
                size++;
            }
        }
    }

    void print()
    {
        cout << "array after insertion: ";
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{   insertion obj;
    int choice;

    do {
        cout << "\n--- Menu ---" << endl;
        cout<<"1. Input Size of Array"<<endl;
        cout << "2. Input Array" << endl;
        cout << "3. Insert Element" << endl;
        cout << "4. Print Array" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.inputsize();
                break;
            case 2:
                obj.input();
                break;
            case 3:
                obj.insert();
                break;
            case 4:
                obj.print();
                break;
            case 5: 
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
  
}