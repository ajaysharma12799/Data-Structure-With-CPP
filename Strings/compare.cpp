#include <iostream>
#include <string.h>

using namespace std;

void compare() { // Function to compare two strings bases on ascii value
    char str1[] = "AjaySharma";
    char str2[] = "Ajay";
    int x = strcmp(str1, str2);
    if(x == 0) { // It returns zero if both strings are identical. All characters are same in both strings
        cout<<"\n Equal String";
    }
    else if (x < 0) { // It returns a value less than zero when the matching character of left string has lesser ASCII value than the character of the right string.
        cout<<"\n Smaller";
    }
    else if(x > 0) { // It returns a value greater than zero when the matching character of left string has greater ASCII value than the character of the right string.
        cout<<"\n Greater";
    }
    else {
        cout<<"\n Not Equal";
    }
}

int main(int argc, char const *argv[])
{
    compare();
    return 0;
}