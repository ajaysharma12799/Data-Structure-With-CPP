/*
 *  The problem is nCr = n!/(n-r)! * n!
*/
#include <iostream>

using namespace std;

// Main Problem Function but not recursively
int nCr(int n, int r) {
    int num1, num2, num3;
    num1 = factorial(n);
    num2 = factorial(r);
    num3 = factorial(n-r);

    return num1/(num2 * num3);
}

// Factorial of Function
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
    int combination = nCr(2, 3);
    cout<<"Combination : "<<combination;
    return 0;
}