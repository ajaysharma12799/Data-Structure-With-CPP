#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int size, temp, j;
    cout<<"\n Enter Size : ";
    cin>>size;
    int arr[size];
    cout<<"\n Enter Array Element : ";
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }
    for(int i=1; i<size; i++) {
        temp = arr[i];
        j = i-1;
        while( (j >= 0) && (arr[j] > temp) ) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    //Printing Array
    cout<<"\n Sorted Array : ";
    for(int i=0; i<size; i++) {
        cout<<" "<<arr[i];
    }
    return 0;
}
