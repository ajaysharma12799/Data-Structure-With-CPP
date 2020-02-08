#include <iostream>
#include <string.h>

using namespace std;

void upperCase() { // Function for Changing lower case to upper case
    char str[] = "ajay", newstr[5];
    int length = strlen(str);
    for(int i=0; str[i] != '\0'; i++) {
        newstr[i] = str[i] - 32;
    }
    cout<<"New UpperCase String : ";
    for(int i=0; i<length; i++) {
        cout<<" "<<newstr[i];
    }
}

void lowerCase() { // Function for changing upper case to lower case
    char str[] = "AJAY", newstr[5];
    int length = strlen(str);
    for(int i=0; str[i] != '\0'; i++) {
        newstr[i] = str[i] + 32;
    }
    cout<<"New Lowercase String : ";
    for(int i=0; i<length; i++) {
        cout<<" "<<newstr[i];
    }
}

void toggleCase() {
    char str[] = "AjaY", newstr[5];
    int length = strlen(str);
    for(int i=0; str[i] != '\0'; i++) {
        if(str[i] >= 65 && str[i] <= 90) { // UPPERCASE
            newstr[i] = str[i] + 32;
        }
        else if(str[i] >= 97 && str[i] <= 122) { // LOWERCASE
            newstr[i] = str[i] - 32;
        }
    }
    cout<<"New Toggle String : ";
    for(int i=0; i<length; i++) {
        cout<<" "<<newstr[i];
    }
}

int main(int argc, char const *argv[])
{
    upperCase(); // Function for UPPERCASE
    cout<<endl;
    lowerCase(); // Function for LOWERCASE
    cout<<endl;
    toggleCase(); // Function for TOGGLECASE
    return 0;
}