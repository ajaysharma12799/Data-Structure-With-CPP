#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int size1, size2, newsize = 0, a = 0, b = 0;

    cout<<"\n Enter Size 1 : ";
    cin>>size1;
    cout<<"\n Enter Size 2 : ";
    cin>>size2;

    //creating array of specific size
    int arr1[size1], arr2[size2], newArray[50];

    //taking input of both array 
    cout<<"\n Enter Element in Array 1 : ";
    for(int i=0; i<size1; i++) {
        cin>>arr1[i];
    }
    cout<<"\n Enter Element in Array 2 : ";
    for(int i=0; i<size2; i++) {
        cin>>arr2[i];
    }

    //sorting element and merging
    while( (a < size1) && (b < size2) ) {
        if(arr1[a] < arr2[b]) {
            newArray[newsize] = arr1[a];
            newsize++;
            a++;
        }
        else {
            newArray[newsize] = arr2[b];
            newsize++;
            b++;
        }
    }

    //Storing rest element
    while(a < size1) {
        newArray[newsize++] = arr1[a++];
    }
    while(b < size2) {
        newArray[newsize++] = arr2[b++];
    }
    
    //Printing Array
    cout<<"\n Merge Sorted Array : ";
    for(int i = 0; i < newsize; i++) {
        cout<<"  "<<newArray[i];
    }
    return 0;
}