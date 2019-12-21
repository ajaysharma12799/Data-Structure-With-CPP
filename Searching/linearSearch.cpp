#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[5], position, element, flag = 0;
    cout<<"\n Enter ELement in Array : ";
    for(int i = 0; i < 5; i++) {
        cin>>arr[i];
    }
    cout<<"\n Enter Search Element : ";
    cin>>element;
    for(int i = 0; i < 5; i++) {
        if(arr[i] == element) {
            flag = 1;
            position = i;
        }
    }
    if(flag == 1) {
        cout<<"\n Element : "<<element<<" is Found at : "<<position+1;
    }
    else {
        cout<<"\n Element is Not Found";
    }
    return 0;
}
