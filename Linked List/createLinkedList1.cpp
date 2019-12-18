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
        void insetEnd();
        void insertPosition();
        void deleteBeg();
        void deleteEnd();
        void deletePosition();
        void count();
        void reverseList();
        void searchElement();
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
    // Calling InsertatEnd Function
    li.insetEnd();
    // Calling Printing LinkedList Function
    li.printList();
    // Calling Count Element Function
    li.count();
    // Calling Insert at Position Function
    li.insertPosition();
    // Calling Print List Function
    li.printList();
    // Calling DeleteBeginning Function
    li.deleteBeg();
    // Calling Print List Function
    li.printList();
    // Calling DeleteatEnd Function
    li.deleteEnd();
    // Calling Print List Function
    li.printList();
    // Calling DeleteatPosition Function
    li.deletePosition();
    // Calling Print List Function
    li.printList();
    // Calling Search Element Function
    li.searchElement();
    // Calling Print List Function
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
        cout<<"\n Unable To Allocate Memory";
    }
    else {
        // if newNode is not Null then we are going to insert data and address newNode next pointer to head
        newNode->data = data;
        newNode->next = head;
        // making head as newNode
        head = newNode;
    }
}

// Function to insert at End
void LinkedList::insetEnd()
{
    //Taking Input
    int data;
    cout<<"\n Enter Data To Insert : ";
    cin>>data;
    newNode = new Node;
    //Inserting Data into newNode
    newNode->data = data;
    newNode->next = NULL;
    temp = head;
    //Traversing Whole List
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert at Specific Position
void LinkedList::insertPosition() {
    int position, data, i = 1;
    //Taking position input
    cout<<"\n Enter Position : ";
    cin>>position;
    newNode = new Node;
    cout<<"\n Enter Data : ";
    cin>>newNode->data;
    temp = head;
    while(i < position) {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete Element at Beginning
void LinkedList::deleteBeg(){
    temp = head;
    head = head->next;
    delete temp;
}

// Function to delete Element at End
void LinkedList::deleteEnd(){
    struct Node *prevNode = NULL;
    temp = head;
    while(temp->next != NULL) {
        prevNode = temp;
        temp = temp->next;
    }
    // Checking if temp is not pointing to head
    if(temp == head) {
        head = NULL;
    }
    else {
        prevNode->next = NULL;
    }
    // deleting last node
    delete temp;
}

// Function to delete Element at Specific Position
void LinkedList::deletePosition() {
    struct Node *nextNode = NULL;
    temp = head;
    int position, i = 1;
    cout<<"\n Enter Position : ";
    cin>>position;
    while(i < position-1) {
        temp = temp->next;
        i++;
    }
    nextNode = temp->next;
    temp->next = newNode->next;
    delete temp;
}

// Function to search Element 
void LinkedList::searchElement() {
    int searchElement, flag = 0;
    cout<<"\n Enter Element to be Searched : ";
    cin>>searchElement;
    temp = head;
    while(temp->next != NULL) {
        if(searchElement == temp->data) {
            flag = 1;
        }
        temp = temp->next;
    }
    if(flag == 1) {
        cout<<"\n Element is Present : "<<searchElement;
    }
    else {
        cout<<"\n Element is Not Present : "<<searchElement;
    }
}

// Function to Count Number of Element in List
void LinkedList::count() {
    //Counter Variable
    int count = 0;
    temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    cout<<"\n Number of Element in List : "<<count;
}

// Function to Print List
void LinkedList::printList() {
    temp = head;
    cout<<"\n Printed Singly Linked List : ";
    while(temp != NULL) {
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
}