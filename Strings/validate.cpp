#include <iostream>

using namespace std;

bool validate() {
    char str[] = "Ajay123";
    for(int i=0; str[i] != '\0'; i++) {
        if( !(str[i] >= 65 && str[i] <= 90) 
                           && 
            !(str[i] >= 97 && str[i] <= 122) 
                           && 
            !(str[i] >= 48 && str[i] <= 57) ) {

            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    if(validate()) {
        cout<<"\n Valid String";
    }
    else {
        cout<<"\n In-valid String";    
    }
    return 0;
}