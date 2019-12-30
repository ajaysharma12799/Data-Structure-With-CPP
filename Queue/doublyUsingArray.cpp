/*
*   Doubly Ended Queue 
*/

#include <iostream>
#define size 5

using namespace std;

class Queue {
    public:
        int arr[size];
        int front, rear;

        // Constructor
        Queue() {
            front = rear = -1;
        }

        // Methods
        void showChoice();
        void insertFront(int data);
        void insertRear(int data);
        void deleteFront();
        void deleteRear();
        bool isEmpty();
        bool isFull();
        void display();

};

int main(int argc, char const *argv[])
{
    int choice;
    Queue obj;
    do {

        obj.showChoice();
        cout<<"\n Enter Choice From Above Option : ";
        cin>>choice;
        
        switch(choice) {
            
            case 1:{
                int data;
                cout<<"\n Enter Data : ";
                cin>>data;
                obj.insertFront(data);
            
            }
            break;

            case 2:{
                int data;
                cout<<"\n Enter Data : ";
                cin>>data;
                obj.insertRear(data);
            }
            break;

            case 3:
                obj.deleteFront();
            break;

            case 4:
                obj.deleteRear();
            break;

            case 5:
                obj.display();
            break;

        }

    } while(choice != 0);
    return 0;
}

void Queue::showChoice() {
    cout<<"\n 1. Insert at Front";
    cout<<"\n 2. Insert at Rear";
    cout<<"\n 3. delete at Front";
    cout<<"\n 4. delete at Rear";
    cout<<"\n 5. display";
    cout<<"\n 0. Quit";
}

void Queue::insertFront(int data) {
    if(isFull()) {
        cout<<"\n OverFlow For Front Insertion";
    }
    else {
        if(front == -1) { // checking for queue to be empty
            front = 0;
            rear = 0;
        }
        else if (front == 0) {
            front = size-1;
        }
        else {
            front--;
        }
        arr[front] = data;
    }
}

void Queue::insertRear(int data) {
    if(isFull()) {
        cout<<"\n OverFlow For Rear Insertion";
    }
    else {
        if(front == -1) { // checking for queue to be empty
            front = 0;
            rear = 0;
        }
        else if(rear == size-1) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = data;
    }
}

void Queue::deleteFront() {
    if(isEmpty()) {
        cout<<"\n UnderFlow For Front Deletion";
    }
    else {
        cout<<"\n Front Removed Element : "<<arr[front];
        if(front == rear) { // if only one element is present
            front = -1;
            rear = -1;
        }
        else if (front == size-1) { // if front is pointing to last element then moving it to point to first element
            front = 0;
        }
        else { // incrementing front
            front++;
        }
    }
}

void Queue::deleteRear() {
    if(isEmpty()) {
        cout<<"\n UndeFlow For Rear Deletion";
    }
    else {
        cout<<"\n Rear Removed Element : "<<arr[rear];
        if(front == rear) { // if only one element is present
            front = -1;
            rear = -1;
        }
        else if(rear == 0) { // if pointing to first element then moving it to point to last element
            rear = size-1;
        }
        else {
            rear = rear-1;
        }
    }
}

bool Queue::isEmpty() {
    if( (front == -1) && (rear == -1) ) {
        return true;
    }
    else {
        return false;
    }
}

bool Queue::isFull() {
    if( ( (front == 0) && (rear == size-1) ) || (front == (rear+1)%size) ) {
        return true;
    }
    else {
        return false;
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