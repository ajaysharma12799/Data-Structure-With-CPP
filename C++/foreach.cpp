#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5};
    
    for(int i:arr) {
        cout<<i<<" ";
    }
       
    return 0;
}