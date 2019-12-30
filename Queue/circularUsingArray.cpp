/*
*   Circular Queue
*/

#include <iostream>
#define size 5

using namespace std;

class Queue {
    public:
        int arr[size];
        int front;
        int rear;

        Queue() {
            front = rear = -1;
        }

        // Methods
        void Enqueue(int data);
        void Dequeue();
        void display();
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
    obj.Dequeue();
    obj.Dequeue();
    obj.display();
    return 0;
}

void Queue::Enqueue(int data) {
    if( (front == -1) && (rear == -1) ) {
        front = rear = 0;
        arr[rear] = data;
    }
    else if( (rear+1)%size == front ) {
        cout<<"\n Queue if Full";
    }
    else {
        rear = ( (rear+1)%size );
        arr[rear] = data;
    }
}

void Queue::Dequeue() {
    if( (front == -1) && (rear == -1) ) {
        front = rear = -1;
    }
    else if( front == rear ) {
        cout<<"\n Empty Queue";
    }
    else {
        cout<<"\n Remove Element : "<<arr[front];
        front = (front+1) % size;
    }
}

void Queue::display() {
    int i = front;
    if( (front == -1) && (rear == -1) ) {
        cout<<"\n Empty Queue";
    }
    else {
        cout<<"\nQueue is : ";
        while(i != rear) {
            cout<<" "<<arr[i];
            i = (i+1)%size;
        }
    }
}