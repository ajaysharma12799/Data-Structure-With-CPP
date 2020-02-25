#include <algorithm>
#include <iostream>

using namespace std;

void print(int arr[]) {
    for(int i=0; i<10; i++) {
        cout<<arr[i]<<" ";
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {2,1,3,5,4,9,6,8,7}   ;
    cout<<"\n Array Before Sorting : ";
    print(arr);

    sort(arr, arr+10); // STL Sort Function, take second argument as how many number of block you want to sort

    cout<<"\n Array After Sorting : ";
    print(arr);
    return 0;
}