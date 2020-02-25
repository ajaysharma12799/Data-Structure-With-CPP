#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int x = 10; // Normal Variable

    int &ref = x; // Refrence Variables, Alias to that variable which is it pointing


    cout<<"\n Normal Variable : "<<x;
    cout<<"\n Refrence Variable : "<<ref;

    ref = 20;
    cout<<"\n After Change ";
    cout<<"\n Normal Variable : "<<x;
    cout<<"\n Refrence Variable : "<<ref;
    

    return 0;
}