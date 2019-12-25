#include <iostream>

using namespace std;

class mergeSort {
    public:
        void divideArray(int arr[], int lower, int upper);
        void mergeArray(int arr[], int lower, int middle, int upper);
        void printArray(int arr[], int size);
};

int main(int argc, char const *argv[])
{
    int size;
    cout<<"\n Enter Size of Array : ";
    cin>>size;
    int arr[size];
    cout<<"\n Enter Array Element : ";
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }
    // Class Instance to access method
    mergeSort obj;
    obj.divideArray(arr, 0, size-1);
    obj.printArray(arr, size); // Method for printing Array
    return 0;
}

void mergeSort::divideArray(int arr[], int lower, int upper) {
    if(lower < upper) {
        int middle = (lower + upper) / 2;

        // Calling Recursion on left half
        divideArray(arr, lower, middle);
        // Calling Recursion on right half
        divideArray(arr, middle+1, upper);
        // Calling merge function
        mergeArray(arr, lower, middle, upper);
    }
}

void mergeSort::mergeArray(int arr[], int lower, int middle, int upper) {
    int tempArray[upper];
    int i = lower, j = middle+1, k = 0;

    while( (i <= middle) && (j <= upper) ) {
        if(arr[i] <= arr[j]) {
            tempArray[k] = arr[i];
            i++;
        }
        else {
            tempArray[k] = arr[j];
            j++;
        }
        k++;
    }

    // Checking Condition for Left over Element
    if(i > middle) {
        // Left over Element of Right Sub Array
        while(j <= upper) {
            tempArray[k] = arr[j];
            j++;
            k++;
        }
    }
    else {
        while(i <= middle) {
            tempArray[k] = arr[i];
            i++;
            k++;
        }
    }

    // Copying Original array value into temporary array
    for(int i=upper; i>= lower; i--) {
         arr[i] = tempArray[--k];
    }
}

void mergeSort::printArray(int arr[], int size) {
    cout<<"\n Sorted Array : ";
    for(int i=0; i<size; i++) {
        cout<<" "<<arr[i];
    }
}