#include <iostream>

using namespace std;

int printReverse(int n) {
    // base condition
    if(n > 0) {
        cout<<" "<<n;
        printReverse(n-1);
    }
}

int printSimple(int n) {
    // base condition
    if(n > 0) {
        printSimple(n-1);
        cout<<" "<<n;
    }
}

int main(int argc, char const *argv[])
{

    cout<<"\n Reverse : ";
    printReverse(3);

    cout<<"\n Simple : ";
    printSimple(3);

    return 0;
}