#include <iostream>
#define size 5

using namespace std;

class Queue {
    public:
        int front;
        int rear;
        int arr[size];

    // Constructor to initilize front and read
    Queue() {
        front = -1;
        rear = -1;
    }

    // Methods
    void showChoice();
    void enqueue(int data);
    void dequeue();
    void peek();
    void display();
};

int main(int argc, char
    const * argv[]) {
    // Class instance to access method
    Queue obj;
    int choice;
    do {

        obj.showChoice();
        cout << "\n Enter Choice From Above Option : ";
        cin >> choice;
        switch(choice) {

            case 1:
                int data;
                cout<<"\n Enter Data : ";
                cin>>data;
                obj.enqueue(data);
            break;

            case 2:
                obj.dequeue();
            break;

            case 3:
                obj.peek();

            case 5:
                obj.display();
            break;

            case 0:
            break;
        }

    } while (choice != 0);
    return 0;
}

void Queue::showChoice() {
    cout<<"\n 1. Insert Element (Enqueue) ";
    cout<<"\n 2. Remove Element (Dequeue) ";
    cout<<"\n 3. Peek Element";
    cout<<"\n 5. Display ";
    cout<<"\n 0. To Quit ";
}

void Queue::enqueue(int data) {
    // Checking Condition Queue to be full
    if(rear == size-1) {
        cout<<"\n OverFlow";
    }
    else if ( (front == -1) && (rear == -1) ) {
        front = rear = 0;
        arr[rear] = data;
        cout<<"\n Successfully Inserted at Front";
    }
    else {
        rear++;
        arr[rear] = data;
        cout<<"\n Successfully Inserted other Elements";
    }
}

void Queue::dequeue() {
    // Checking Condition Queue to be empty
    if(front == -1) {
        cout<<"\n UnderFlow";
    }
    else if(front == rear) { 
        front = rear = -1;
    }
    else {
        int item;
        item = arr[front];
        front++;
        cout<<"\n Removed Element : "<<item;
    }
}

void Queue::peek() {
    // Checking condition for stack to be empty
    if( (front == -1) && (rear == -1) ) {
        cout<<"\n Empty Queue";
    }
    else {
        cout<<arr[front];
    }
}

void Queue::display() {
    int i = front;
    cout<<"\n Queue Element : ";
    while(i < rear+1) {
        cout<<" "<<arr[i];
        i++;
    }
}