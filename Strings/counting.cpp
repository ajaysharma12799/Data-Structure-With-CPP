#include <iostream>

using namespace std;

void count() {
    int wCount = 0, vCount = 0;
    char str[] = "Ajay";
    for(int i = 0; str[i] != '\0'; i++) {

        if( (str[i] == 'A') || (str[i] == 'E') || (str[i] == 'I') || (str[i] == 'O') || (str[i] == 'U') ) { // UPPERCASE VOWELS
            vCount++ ;
        }
        else if( (str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u') ) { // LOWERCASE VOWELS
            vCount++;
        }
        else { // WORDS
            if(str[i] == ' ') {
                wCount++;
            }
        }

    }
    cout<<"\n Vowel Count : "<<vCount;
    cout<<"\n Word Count : "<<wCount+1;
}

int main(int argc, char const *argv[])
{
    count();
    return 0;
}