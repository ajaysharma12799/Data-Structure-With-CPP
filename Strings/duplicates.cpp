#include <iostream>

using namespace std;

void duplicates() {
    char str1[] = "Ajay";
    char str2[] = "Ajay";
    int i, j, counts = 0;

    for(i=0, j=0; str1[i] != '\0', str2[j] != '\0'; i++, j++) {
        if(str1[i] == str2[j]) {
            counts++;
        }
    }
    cout<<"\n Total Duplicates : "<<counts;
}

int main(int argc, char const *argv[])
{
    duplicates();
    return 0;
}