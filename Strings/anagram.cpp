#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

bool isanagram(char s1[], char s2[]) {
    int length1 = strlen(s1);
    int length2 = strlen(s2);

    // checking is string are not of equal length
    if(length1 != length2) {
        return false;
    }
    else {
        
    }
}

int main(int argc, char const *argv[])
{
    char str1[] = "Ajay";
    char str2[] = "Ajay";

    if(isanagram( str1, str2 )) {
        cout<<"\n String is Anagram";
    }
    else {
        cout<<"\n String is not Anagram";
    }
    return 0;
}