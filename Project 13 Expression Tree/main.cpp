#include <iostream>
#include <fstream>

using namespace std;

struct tree
{
    char item;
    tree* left;
    tree* right;
};

struct node
{
    tree* leaf;
    node* next;
};
void push (node*& head, tree* leaf);
tree* pop(node*& head);
int postOrder(tree* BinTree);
void inOrder (tree* BinTree, bool root = true);
int main()
{
    node* TreeStack = NULL;
    char item;

    ifstream in;
    in.open("input.txt");
    if (!in)
    {
        cout <<"error opening file"<<endl;
    }
    while (in >> item)
    {
        tree* temp = new tree;
        temp->item = item;
        if (isdigit(item))
            temp->left = temp->right = NULL;
        else
        {
            tree* popRight = pop(TreeStack);
            tree* popLeft = pop(TreeStack);
            temp->left = popLeft;
            temp->right = popRight;
        }
        push(TreeStack, temp);
    }
    tree* BinaryTree = pop(TreeStack);
    cout <<"Infix Notation: ";
    inOrder(BinaryTree);
    cout <<"\nPostOrder Evaluation: " <<postOrder(BinaryTree)<<endl;
    return 0;
}
void push (node*& head, tree* leaf)
{
    node* nn = new node;
    nn->leaf = leaf;
    if (head)
        nn->next = head;
    else
        nn->next = NULL;
    head = nn;
}

tree* pop(node*& head)
{
    tree* temp = NULL;
    node* temp1 = NULL;
    if (head)
    {
        temp = head->leaf;
        temp1 = head;
        head = head->next;
        delete temp1;
    }
    return temp;

}

int postOrder(tree* BinTree)
{
    if (BinTree)
    {
        int left = postOrder(BinTree->left);
        int right = postOrder(BinTree->right);
        if (!isdigit(BinTree->item))
        {
            switch (BinTree->item) {
                case '^':
                    return left ^ right;
                    break;
                case '/':
                    return left / right;
                    break;
                case '*':
                    return left * right;
                    break;
                case '+':
                    return left + right;
                    break;
                case '-':
                    return left - right;
                    break;
                default:
                    return -1;
            }
        }
        else
            return BinTree->item - '0';
    }
    else
        return 0;
}
void inOrder (tree* BinTree, bool root)
{
    if (BinTree)
    {
        if (BinTree->left && !root)
        {
            cout << "(";
        }
        inOrder(BinTree->left, false);
        cout <<BinTree->item;
        inOrder(BinTree->right, false);
        if (BinTree->right && !root) {
            cout << ")";
        }
    }
}
