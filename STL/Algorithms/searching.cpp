#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{   
    int arr[] = {1,2,3,4,5,6,7,8,9};
    if(binary_search(arr, arr+10, 1)) {
        cout<<"\n Element Found";
    }
    else {
        cout<<"\n Element not Found";
    }
    return 0;
}