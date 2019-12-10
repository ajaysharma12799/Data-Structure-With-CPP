#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int size, pos;
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
    //Checking condition
    for (int i = pos - 1; i < size -1 ; i++)
    {
        //swapped array elements
        arr[i] = arr[i+1];
    }
    //decrementing size of array
    size--;
    //printing array
    cout<<"\n Deleted Array : ";
    for (int i = 0; i < size; i++)
    {
        cout<<"\t"<<arr[i];
    }
    return 0;
}
