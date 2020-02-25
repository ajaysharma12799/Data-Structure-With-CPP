// Predefined Header File
#include <iostream>
// Custom Header File
#include "namespace1.h"
#include "namespace2.h"

// Predefined Namespace
using namespace std;
// Custom Namespace
using namespace ADD_INT;
using namespace ADD_INT;

namespace Class {
    class person;
}

class Class::person {
    private:
        int age;
    public:
        person();
        void print();
};

Class::person::person() {
    age = 22;
}
void Class::person::print() {
    cout<<"\n Person Age : "<<age;
}


int main(int argc, char const *argv[])
{
    // From Header File
    cout<<"\n Addition of Two Number : "<<ADD_INT::add(5, 5);
    cout<<"\n Addition of Three Number : "<<ADD_INT::add(5, 5, 6);

    // From Self File
    Class::person obj;
    obj.print();
    return 0;
}