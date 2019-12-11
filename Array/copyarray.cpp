#include <iostream>
using namespace std; 
int main(int argc, char const *argv[])
{
    int size1, newSize = 0, i = 0;
    //taking input
    cout<<"\n Enter Size of Array : ";
    cin>>size1;
    //creating array of specific size
    int arr[size1], newArray[newSize];
    //taking input 
    cout<<"\n Enter Array Element : ";
    for(int i=0; i<size1; i++) {
        cin>>arr[i];
    }
    //copying array 
    while(i < size1) {
        newArray[newSize++] = arr[i];
        i++;
    }
    //print array 
    cout<<"New Copied Array : ";
    for(int i = 0; i < newSize; i++) {
        cout<<" "<<newArray[i];
    }
    return 0;
}
