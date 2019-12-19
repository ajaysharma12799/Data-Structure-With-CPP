#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node * prev;
    struct Node * next;
};

struct Node *head = NULL, *newNode = NULL, *temp = NULL;

class LinkedList {
    public:
        void showChoice();
        void createList();
        void insertBeg();
        void insertEnd();
        void insertPosition();
        void count();
        void printList();
};

int main(int argc, char const * argv[]) {
    int choice;
    // Class instance to access method
    LinkedList li;
    do {

        li.showChoice();
        cout<<"\n Enter Choice From Above Option : ";
        cin>>choice;

        // Applying Cases
       switch(choice) {
           // Create List Case
           case 1:{
               int choice = 1;
               while(choice) {
                   li.createList();
                   cout<<"\n Do You Want To Add More Data ( 0 | 1 ) : ";
                   cin>>choice;
               }
           }
           break;
        
           case 2:
           li.insertBeg();
           break;

           case 3:
           li.insertEnd();
           break;

           case 4:
           li.insertPosition();
           break;

           case 8:
           li.count();
           break;

           case 9:
            li.printList();
           break;

           case 0: 
           break;
       }

    }while( choice != 0);
    return 0;
}

// Function to Show Choices
void LinkedList::showChoice() {
    cout<<"\n";
    cout<<"\n 1. To Create List";
    cout<<"\n 2. To Insert Element at Beginning";
    cout<<"\n 3. To Insert ELement at End";
    cout<<"\n 4. To Insert Element at Specific Position";
    cout<<"\n 8. To Count Elements";
    cout<<"\n 9. To Print List";
    cout<<"\n 0. To Quit";
}

// Function to Create List
void LinkedList::createList() {
    int data;
    // Allocating Memory Dynamically
    newNode = new Node;
    cout<<"\n Enter Data : ";
    cin>>data;
    // Inserting data into node
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    // Checking head condition 
    if(head == NULL) {
        head = temp = newNode;
    }
    else {
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
}

// Function to insert Node at Beginning
void LinkedList::insertBeg() {
    int data;
    // Creating new Node
    newNode = new Node;
    cout<<"\n Enter Data : ";
    cin>>data;
    // Checking Condition for Head is not null
    if(head == NULL) {
        cout<<"\n Unable to Allocate Memort ";
    }
    else {
        newNode->data = data;

        head->prev = newNode;
        newNode->prev = NULL;
        newNode->next = head;
        head = newNode;
    }
}

// Function to insert Node at End
void LinkedList::insertEnd() {
    int data;
    cout<<"\n Enter Data : ";
    cin>>data;
    newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert element at Specific Position
void LinkedList::insertPosition() {
    int data, position, i = 0;
    cout<<"\n Enter Position : ";
    cin>>position;
    cout<<"\n Enter Data : ";
    cin>>data;
    newNode = new Node;
    newNode->data = data;
    temp = head;
    while(i <position - 1) {
        temp = temp->next;
        i++;
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
}

// Function to Count Number of Element
void LinkedList::count() {
    temp = head;
    int count = 0;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    cout<<"\n Number of Elements : "<<count;
}

// Function to Print List
void LinkedList::printList() {
    temp = head;
    cout<<"\n Printed Doubly Linked List : ";
    while(temp != NULL) {
        cout<<" "<<temp->data;
        temp = temp->next;
    }
}