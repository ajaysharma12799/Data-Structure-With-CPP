#include <iostream>

#define size 5

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
    void push(int data);
    int pop();
    bool isEmpty();
};

class Queue {
    public:
        Stack obj1, obj2;

    void Enqueue(int data);
    int Dequeue();
    void display();
};

int main(int argc, char
    const * argv[]) {
    Queue obj;
    obj.Enqueue(1);
    obj.Enqueue(2);
    obj.Enqueue(3);
    obj.Enqueue(4);
    obj.Enqueue(5);
    obj.display();
    cout << "\n Remove Element : " << obj.Dequeue();
    cout << "\n Remove Element : " << obj.Dequeue();
    obj.Enqueue(10);
    obj.Enqueue(15);
    obj.display();
    return 0;
}

// Methods of Stack 1
void Stack::push(int data) {
    if (top >= size) {
        cout << "\n Stack is Full";
    } else {
        top++;
        arr[top] = data;
    }
}

int Stack::pop() {
    int item;
    if (top == -1) {
        cout << "\n Stack is Empty";
        return 0;
    } else {
        item = arr[top--];
        return item;
    }
}

bool Stack::isEmpty() {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

// Method of Queue
void Queue::Enqueue(int data) {
    obj1.push(data);
}

int Queue::Dequeue() {
    int num1, num2;
    while (!obj1.isEmpty()) {
        num1 = obj1.pop();
        obj2.push(num1);
    }

    num2 = obj2.pop();

    while (!obj2.isEmpty()) { // again poping element from second stack and inserting into first stack
        num1 = obj2.pop();
        obj1.push(num1);
    }
    return num2;
}

void Queue::display() {
    cout << "\n Queue : ";
    for (int i = 0; i < size; i++) {
        cout << " " << obj1.arr[i];
    }
}