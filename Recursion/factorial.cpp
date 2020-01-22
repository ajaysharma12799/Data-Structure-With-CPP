#include <iostream>

using namespace std;

int factorial(int n) {
    if(n == 0) { // base condition
        return 1;
    }

    if (n == 1) {
        return 1;
    }
    else {
        return factorial(n-1) * (n);
    }
}
int main(int argc, char const *argv[])
{
    int fact = factorial(3);
    cout<<"Factorial : "<<fact;
    return 0;
}