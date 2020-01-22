#include <iostream>

using namespace std;

int fib(int n) {
    
    if(n == 0) { // base condition
        return 0;
    }
    
    if(n == 1) {
        return 1;
    }
    else {
        return fib(n-2) + fib(n-1);
    }

}
int main(int argc, char const *argv[])
{
    int fibo = fib(10);
    cout<<"Fibonacci : "<<fibo;
    return 0;
}