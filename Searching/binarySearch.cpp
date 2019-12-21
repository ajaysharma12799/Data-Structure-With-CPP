#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[5], element, lower, upper, mid, flag = 0;
    cout<<"\n Enter Array ELements : ";
    for(int i=0; i<5; i++) {
        cin>>arr[i];
    }
    cout<<"\n Enter Search Element : ";
    cin>>element;
    lower = 0, upper = 4;
    while(lower <= upper) {
        mid = (lower+upper)/2;
        if(arr[mid] == element) {
            flag = 1;
        }
        if(arr[mid] < element) {
            lower = mid+1;
        }
        else {
            upper = mid-1;
        }
    }
    if(flag == 1) {
        cout<<"\n Element Found";
    }
    else {
        cout<<"\n Not Found";
    }
    return 0;
}
