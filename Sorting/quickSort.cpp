#include <iostream>

using namespace std;

class QuickSort {
    public:
        void quickSort(int arr[], int lower, int upper);
        void printArray(int arr[], int size);
};

int main(int argc, char const *argv[])
{
    int size;
    cout<<"\n Enter Size : ";
    cin>>size;
    int arr[size];
    cout<<"\n Enter Array Element : ";
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }

    // Class instance to access methods
    QuickSort obj;
    obj.quickSort(arr, 0, size-1);
    obj.printArray(arr, size);
    return 0;
}
int partition(int arr[], int lower, int upper) {
    int pivot = arr[lower];
    int start = lower;
    int end = upper;
    while(start < end) {
        while(arr[start] < pivot) {
            start++;
        }
        while(arr[end] > pivot) {
            end--;
        }
        // if condition fail swap element
        if (start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }   
    }
    return end;
}
void QuickSort::quickSort(int arr[], int lower, int upper) {
    int index = partition(arr, lower, upper);
    if(lower < upper) {
        quickSort(arr, lower, index-1);
        quickSort(arr, index+1, upper);
    }
}
void QuickSort::printArray(int arr[], int size) {
    cout<<"\n Sorted Array : ";
    for(int i=0; i<size; i++) {
        cout<<" "<<arr[i];
    }
}