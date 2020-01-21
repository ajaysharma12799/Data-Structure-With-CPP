#include <iostream>

using namespace std;

int treeRecur(int n) {
    if(n > 0) {
        cout<<n<<" ";
        treeRecur(n-1);
        treeRecur(n-1);
    }
    else {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    treeRecur(3);
    return 0;
}