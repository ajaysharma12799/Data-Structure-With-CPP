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
    cout<<"\n 1. To Create List : ";
    cout<<"\n 9. To Print List : ";
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