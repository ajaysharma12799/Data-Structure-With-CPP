#include <iostream>
#include <string.h>
#define size 10

using namespace std;

class Stack {
    public:
        int top;
        char arr[size];

        // Constructor to initilize top
        Stack() {
            top = -1;
        }

        // Methods
        bool isBalanced(char exp[]);
        void push(char data);
        void pop();
        char peek();
        bool isEmpty();
};
int main(int argc, char const *argv[])
{
    char arr[] = {'[', '(', ')', ']'};
    Stack obj;
    // Checking isBalanced Condition
    if(obj.isBalanced(arr)) {
        cout<<"\n Balanced Symbol";
    }
    else {
        cout<<"\n UnBalanced Symbol";
    }
    return 0;
}

bool Stack::isBalanced(char exp[]) {
    cout<<"\n 1";
    for(int i=0; i<strlen(exp); i++) {
        cout<<"\n 2";
        // Pushing opening Element into Stack
        if( (exp[i] == '[') || (exp[i] == '{') || (exp[i] == '(') ) {
            cout<<"\n 3";
            push(exp[i]);
            cout<<"\n 4";
        }
        else if( (!isEmpty()) && (exp[i] == ')' &&  peek() == '(') || (exp[i] == '}' &&  peek() == '{') || (exp[i] == ']' &&  peek() == '[') ) {
            cout<<"\n 5";
            pop();
            cout<<"\n 6";
        }
        else {
            cout<<"\n 7";
            return false;
            cout<<"\n 8";
        }
    }
    if(isEmpty()) {
        cout<<"\n 9";
        return true;
    }
    else {
        cout<<"\n 10";
        return false;
    }
}

void Stack::push(char data) {
    // Checking condition for stack not to be full
    if(top == size-1) {
        cout<<"\n OverFlow";
    }
    else {
        arr[top] = data;
        top++;
    }
}

void Stack::pop() {
    // Checking condition for stack not be empty
    char item;
    if(top == -1) {
        cout<<"\n UnderFlow";
    }
    else {
        item = arr[top--];
    }
}

bool Stack::isEmpty() {
    if(top == -1) {
        return true;
    }
    else {
        return false;
    }
}

char Stack::peek() {
    return arr[top];
}