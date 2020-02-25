#include <iostream>
#include <memory>

using namespace std;

class Person {
    private:
        int age;
    public:
        void setAge(int age) {
            this->age = age;
        }
        void getAge() {
            cout<<"\n Age of Person : "<<age;
        }
};

int main(int argc, char const *argv[])
{
    unique_ptr<Person> obj1(new Person); // auto pointer of type person
    obj1->setAge(5);
    obj1->getAge();

    cout<<"\n Some Methods of Unique Pointer";
    cout<<"\n Memory Address of Obj1 : "<<obj1.get();
    return 0;
}