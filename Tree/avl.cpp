#include <stdio.h>
#include <iostream>

using namespace std;

struct Node {
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

class AVL {
    public:
        void showChoice();
        int max(int a, int b);
        int height(struct Node *temp);
        int getBalance(struct Node *temp);
        void inorderTraversal(struct Node *temp);
        void preorderTraversal(struct Node *temp);

        struct Node *createNode(int data);
        struct Node *leftRotate(struct Node *temp);
        struct Node *rightRotate(struct Node *temp);
        struct Node *insertNode(struct Node *temp, int data);
};

int main(int argc, char const *argv[])
{
    AVL obj;
    int choice;
    struct Node *root = NULL;

    do {

        obj.showChoice();
        cout<<"\n Enter Choice From above Menu : ";
        cin>>choice;

        switch(choice) {
            case 1: {
                int data;
                cout<<"\n Enter Data to insert : ";
                cin>>data;
                root = obj.insertNode(root, data);
            }
            break;

            case 3:
                cout<<"\n In-Order Traversal : ";
                obj.inorderTraversal(root);
                cout<<"\n Pre-Order Traversal : ";
                obj.preorderTraversal(root);
            break;
        }

    } while(choice != 0);

    return 0;
}

void AVL::showChoice() {
    cout<<"\n 1. Insert Node";
    cout<<"\n 2. Delete Node";
    cout<<"\n 3. In-Order Traversal";
    cout<<"\n 0. To Quit";
}

// Function to create Node
struct Node *AVL::createNode(int data) {
    struct Node *newNode = NULL;
    // Allocating Memory
    newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; // height will be 1 as new node is added
    return newNode;
}

// Function to Left rotate
struct Node *AVL::leftRotate(struct Node *temp) {
    struct Node *newHead = NULL, *fake = NULL;

    // Capturing Nodes
    newHead = temp->right;
    fake = newHead->left;

    // Rotating
    newHead->left = temp;
    temp->right = fake;

    // Updating Heights
    temp->height = max( height(temp->left), height(temp->right) ) + 1;
    newHead->height = max( height(temp->left), height(temp->right) ) + 1;

    // Returning new Root
    return newHead;
}

// Function to Right rotate
struct Node *AVL::rightRotate(struct Node *temp) {
    struct Node *newHead = NULL, *fake = NULL;

    // Capturing Nodes
    newHead = temp->left;
    fake = newHead->right;

    // Rotating
    newHead->right = temp;
    temp->left = fake;

    // Updating Heights
    temp->height = max( height(temp->left), height(temp->right) ) + 1;
    newHead->height = max( height(newHead->left), height(newHead->right) ) + 1;

    // Returning new Root
    return newHead;
}

// Function for inorder traversal
void AVL::inorderTraversal(struct Node *temp) {

    if(temp != NULL) {
        inorderTraversal(temp->left);
        cout<<" "<<temp->data;
        inorderTraversal(temp->right);
    }

}

void AVL::preorderTraversal(struct Node *root)  
{  
    if(root != NULL)  
    {  
        cout <<" "<< root->data << " ";  
        preorderTraversal(root->left);  
        preorderTraversal(root->right);  
    }  
}

// Function to insert Node
struct Node *AVL::insertNode(struct Node *temp, int data) {
    // 1. Normal BST Insertion
    if(temp == NULL) { // if node is not present
        return (createNode(data));
    }
    
    if (data < temp->data) { // if data is less then node data
        temp->left = insertNode(temp->left, data);
    }
    else if(data > temp->data) { // if data is greater then node data
        temp->right = insertNode(temp->right, data);
    }
    else { // found same key so returning
        return temp;
    }

    // 2. Update Height
    temp->height = max( height(temp->left), height(temp->right) ) + 1;

    // 3. Getting Balance Factor
    int balance  = getBalance(temp);

    /*
        NOTE :- if balance factor is between {-1, 0, 1} then then tree is AVL but if not then there are 4 case of rotation
        1. left left or LL
        2. right right or RR
        3. left right or LR
        4, right left or RL
    */

   // LL Rotation
   if( (balance > 1) && (data < temp->left->data) ) { // heavy left condition
       return rightRotate(temp);
   }

   // RR Rotation
   if( (balance < -1) && (data > temp->right->data) ) { // heavy right condition
       return leftRotate(temp);
   }

   // LEFT RIGHT Rotation
   if( (balance > 1) && (data > temp->left->data) ) {
       temp->left = leftRotate(temp->left);
       return rightRotate(temp);
   }

   // RIGHT LEFT Rotation
   if( (balance < -1) && (data < temp->right->data)) {
       temp->right = rightRotate(temp->right);
       return leftRotate(temp);
   }

   // returning unchanged pointer
   return temp;
}

// Function to return max of two value
int AVL::max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to get height of tree
int AVL::height(struct Node *temp) {
    //checking null condition
    if(temp == NULL) {
        return 0;
    }
    else {
        return temp->height;
    }
}

// Function to het Balance factor
int AVL::getBalance(struct Node *temp) {
    if(temp == NULL) {
        return 0;
    }
    else {
        return ( height(temp->left) - height(temp->right) );
    }
}