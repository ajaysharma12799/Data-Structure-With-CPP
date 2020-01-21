#include <iostream>

using namespace std;

int naturalSum(int n) {

    if(n == 0) {
        return 0;
    }
    else {
        return naturalSum(n-1) + n;
    }

}

int main(int argc, char const *argv[])
{
    int sum = naturalSum(5);
    cout<<"Sum : "<<sum;
    return 0;
}