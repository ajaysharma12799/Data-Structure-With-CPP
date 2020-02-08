#include <iostream>

// using namespace std;

int main(int argc, char const *argv[])
{
    int count = 0;
    char str[] = "Ajay";

    for(int i=0; str[i] != '\0'; i++) {
        count++;
    }

    std::cout<<"\n Length of String : "<<count;
    return 0;
}