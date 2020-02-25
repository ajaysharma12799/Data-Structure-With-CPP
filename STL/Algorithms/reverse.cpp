#include <algorithm>
#include <iostream>

using namespace std;

void print(int arr[]) {
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9};   
    reverse(arr, arr+9);
    print(arr);
    return 0;
}