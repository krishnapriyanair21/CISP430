#include <iostream>
#include <string>
#include <fstream>


using namespace std;

struct BinaryTreeNode
{
    string value;
    BinaryTreeNode* left = NULL;
    BinaryTreeNode* right = NULL;
};
struct node
{
    BinaryTreeNode* leaf;
    node* next;
};
struct queue
{
    node* front = NULL;
    node* rear = NULL;
};

void Insert(BinaryTreeNode *& leaf, string item);
BinaryTreeNode* Delete(BinaryTreeNode *& leaf, string item);
void preOrder(BinaryTreeNode* root, ofstream& out);
void inOrder(BinaryTreeNode* root, ofstream& out);
void postOrder(BinaryTreeNode* root, ofstream& out);
void printLevel(BinaryTreeNode* root, ofstream& out);
void enqueue(queue &queue, BinaryTreeNode *leaf);
BinaryTreeNode *dequeue(queue &queue);


int main()
{
    string temp;
    BinaryTreeNode* root = NULL;


    ifstream in;
    in.open("input.txt");
    if (!in)
    {
        cout<<"Error opening file." <<endl;
    }
    ofstream out;
    out.open("output.txt");
    if (!out)
    {
        cout <<"Failed to open file"<<endl;
    }
    while (in >>temp)
    {
        if (temp == "delete")
        {
            in>>temp;
            root = Delete(root, temp);
        }
        else
            Insert(root, temp);
    }

    ///print preOrder
    preOrder(root, out);
    out <<endl;

    ///print inOrder
    out <<"inOrder: " <<endl;
    inOrder(root, out);
    out <<endl;
    ///print postOrder
    out <<"postOrder: " <<endl;
    postOrder(root, out);
    out <<endl;
    ///display tree level by level
    out<<"Print Level: " <<endl;
    printLevel(root, out);
    out << endl;
    cout <<"printed to output file" <<endl;

    in.close();
    out.close();


    return 0;
}

void Insert(BinaryTreeNode *& leaf, string item)
{
    if (!leaf)
    {
        leaf = new BinaryTreeNode;
        leaf->left = NULL;
        leaf->right = NULL;
        leaf->value = item;
    }
    else if (leaf->value < item)
    {
        Insert(leaf->right, item);
    }
    else if (leaf->value > item)
    {
        Insert (leaf->left, item);
    }
    else
    {
        cout <<"Error inserting"<<endl;
    }
}

BinaryTreeNode* Delete(BinaryTreeNode *& leaf, string item)
{
    BinaryTreeNode* temp = NULL;
    ///search for node to delete
    if (leaf)
    {
        if (item == leaf->value)
            {
                ///node has no children
                if (!(leaf->left || leaf->right))
                {
                    delete leaf;
                    return NULL;
                }
                else if (leaf->left && leaf->right)
                {
                ///node has two children
                    temp = leaf->left;
                    ///traverse to the left then to the rightmost node and copy
                    while (temp->right)
                        temp = temp->right;
                    ///take the copied node and replace the "to be deleted node"
                    leaf->value = temp->value;
                    ///delete the copied node
                    delete temp;
                    return leaf; ///check this
                }
                ///node has one child
                else
                {
                    if (leaf->right)
                    {
                       temp = leaf->right;
                       delete leaf;
                       return temp;
                    }
                    else
                    {
                        temp = leaf->left;
                        delete leaf;
                        return temp;
                    }
                }
            }
        else if (item < leaf->value)
        {
            leaf->left = Delete(leaf->left, item);
        }
        else if (item > leaf->value)
        {
            leaf->right = Delete(leaf->right, item);
        }
        else
            cout <<item <<" not in tree"<<endl;
        return leaf;
    }
    else
    {
        cout <<"Not found"<<endl;
        return leaf;
    }
}

void preOrder(BinaryTreeNode* root, ofstream& out)
{
    if(root)
    {
        out<<root->value<<" ";
        preOrder(root->left, out);
        preOrder(root->right, out);
    }
}

void inOrder(BinaryTreeNode* root, ofstream& out)
{
    if(root)
    {
        inOrder(root->left, out);
        out<<root->value<<" ";
        inOrder(root->right, out);
    }
}

void postOrder(BinaryTreeNode* root, ofstream& out)
{
    if(root)
    {
        postOrder(root->left, out);
        postOrder(root->right, out);
        out<<root->value<<" ";
    }
}

void printLevel(BinaryTreeNode* root, ofstream& out)
{
    queue curr;
    queue next;
    BinaryTreeNode* temp = NULL;
    ///enqueue root on curr
    enqueue(curr, root);
    ///while (curr)
    while (curr.front)
    {
        ///cout <<dequeue curr
        temp = dequeue(curr);
        out <<temp->value <<" ";
        ///enqueue left next
        if (temp->left)
            enqueue(next, temp->left);
        ///enqueue right next
        if (temp->right)
            enqueue(next, temp->right);
        ///if (!curr)
        if (!curr.front)
        {
            ///curr = next
            curr = next;
            ///next = NULL
            next.front= next.rear= NULL;
            out<<endl;

        }
    }
}

void enqueue(queue &queue, BinaryTreeNode *leaf)
{
    node* nn = new node;
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
BinaryTreeNode *dequeue(queue &queue)
{
    BinaryTreeNode* temp = NULL;
    if (queue.front)
    {
        temp = queue.front->leaf;
        node* frTemp = queue.front;
        queue.front = queue.front->next;
        delete frTemp;
        if (!(queue.front))
        {
            queue.front = queue.rear = NULL;
        }
    }
    return temp;
}
