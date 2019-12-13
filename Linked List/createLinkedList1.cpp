/*
 * Note Creating Singly Linked List using Structure
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
        void printList();
};

int main(int argc, char
    const * argv[]) {
    int data, choice = 1;
    //Creating Object of linkedList class to Access Method
    LinkedList li;
    while (choice) {
        cout << "\n Enter Data : ";
        cin >> data;
        li.createNode(data);
        cout << "Do You Want To Insert More Node (0 | 1) : ";
        cin >> choice;
    }
    // Printing Created List
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

// Function to Print List
void LinkedList::printList() {
    temp = head;
    cout<<"\n Created Singly Linked List : ";
    while(temp != NULL) {
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
}