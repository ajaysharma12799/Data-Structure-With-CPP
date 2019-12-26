#include <iostream>

using namespace std;

struct Stack {
    int data;
    struct Stack *next;
};

struct Stack *top = NULL, *newNode = NULL;

class List {
    public:
        void showChoice();
        void push(int data);
        void pop();
        void isEmpty();
        void display();
};

int main(int argc, char const *argv[])
{
    int choice;
    List obj;
    do {

        obj.showChoice();
        cout<<"\n Enter Choice From Above : ";
        cin>>choice;
        switch(choice) {
            case 1:
                int data;
                cout<<"\n Enter Data : ";
                cin>>data;
                obj.push(data);
            break;

            case 2:
                obj.pop();
            break;

            case 3:
                obj.isEmpty();
            break;

            case 4:
                obj.display();
            break;
        }

    }while(choice != 0);
    return 0;
}

void List::showChoice() {
    cout<<"\n 1. Insert Element";
    cout<<"\n 2. Remove Element";
    cout<<"\n 3. isEmpty";
    cout<<"\n 4. Display";
    cout<<"\n 0. Quit";
}

void List::push(int data) {
    // Allocating Memory
    newNode = new Stack;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void List::pop() {
    struct Stack *temp = NULL;
    temp = top;
    cout<<"\n Removed Element : "<<top->data;
    top = top->next;
    delete temp;
}

void List::isEmpty() {
    // Checking Condition for top to be null
    if(top == NULL) {
        cout<<"\n Stack is Empty";
    }
    else {
        cout<<"\n Stack is Full";
    }
}

void List::display() {
    struct Stack *temp = NULL;
    temp = top;
    if(temp == 0) {
        cout<<"\n Stack is Empty";
    }
    else {
        cout<<"\n Printed Stack : ";
        while(temp != NULL) {
            cout<<" "<<temp->data;
            temp = temp->next;
        }
    }
}