#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    float x = -1;

    try {
        if(x < 0) {
            cout<<"\n Value is less than 0";
            throw x;
        }
        else {
            cout<<"\n Value is greater than -1";
        }
    }
    catch(int e) {
        cout<<"\n Exception Occured Due to "<< e;
    }
    catch(...) {
        cout<<"\n Exception Caught by Catch-All Block";
    }

    return 0;
}