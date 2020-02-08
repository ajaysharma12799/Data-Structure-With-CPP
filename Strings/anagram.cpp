#include <iostream>
#include <string.h>

#define MAX_CHAR 256

using namespace std;

bool isanagram(char *s1, char *s2) {
    int length1 = strlen(s1);
    int length2 = strlen(s2);

    // checking is string are not of equal length
    if(length1 != length2) {
        return false;
    }

    int first[MAX_CHAR] = { 0 }, second[MAX_CHAR] = { 0 };

    for(int i=0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        first[s1[i]]++;
        second[s2[i]]++;
    }

    // checking condition for int array
    for(int i=0; i<MAX_CHAR; i++) {
        if(first[i] != second[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    char str1[] = "ajay";
    char str2[] = "ajay";

    if(isanagram( str1, str2 )) {
        cout<<"\n String is Anagram";
    }
    else {
        cout<<"\n String is not Anagram";
    }
    return 0;
}