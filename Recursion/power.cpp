#include <iostream>

using namespace std;

int power(int num, int pow) {
    if(num == 0) { // base codition
        return 1;
    }

    if(num == 1) {
        return 1;
    }
    else {
        return num * power(num, pow-1);
    }
}

int main(int argc, char const *argv[])
{
    int pow = power(5, 10);
    cout<<"Power : "<<pow;
    return 0;
}