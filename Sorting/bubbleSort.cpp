#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int size, temp;
    cout<<"\n Enter Size : ";
    cin>>size;
    int arr[size];
    cout<<"\n Enter Array Element : ";
    for(int i=0;i<size; i++) {
        cin>>arr[i];
    }
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<"\n Sorted Array : ";
    for(int i=0; i<size; i++) {
        cout<<" "<<arr[i];
    }
    return 0;
}
