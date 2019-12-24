#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int size, min, temp;
    cout<<"\n Enter Size : ";
    cin>>size;
    int arr[size];
    cout<<"\n Enter Array Element : ";
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }
    for(int i=0; i<size-1; i++) {
        min = i;
        for(int j=i+1; j< size; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        //Swapping on base of min value
        if(min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    // Printing Array
    cout<<"\n Sorted Array : ";
    for(int i=0; i<size; i++) {
        cout<<" "<<arr[i];
    }
    return 0;
}
