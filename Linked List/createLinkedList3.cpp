/*
 * Note Creating Circular Linked List using Structure & Class
*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL, *newNode = NULL, *temp = NULL;

class LinkedList {
    public:
        void showChoices();
        void createList();
        void insetBeg();
        void insertPosition();
        void insertEnd();
        void deleteBeg();
        void deleteEnd();
        void deletePosition();
        void reverseList();
        void printList();
};

int main(int argc, char const *argv[])
{
    int choice;
    // Class instance to access methods
    LinkedList li;
    do {
        
        li.showChoices();
        cout<<"\n Enter Choice :";
        cin>>choice;
        switch(choice) {
            case 1:
            int choice;
            while(choice) {
                li.createList() ;
                cout<<"\n Want to Add More Data ( 0 | 1 ) : ";
                cin>>choice;
            }
            break;

            case 2: 
            li.insetBeg();
            break;

            case 3:
            li.insertPosition();
            break;

            case 4: 
            li.insertEnd();
            break;

            case 5:
            li.deleteBeg();
            break;

            case 6:
            li.deleteEnd();
            break;

            case 7:
            li.deletePosition();
            break;

            case 8:
            li.reverseList();
            break;

            case 9:
            li.printList();
            break;

            case 0:
            break;
        }

    }while(choice != 0);
    return 0;
}

// Function to Show Choices
void LinkedList::showChoices () {
    cout<<"\n 1. To Create List";
    cout<<"\n 2. To Insert At Beginning";
    cout<<"\n 3. To Insert At Specific Position";
    cout<<"\n 4. To Insert At End";
    cout<<"\n 5. To Delete At Beginning";
    cout<<"\n 6. To Delete At End";
    cout<<"\n 7. To Delete At Specific position";
    cout<<"\n 8. To Reverse List";
    cout<<"\n 9. To Print List";
    cout<<"\n 0. To Quit";
}

// Function to Create List
void LinkedList::createList() {
    int data;
    // Allocating Memory
    newNode = new Node;
    cout<<"\n Enter Data : ";
    cin>>data;
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL) {
        head = temp = newNode;
    }
    else {
        temp->next = newNode;
        temp = newNode;
    }
    temp->next = head;
}

// Function to Print List
void LinkedList::printList() {
    // Checking NULL Condition
    if(head == 0) {
        cout<<"\n List is Empty";
    }
    else {
        temp = head;
        cout<<"\n Printed Linked List : ";
        while(temp->next != head) {
            cout<<" "<<temp->data;
            temp = temp->next;
        }
        cout<<" "<<temp->data;
    }
}

// Function to insert Node at Beginning
void LinkedList::insetBeg() {
    int data;
    // Allocating Memory
    newNode = new Node;
    cout<<"\n Enter Data : ";
    cin>>data;
    newNode->data = data;
    newNode->next = head;
    // Checking Head Condition not to be NULL
    if(head == NULL) {
        cout<<"\n List is Empty";
    }
    else {
        temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        head = newNode;
    }
}

// Function to insert Node at Specific position
void LinkedList::insertPosition() {
    int data, position, i = 1;
    cout<<"\n Enter Position : ";
    cin>>position;
    cout<<"\n Enter Data : ";
    cin>>data;
    temp = head;
    // Allocating Memory
    newNode = new Node;
    newNode->data = data;
    while(i < position -1) {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert Node at End
void LinkedList::insertEnd() {
    int data;
    cout<<"\n Enter Data : ";
    cin>>data;
    temp = head;
    //Allocating Memory
    newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete Node at Beginning
void LinkedList::deleteBeg() {
    if(head == NULL) {
        cout<<"\n Failed to Remove Node";
    }
    else {
        temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        /*
        *   Another Way :-
            *   temp->next = head->next;
            *   head = head->next;
        */
        delete temp;
    }
}

// Function to delete Node at End
void LinkedList::deleteEnd() {
    struct Node *current = NULL;

    if(head == NULL) {
        cout<<"\n UnderFlow Condition";
    }else if(head->next == NULL) {
        delete head;
    }
    else {
        current = head;
        while(current->next != head) {
            temp = current;
            current = current->next;
        }
        temp->next = head;
        /*
        *   Another Way:-
        *   temp->next = current->next;
        */
       delete current;
    }
}

// Function to delete Node at Specific Position
void LinkedList::deletePosition() {
    cout<<"\n Empty Function";
}

// Function to Reverse List
void LinkedList::reverseList() {
    cout<<"\n Empty Function";
}