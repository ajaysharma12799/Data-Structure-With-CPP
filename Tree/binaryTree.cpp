#include <iostream>
#include <stack>
// #include <bits/stl_queue.h>
#include <queue>

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
        void leveOrderTraversal(struct Node *temp);
        void iterativeInOrderTraversal(struct Node *temp);
        void iterativePreOrderTraversal(struct Node *temp);
        void iterativePostOrderTraversal(struct Node *temp);
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
            case 6:
                cout<<"Iterative In-Order Traversal : ";
                obj.iterativeInOrderTraversal(root);
            break;
            case 7:
                cout<<"Iterative Pre-Order Traversal : ";
                obj.iterativePreOrderTraversal(root);
            break;
            case 8:
                cout<<"Iterative Post-Order Traversal : ";
                obj.iterativePostOrderTraversal(root);
            break;
            case 9:
                cout<<"Level Order Traversal : ";
                obj.leveOrderTraversal(root);
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
    cout<<"\n 6. Iterative In-Order Traversal";
    cout<<"\n 7. Iterative Pre-Order Traversal";
    cout<<"\n 8. Iterative Post-Order Traversal";
    cout<<"\n 9. Level Order Traversal";
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

// Iterative In-Order Traversal
void BTree::iterativeInOrderTraversal(struct Node *temp) {
    stack<Node *> s;
    while(true) {

        while(temp != NULL) {
            s.push(temp);
            temp = temp->left;
        }

        if(s.empty()) { // breaking condition of outer while loop
            break;
        }

        temp = s.top(); // error : a value of type void cannot be assigned to an entity of type Node *, so we are taking top into root then rempvong element using pop method
        s.pop(); 
        cout<<" "<<temp->data;
        temp = temp->right;

    }
}

// Iterative In-Order Traversal
void BTree::iterativePreOrderTraversal(struct Node *temp) {
    stack<Node *> s;
    while(true) {

        while(temp != NULL) {
            cout<<" "<<temp->data;
            s.push(temp);
            temp = temp->left;
        }

        if(s.empty()) { // breaking condition for outer loop
            break;
        }

        temp = s.top();
        s.pop();
        temp = temp->right;
    }
}

// Iterative In-Order Traversal
void BTree::iterativePostOrderTraversal(struct Node *temp) {
    stack<Node *> s1, s2;
    struct Node *fake = NULL;

    s1.push(temp);// pushing root node into stack
    while( !s1.empty() ) { // checking if stack one is not empty than remove element from stack one and push into stack two

        fake = s1.top();
        s1.pop();
        s2.push(fake);

        if(fake->left != NULL) {// pushing left children of popped node into stack one
            s1.push(fake->left);
        }
        if(fake->right != NULL) {// pushing right children of popped node into stack one
            s1.push(fake->right);
        }

    }
    while( !s2.empty() ) { // checking if stack two is not empty the pop elements from stack and print data
        fake = s2.top();
        s2.pop();
        cout<<" "<<fake->data;
    }
}

// Level Order Traversal
void BTree::leveOrderTraversal(struct Node *temp) {
    queue<Node *> q;
    struct Node *fake = NULL;

    q.push(temp);
    while( !q.empty() ) {

        fake = q.front();
        q.pop();
        cout<<" "<<fake->data;

        if(fake->left != NULL) {
            q.push(fake->left);
        }

        if(fake->right != NULL) {
            q.push(fake->right);
        }

    }
}