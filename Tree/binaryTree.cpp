#include <iostream>

using namespace std;

struct Node {
    struct Node *left;
    int data;
    struct Node *right;
};

class BTree {
    public:
        void showChoice();
        struct Node *createNode(int data);
        struct Node *addNode(struct Node *temp, int value);
        void inOrderTraversal(struct Node *temp);
        void preOrderTraversal(struct Node *temp);
        void postOrderTraversal(struct Node *temp);
};

int main(int argc, char const *argv[])
{
    struct Node *root= NULL;
    BTree obj;
    // root = obj.createNode();
    int choice;
    do {
        obj.showChoice();
        cout<<"\n Enter Choice : ";
        cin>>choice;

        switch(choice) {

            case 1:
            {
                int data;
                cout<<"\n Enter Data : ";
                cin>>data;
                root = obj.createNode(data);
            }
            break;
            case 2:
            {
                int data;
                cout<<"\n Enter Data : ";
                cin>>data;
                obj.addNode(root, data);
            }
            break;
            case 3:
                cout<<"In-Order Traversal : ";
                obj.inOrderTraversal(root);
            break;
            case 4:
                cout<<"Pre-Order Traversal : ";
                obj.preOrderTraversal(root);
            break;
            case 5:
                cout<<"Post-Order Traversal : ";
                obj.postOrderTraversal(root);
            break;

        }

    } while(choice != 0);
    return 0;
}

void BTree::showChoice() {
    cout<<"\n 1. Create Node";
    cout<<"\n 2. Insert Node";
    cout<<"\n 3. In-Order Traversal";
    cout<<"\n 4. Pre-Order Traversal";
    cout<<"\n 5. Post-Order Traversal";
    cout<<"\n 0. Quit";
}

// Function to Create Node
struct Node * BTree::createNode(int data) {
    struct Node *newNode = NULL;
    // Allocating Memory
    newNode = new Node;
    // inserting data into node
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert Node
struct Node * BTree::addNode(struct Node *temp, int value) {
    // Checking condition for value then inserting left or right child
    if(temp == NULL) {
        temp = createNode(value);
        return temp;
    }
    else if (value < temp->data) {
        // Checking Left Side to be null or not
        if( !(temp->left == NULL) ) {
            addNode(temp->left, value);
        }
        else {
            temp->left = createNode(value);
        }
    }
    else if (value > temp->data) {
        // Checking Right Side to be null or not
        if( !(temp->right == NULL) ) {
            addNode(temp->right, value);
        }
        else {
            temp->right = createNode(value);
        }
    }
    else {
        return NULL;
        cout<<"\n Node With Same Value Exists";
    }
}

// In-Order Traversal
void BTree::inOrderTraversal(struct Node *temp) {
    // Checking Condition for null
    if(temp == NULL) {
        return ;
    }
    else {
        inOrderTraversal(temp->left);
        cout<<" "<<temp->data;
        inOrderTraversal(temp->right);
    }
}

// Pre-order Traversal
void BTree::preOrderTraversal(struct Node *temp) {
    // Checking Condition for null
    if(temp == NULL) {
        return ;
    }
    else {
        cout<<" "<<temp->data;
        preOrderTraversal(temp->left);
        preOrderTraversal(temp->right);
    }
}

// Post-order Traversal
void BTree::postOrderTraversal(struct Node *temp) {
    // Checking Condition for NULL
    if(temp == NULL) {
        return ;
    }
    else {
        postOrderTraversal(temp->left);
        postOrderTraversal(temp->right);
        cout<<" "<<temp->data;
    }
}