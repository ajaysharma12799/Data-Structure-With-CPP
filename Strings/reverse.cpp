#include <iostream>
#include <string.h>

using namespace std;

void reverseloop() { // Function using reverse loop to reverse string
    char str [] = "Ajay Sharma";
    int length = strlen(str);
    for(int i=length; i >= 0; i--) {
        cout<<str[i];
    }
}

void reverse_2_String() { // Function using 1 extra string to reverse string
    char str[] = "Ajay Sharma", newStr[15];
    int length = strlen(str), i, j;
    for(i=0; str[i] != '\0'; i++) {
    }
    i = i-1;
    for(j=0; i>=0; i--, j++) {
        newStr[j] = str[i];
    }
    newStr[j] = '\0';

    //printing string
    for(int i=0; i<length; i++) {
        cout<<newStr[i];
    }
}

int main(int argc, char const *argv[])
{
    reverseloop();
    cout<<endl;
    reverse_2_String();
    return 0;
}