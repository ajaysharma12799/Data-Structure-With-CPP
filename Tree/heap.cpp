#include <iostream>

using namespace std;

void swap(int *num1, int *num2) { // swapping element
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void max_Heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2*i + 1;
    int right = (2*i) + 2;

    while( (left < n) && (arr[left] > arr[largest]) ) { // checking whether left child is large or not
        largest = left;
    }
    while( (right < n) && (arr[right] > arr[largest]) ) { // checking whether right child is large or not
        largest = right;
    }

    if(largest != i) {
        swap( arr[i], arr[largest] );
        max_Heapify(arr, n, largest);
    }

}

void min_Heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    while( (left > n) && (arr[left] < arr[smallest]) ) { // checking whether left child is large or not
        smallest = left;
    }
    while( (right > n) && (arr[right] < arr[smallest]) ) { // checking whether right child is large or not
        smallest = right;
    }

    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        min_Heapify(arr, n, smallest);
    }
}

void heap_Sort(int arr[], int n) {
    for(int i=(n/2)-1; i>=0; i--) { // building max heap
        max_Heapify(arr, n, i);
    }

    for(int i=n-1; i>=0; i--) { // extracting one by one element from heap
        swap(arr[0], arr[i]);
        max_Heapify(arr, i, 0); // calling max_heapify on reduced heap
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    heap_Sort(arr, n);
    cout<<"\n Sorted Array : ";
    printArray(arr, n);
    return 0;
}

/*
    Heapify up is used when we insert a new element to a heap.
    When inserting a new element, we add it at the bottom of the heap tree,
    and move up the tree while comparing to the current parent element and swapping if needed.
    Because we move up for heapify up, we only make one comparison per iteration,
    between the current element and its parent element.

    Heapify down is used when we remove the top element from a heap. 
    Removal of an element is done by swapping the top element with the last element at the bottom of the tree,
    removing the last element, and then heapfying the new top element down to maintain the heap property. 
    Because this moves down the heap tree, it must perform two comparisons per iteration, 
    with the left child and the right child elements, then swap with the smaller one.
    Because of this, heapify down is usually more complex to implement than heapify up.
*/
