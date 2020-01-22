#include <stdio.h>
#include <iostream>

using namespace std;

int TOH(int disc, int a, int b, int c) {
    if(disc > 0) { // base condition

        TOH(disc-1, a, c, b);
        
        printf("\n disc changed from %d to %d ", a, c);
        
        TOH(disc-1, b, a, c);

    }
    else {
        return 0;
    }
}
int main(int argc, char const *argv[])
{
    int tower = TOH(2, 1, 2, 3);
    return 0;
}