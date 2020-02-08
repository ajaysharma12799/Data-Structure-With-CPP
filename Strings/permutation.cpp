#include <iostream>
#include <string.h>

using namespace std;

void swap(char *s1, char *s2) {
    char temp;

    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void permutate(char *string, int start, int end) {
    // base case for length of string
    if(start == end) {
        cout<<string<<endl;
    }
    else {
        for(int i=start; i<=end; i++) {

            // Swapping done  
            swap(string[start], string[i]);  
  
            // Recursion called  
            permutate(string, start+1, end);  
  
            //backtrack  
            swap(string[start], string[i]); 
        }
    }
}

int main(int argc, char const *argv[])
{
    char str[] = "abc";
    int length = strlen(str);
    permutate(str, 0, length-1);
    return 0;
}