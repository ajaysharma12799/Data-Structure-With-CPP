#include <iostream>

using namespace std;

struct Queue {
    int data;
    struct Queue *next;
};

struct Queue *newNode = NULL, *front = NULL, *rear = NULL; 

class List{
    public:
        void showChoice();
        void Enqueue(int data);
        void Dequeue();
        void peek();
        void display();
};

int main(int argc, char const *argv[])
{
    List obj;
    int choice;
    do {

        obj.showChoice();
        cout<<"\n Enter Choice From Above Option : ";
        cin>>choice;

        switch(choice) {
            case 1:
            {
                int choice = 1;
                while(choice) {
                    int data;
                    cout<<"\n Enter Data : ";
                    cin>>data;
                    obj.Enqueue(data);

                    cout<<"\n Want to insert more element ( 0 | 1 ) : ";
                    cin>>choice;
                }
            }
            break;

            case 2:
                obj.Dequeue();
            break;

            case 3:
                obj.peek();
            break;

            case 5:
                obj.display();
            break;
        }

    } while(choice != 0);
    return 0;
}

void List::showChoice() {
    cout<<"\n 1. Insert Element";
    cout<<"\n 2. Remove Element";
    cout<<"\n 3. Peek Element";
    cout<<"\n 5. Display";
    cout<<"\n 0. Quit";
}

void List::Enqueue(int data) {
    
    newNode = new Queue;

    newNode->data = data;
    newNode->next = NULL;

    if( (front == NULL) && (rear == NULL) ) {
        front = rear = newNode;
        cout<<"\n Successfully inserted First Node";
    }
    else {
        rear->next = newNode;
        rear = newNode;
        cout<<"\n Successfully inserted Other Node";
    }
}

void List::Dequeue() {
    struct Queue *temp = NULL;
    if( (front == NULL) && (rear == NULL) ) {
        cout<<"\n Empty Queue";
    }
    else {
        temp = front;
        front = front->next;
        delete temp;
    }
}

void List::peek() {
    if( (front == NULL) && (rear == NULL) ) {
        cout<<"\n Empty Queue";
    }
    else {
        cout<<"\n Peek Element : "<<front->data;
    }
}

void List::display() {
    struct Queue *temp = NULL;
    temp = front;
    cout<<"\n Queue : ";
    while(temp != NULL) {
        cout<<" "<<temp->data;
        temp = temp->next;
    }
}