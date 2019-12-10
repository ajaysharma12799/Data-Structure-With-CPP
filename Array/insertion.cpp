#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int size, pos, element;
    cout<<"\n Enter Size : ";
    cin>>size;
    //creating array of specific size
    int arr[size];
    //input element in array
    cout<<"\n Enter Element in Array : ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"\n Enter Position Where to insert : ";
    cin>>pos;
    cout<<"\n Enter Element : ";
    cin>>element;
    //Checking condition
    for (int i = size; i >= pos -1 ; i--)
    {
        //swapped array elements
        arr[i+1] = arr[i];
    }
    //inserting element into array
    arr[pos-1] = element;
    //incrementing size of array
    size++;
    //printing array
    cout<<"\n Inserted Array : ";
    for (int i = 0; i < size; i++)
    {
        cout<<"\t"<<arr[i];
    }
    return 0;
}
