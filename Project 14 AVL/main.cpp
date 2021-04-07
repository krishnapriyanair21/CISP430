#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct node
{
    int value;
    node* left;
    node* right;
    int height;
};

struct nodePrint
{
    node* leaf;
    nodePrint* next;
};
struct queue
{
    nodePrint* front = NULL;
    nodePrint* rear = NULL;
};

node* rebalance(node* n);
node* insert(node* n, int key);
node*leftRotate(node *x);
node* rightRotate(node *x);
int getBalance(node* n);
void printLevel(node* root, ofstream& out);
void enqueue(queue &queue, node *leaf);
node *dequeue(queue &queue);
int max(int a, int b);
int getHeight (node* leaf);
void setHeight(node * leaf);

int main()
{
    node* root = '\0';
    int temp = 0;
    ifstream in;
    in.open("input.txt");
    if (!in)
    {
        cout <<"error opening file"<<endl;
    }
    ofstream out;
    out.open("output.txt");
    if (!out)
    {
        cout <<"Failed to open file"<<endl;
    }
    while (in >> temp)
    {
        root = insert(root, temp);
    }
    printLevel(root, out);

    cout<<"printed"<<endl;

    in.close();
    out.close();
    return 0;
}

int getBalance(node* n)
{
    return (getHeight(n->left) - getHeight(n->right));
}

node* rebalance(node *n){
    setHeight(n);
    int balance = getBalance(n);//node->left - node->right
    int innBalance = 55;

    if (balance == 2){
        innBalance = getBalance(n->left);
        if (innBalance == -1 ){   ///If left heavy inside:  left rotation first, right rotation 2nd, return top node
            n->left =  leftRotate(n->left);
    		return rightRotate(n);
        }
        else{
            return rightRotate(n); ///If Left heavy outside :  return rightRotate(node);
        }
    }
    else if (balance == -2){
        innBalance = getBalance(n->right);
        if (innBalance == 1){   ///if right heavy inside: right rotation first, left rotation 2nd, return top node
            n->right = rightRotate(n->right);
        	return leftRotate(n);
        }
        else{
            return leftRotate(n); /// If right heavy outside:  return leftRotate(node);
        }
    }
    else{
        return n;
    }

}
node* insert(node* n, int key)
{
    //recursive Code for inserting a node
    //When insert happens set height to 0 for the node
    if (n == NULL){
        node* nn = new node;
        nn->left = nn->right = NULL;
        nn->height = 0;
        nn->value = key;
        n = nn;
        return n;
    }
    if (key < n->value){
        n->left  = insert(n->left, key);
    }
    else{
        n->right = insert(n->right, key);
    }
    n=rebalance(n);
    return n;
}

node* leftRotate(node* x){
    node* y = x->right;
    node* z = y->left;
    x->right = y->left;
    y->left = x;

    setHeight(z);
    setHeight(x);
    setHeight(y);

   return y;
}

node* rightRotate(node *x){
    node* y = x->left;
    node* z = y->right;
    x->left = y->right;
    y->right = x;

    setHeight(z);
    setHeight(x);
    setHeight(y);
    return y;
}

void printLevel(node* root, ofstream& out)
{
    queue curr;
    queue next;
    node* temp = NULL;
    enqueue(curr, root);
    while (curr.front){
        temp = dequeue(curr);
        out <<temp->value <<" (" <<getHeight(temp)<<","<<getBalance(temp)<<")        ";
        if (temp->left)
            enqueue(next, temp->left);
        if (temp->right)
            enqueue(next, temp->right);
        if (!curr.front){
            curr = next;
            next.front= next.rear= NULL;
            out<<endl;
        }
    }
}

void enqueue(queue &queue, node *leaf)
{
    nodePrint* nn = new nodePrint;
    nn->leaf = leaf;
    nn->next = NULL;
    if (queue.rear)
    {
        queue.rear->next = nn;
        queue.rear = nn;
    }
    else
    {
        queue.front = queue.rear = nn;
    }
}
node *dequeue(queue &queue)
{
    node* temp = NULL;
    if (queue.front)
    {
        temp = queue.front->leaf;
        nodePrint* frTemp = queue.front;
        queue.front = queue.front->next;
        delete frTemp;
        if (!(queue.front))
        {
            queue.front = queue.rear = NULL;
        }
    }
    return temp;
}

int max(int a, int b) {
    return (a < b) ? b : a;
}

int getHeight (node* leaf) {
    if (leaf) {
        return leaf->height;
    }
    else {
        return -1;
    }
}
void setHeight(node * leaf) {
    if (leaf) {
        leaf->height = max(getHeight(leaf->left), getHeight(leaf->right)) + 1;
    }
}
