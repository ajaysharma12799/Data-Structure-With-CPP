/*
 * Note Creating Singly Linked List using Structure & Class
 */

#include <iostream>

using namespace std;

// Creating Custom Type to created Node
struct Node {
    int data;
    struct Node * next;
};

struct Node * head = NULL, * newNode = NULL, * temp = NULL;

// Creating Class To Add Functions
class LinkedList {
    public:
        void createNode(int data);
        void insertBeg();
        void printList();
};

int main(int argc, char
    const * argv[]) {
    int data, choice = 1, option;
    //Creating Object of linkedList class to Access Method
    LinkedList li;
    // Calling CreateLinkedList Function
    while (choice) {
        cout << "\n Enter Data : ";
        cin >> data;
        li.createNode(data);
        cout << "Do You Want To Insert More Node (0 | 1) : ";
        cin >> choice;
    }
    // Calling Printing LinkedList Function
    li.printList();
    // Calling InsertatBeginning Function
    li.insertBeg();
    // Calling Printing LinkedList Function
    li.printList();
    return 0;
}

// Function to Create Singly Linked List
void LinkedList::createNode(int data) {
    // Allocating Memory using new
    newNode = new Node;

    // Adding data
    newNode -> data = data;
    newNode -> next = NULL;

    // Checking Condition for NULL
    if (head == NULL) {
        head = temp = newNode;
    } else {
        temp -> next = newNode;
        temp = newNode;
    }
}

// Function to insert at Begenning
void LinkedList::insertBeg() {
    // Taking Input of Data
    int data;
    cout<<"\n Enter Data To Insert : ";
    cin>>data;
    newNode = new Node;
    if(newNode == NULL) {
        // if newNode is Null then we are unable to allocate memory
    }
    else {
        // if newNode is not Null then we are going to insert data and address newNode next pointer to head
        newNode->data = data;
        newNode->next = head;
        // making head as newNode
        head = newNode;
    }
}

// Function to Print List
void LinkedList::printList() {
    temp = head;
    cout<<"\n Created Singly Linked List : ";
    while(temp != NULL) {
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
}