// Function Template
#include <iostream>

using namespace std;

template <typename T>
// template <class T>
T Max(T a, T b) {
    if(a > b) {
        return a;
    }
    else {
        return b;
    }
}

template <typename T1, typename T2>
void Add(T1 num1, T2 num2) {
    cout<< num1 + num2;
}

int main(int argc, char const *argv[])
{
    cout<<"Greater : "<<Max<int>(1, 2)<<endl;
    cout<<"Greater : "<<Max<float>(10.6, 2.0)<<endl;

    // cout<<"Addition of two different type : "<<Add<int>(1, 5.0)<<endl;
    // cout<<"Addition of two different type : "<<Add<float>(1, 5.0)<<endl;
    Add(1, 5.0);
    Add(5.0, 1);
    return 0;
}