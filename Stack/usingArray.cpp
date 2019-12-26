#include <iostream>
# define size 5

using namespace std;

class Stack {
    private:
        int top;
    public:
        int arr[size];
        // Constructor to initilize top
        Stack() {
            top = -1;
        }
        // Methods
        void showChoice();
        void push(int data);
        void pop();
        void peek();
        void isEmpty();
        void display();
};

int main(int argc, char const *argv[])
{
    int choice;
    // Class Instance to access method
    Stack obj;
    do {

        obj.showChoice();
        cout<<"\n Enter Choice From Above Option : ";
        cin>>choice;
        switch(choice){
            
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
                obj.peek();
            break;

            case 5:
                obj.isEmpty();
            break;

            case 6:
                obj.display();
            break;

            case 0:
            break;
        }

    }while(choice != 0);
    
    return 0;
}

// Function to show choice
void Stack::showChoice() {
    cout<<"\n 1. Insert Element";
    cout<<"\n 2. Remove Element";
    cout<<"\n 3. Peek or Top ELement";
    cout<<"\n 5. isEmpty";
    cout<<"\n 6. display";
    cout<<"\n 0. To Quit";
}

// Function to push data 
void Stack::push(int data) {
    // Checking condition for stack not to be full
    if(top == size-1) {
        cout<<"\n OverFlow";
    }
    else {
        top++;
        arr[top] = data;
        cout<<"\n Successfully Inserted.";
    }
}

// Function to pop data
void Stack::pop() {
    // Checking condition for stack not to be empty
    if(top == -1) {
        cout<<"\n UnderFlow";
    }
    else {
        int item;
        item = arr[top--];
        cout<<"\n Poped Element : "<<item;
    }
}

void Stack::peek() {
    // Getting top Element
    int item;
    item = arr[top];
    cout<<"\n Peek Element : "<<item;
}

void Stack::isEmpty() {
    // Checking condition for stack to be empty
    if(top < 0) {
        cout<<"\n Stack is Empty";
    }
    else {
        cout<<"\n Stack is Full";
    }
}

void Stack::display() {
    cout<<"\n Stack : ";
    for(int i=top; i>=0; i--) {
        cout<<" "<<arr[i];
    }
}