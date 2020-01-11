#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

class BST {
    public:
        void showChoice();
        struct Node *create(int key);

        struct Node *insertIterative(struct Node *temp, int key);
        struct Node *insertRecursive(struct Node *temp, int key);

        void inorderTraversal(struct Node *temp);

        struct Node *searchElement(struct Node *temp, int key);
        struct Node *deleteElement(struct Node *temp, int key);

        struct Node *inorderSuccessor(struct Node *temp);
        struct Node *inorderPredecessor(struct Node *temp);
};

int main(int argc, char const *argv[])
{
    int choice;
    struct Node *root = NULL;
    BST obj;
    do {

        obj.showChoice();
        cout<<"\n Enter Choice From Above Menu : ";
        cin>>choice;
        switch(choice) {
            case 1:{
                int key;
                cout<<"\n Enter key : ";
                cin>>key;
                root = obj.create(key);
            }
            break;
            case 2:{
                int key;
                cout<<"\n Enter Data to insert : ";
                cin>>key;
                obj.insertIterative(root, key);
            }
            break;
            case 3:{
                    int key;
                    cout<<"\n Enter Data to insert : ";
                    cin>>key;
                    obj.insertRecursive(root, key);
            }
            break;
            case 4:
                cout<<"\n In-Order Traversal : ";
                obj.inorderTraversal(root);
            break;
            case 5:{
                int key;
                struct Node *fake = NULL;
                cout<<"\n Enter Data to Search : ";
                cin>>key;
                fake = obj.searchElement(root, key);
                if(fake != NULL) {
                    cout<<"\n Element is Present";
                }
                else {
                    cout<<"\n Element is Not Present";
                }
            }
            break;
            case 6:{
                int key;
                struct Node *fake = NULL;
                cout<<"\n Enter Key to be deleted : ";
                cin>>key;
                fake = obj.deleteElement(root, key);
                if(fake != NULL) {
                    cout<<"\n Deleted Node";
                }
                else {
                    cout<<"\n Fail to Delete Node";
                }
            }
            break;

        }

    } while(choice != 0);
    return 0;
}

// FUnction to show Choices
void BST::showChoice() {
    cout<<"\n 1. Create BST";
    cout<<"\n 2. Insert via Iteration";
    cout<<"\n 3. Insert via Recursion";
    cout<<"\n 4. In-Order Traversal";
    cout<<"\n 5. Searching Element";
    cout<<"\n 6. Delete Element";
    cout<<"\n 0. To Quit";
}

// Function to create BST
struct Node *BST::create(int data){
    struct Node *newNode = NULL;

    newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to insert Node using iterative method
struct Node *BST::insertIterative(struct Node *temp, int key) {
     struct Node *fake = NULL;

     while(temp != NULL) {
         fake = temp;

         //Searching
         if(temp == NULL) {
             return create(key);
         }
         else if (key < temp->data) {
             temp = temp->left;
         }
         else {
             temp = temp->right;
         }
     }
     // Checking less or large condition
     if(key < fake->data) {
         fake->left = create(key);
     }
     else {
         fake->right = create(key);
     }

}

// Function to insert Node using recursive method
struct Node *BST::insertRecursive(struct Node *temp, int key) {

    if(temp == NULL) {
        return create(key);
    }
    else if(key < temp->data) {
        temp->left = insertRecursive(temp->left, key);
    }
    else if(key > temp->data) {
        temp->right = insertRecursive(temp->right, key);
    }
    else {
        return 0;
    }

    return temp;
}

// Function for In-Order Traversal
void BST::inorderTraversal(struct Node *temp) {
    if(temp != NULL) {
        inorderTraversal(temp->left);
        cout<<" "<<temp->data;
        inorderTraversal(temp->right);
    }
}

// Function to Search Element
struct Node *BST::searchElement(struct Node *temp, int key) {
    if( (temp == NULL) || (key == temp->data) ) {
        return temp;
    }
    else if(key < temp->data) {
        return searchElement(temp->left, key);
    }
    else if(key > temp->data) {
        return searchElement(temp->right, key);
    }
}

// Function to delete Node
struct Node *BST::deleteElement(struct Node *temp, int key) {

    // Checking for NULL Condition
    if(temp == NULL) {
        return temp;
    }

    // Checking for key is smaller
    if(key < temp->data) {
        temp->left = deleteElement(temp->left, key);
    }
    else if(key > temp->data) { // Checking for key is greater
        temp->right = deleteElement(temp->right, key);
    }
    else { // found when key is same as node data
        
        // Checking whether node has one child or no child
        if(temp->left == NULL) {
            struct Node *fake = temp->right;
            delete temp; // deleting right node
            return fake;
        }
        else if (temp->right == NULL) {
            struct Node *fake = temp->left;
            delete temp; // deleting left node
            return fake;
        }
        else { // node having both children
            struct Node *fake = inorderSuccessor(temp->right);
            // struct Node *fake = inorderPredecessor(temp->left);
            temp->data = fake->data;
            temp->right = deleteElement(temp->right, fake->data); // deleting inorder successor
        }

    }
    return temp;

}

// Function to find In-Order Successor
struct Node *BST::inorderSuccessor(struct Node *temp) { // finding smallest element from right sub tree

    while( (temp != NULL) && (temp->left != NULL)) {
        temp = temp->left;
    }
    return temp;

}

// Function to find In-Order Predecessor
struct Node *BST::inorderPredecessor(struct Node *temp) { // finding largest element from left sub tree
    
    while( (temp != NULL) && (temp->right != NULL) ) {
        temp = temp->right;
    }
    return temp;

}