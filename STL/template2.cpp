// Class Template
#include <iostream>

using namespace std;

template <class T>
class Person {
    
    private:
        T a;
    
    public:
        void setValue(T a);
        T getValue();
};

template <typename T>
void Person<T>::setValue(T a) {
    this->a = a;
}

template <typename T>
T Person<T>::getValue() {
    return a;
}

int main(int argc, char const *argv[])
{    
    Person<int> obj;
    obj.setValue(5);
    cout<<"Returned Value : "<<obj.getValue();
    return 0;
}
/*
    Note: When we define function outside class at that time we need to also 
        declare template line other it will give error for undefined template variable
*/