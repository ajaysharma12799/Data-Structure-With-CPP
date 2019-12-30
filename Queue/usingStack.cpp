#include <iostream>
#define size1 5
#define size2 5

using namespace std;

class Stack1 {
    public:
        int top1;
        int arr1[size1];

        // Constructor to initilize top
        Stack1() {
            top1 = -1;
        }

        // Methods
        void push1(int data);
        int pop1();
};

class Stack2 {
    public:
        int top2;
        int arr2[size1];

        // Constructor to initilize top
        Stack2() {
            top2 = -1;
        }

        // Methods
        void push2(int data);
        int pop2();
};

class Queue {
    public:
        Stack1 obj1;
        Stack2 obj2;
        int count;
        void Enqueue(int data);
        void Dequeue();
        void display();

        Queue() {
            count = 0;
        }
};

int main(int argc, char const *argv[])
{
    Queue obj;
    obj.Enqueue(1);
    obj.Enqueue(2);
    obj.Enqueue(3);
    obj.Enqueue(4);
    obj.Enqueue(5);

    obj.display();

    obj.Dequeue();
    obj.Dequeue();

    obj.display();

    obj.Enqueue(10);

    obj.display();
    return 0;
}

// Methods of Stack 1
void Stack1::push1(int data) {
    if(top1 == size1-1) {
        cout<<"\n Stack 1 Full";
    }
    else {
        arr1[top1++] = data;
    }
}

int Stack1::pop1() {
    int item;
    if(top1 == -1) {
        cout<<"\n Stack 1 Empty";
    }
    else {
        item = arr1[top1--];
    }
    return item;
}

// Methods of Stack 2
void Stack2::push2(int data) {
    if(top2 == size2-1) {
        cout<<"\n Stack 1 Full";
    }
    else {
        arr2[top2++] = data;
    }
}

int Stack2::pop2() {
    int item;
    if(top2 == -1) {
        cout<<"\n Stack 1 Empty";
    }
    else {
        item = arr2[top2--];
    }
    return item;
}

// Method of Queue
void Queue::Enqueue(int data) {
    obj1.push1(data);
    cout<<"\n Count 1 TIme : "<<count;
    count++;
    cout<<"\n\t\t Count 2 Time : "<<count;
}

void Queue::Dequeue() {
    
    // Stack1 obj1;
    // Stack2 obj2;
    int num1, num2, num3;

    if( (obj1.top1 == -1) && (obj2.top2 == -1) ) {
        cout<<"\n Queue is Empty";
    }
    else {
        for(int i=0; i<count; i++) {
            num1 = obj1.pop1();
            obj2.push2(num1);
        }
        num2 = obj2.pop2();
        cout<<"\n Dequed Element : "<<num2;
        count--; // Decrementing count after poping element from queue
        for(int i=0; i<count; i++) { // again poping element from second stack and inserting into first stack
            num3 = obj2.pop2();
            obj1.push1(num3);
        }
    }
}

void Queue::display() {
    cout<<"\n Queue : ";
    for(int i=obj1.top1; i>=0; i--) {
        cout<<"  "<<obj1.arr1[i];
    }
}