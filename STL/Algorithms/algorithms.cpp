#include <algorithm>
#include <iostream>
#include <numeric> // For Accumulate Operation

using namespace std;

void print(int arr[]) {
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9}   ;
    int newarr[9];
    int *max = max_element(arr, arr+9);
    int *min = min_element(arr, arr+9);
    int sum = accumulate(arr, arr+9, 0);
    int counter = count(arr, arr+9, 1);

    // STL Array Algorthms
    all_of(arr, arr+9, [](int x) { return x > 0; }) ? cout<<"\n All are Positive Number" : cout<<"\n All are Negative Number";
    any_of(arr, arr+9, [](int x) { return x > 0; }) ? cout<<"\n Some are Positive Number" : cout<<"\n Some are Negative Number";
    none_of(arr, arr+9, [](int x) { return x > 0; }) ? cout<<"\n None are Positive Number" : cout<<"\n None are Negative Number"; 
    copy_n(arr, 6, newarr); // Copy New Array
    print(newarr);

    cout<<"\n Max ELement : "<<*max;
    cout<<"\n Min ELement : "<<*min;
    cout<<"\n Summation of ELement : "<<sum;
    cout<<"\n Count of Any ELement { 1 } : "<<counter;
    return 0;
}