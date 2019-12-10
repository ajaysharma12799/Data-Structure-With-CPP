#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int size1, size2, newSize;
    cout<<"\n Enter Size 1 : ";
    cin>>size1;
    cout<<"\n Enter Size 2 : ";
    cin>>size2;
    newSize = size1 + size2;
    //creating array of specific size
    int arr1[size1], arr2[size2], newArray[newSize];
    //taking input in array
    cout<<"\n Enter Element in Array 1 : ";
    for(int i=0; i< size1; i++) {
        cin>>arr1[i];
    }
    cout<<"\n Enter Element in Array 2 : ";
    for(int i=0; i< size2; i++) {
        cin>>arr2[i];
    }
    //inserting first array element
    for(int i=0; i< size1; i++) {
        newArray[i] = arr1[i];
    }
    //merging second array
    for(int i=0, j=size1; i< size2 && j< newSize; i++,j++) {
        newArray[j] = arr2[i];
    }
    //printing array
    cout<<"\n New Merged Array : ";
    for(int i = 0; i< newSize; i++) {
        cout<<"\t"<<newArray[i];
    }
    return 0;
}