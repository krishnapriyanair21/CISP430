#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int SIZE  = 10;

struct BinaryTreeNode
{
    int data = 0;
    BinaryTreeNode* right = '\0';
    BinaryTreeNode* left = '\0';
};

void displayArray(int* a);
BinaryTreeNode* SortArrToBST (int* a, int start, int end);
void inOrder(BinaryTreeNode* root);
void BSTToUnsortArr (BinaryTreeNode* root, int i, int* a);
int findHeight(BinaryTreeNode* n);
BinaryTreeNode* UnsortArrToBST(int index, int* a);

int main()
{
    int a[SIZE];
    int temp = 0;
    ifstream in;
    in.open("input.txt");
    if (!in)
    {
        cout <<"error opening file"<<endl;
    }

    ///place in sorted array
    int j = 0;
    while (in >> temp && temp != 0)
    {
        a[j++] = temp;
    }
    ///change size passed on input data
    SIZE = j;

    cout <<"Sorted Array: " <<endl;
    displayArray(a);

    ///SA->BST
    BinaryTreeNode* root = SortArrToBST(a, 0, SIZE - 1);

    ///display BST
    cout <<"BST inOrder: " <<endl;
    inOrder(root);
    cout <<endl;

    ///find height of tree
    int height = findHeight(root);
    ///create new array with size (2^height+1) - 1
    SIZE = (pow (2, height + 1)) - 1;
    int arr[SIZE];

    ///BST -> UA
    BSTToUnsortArr(root, 0, arr);

    ///display unsorted array
    cout <<"Unsorted Array (-999 = no value present): " <<endl;
    displayArray(arr);

    ///UA -> BST
    root = UnsortArrToBST(0, arr);

    ///display BST
    cout <<"BST inOrder: " <<endl;
    inOrder(root);
}

void displayArray(int* a)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << a[i] <<" ";
    }
    cout <<endl;
}
BinaryTreeNode* SortArrToBST (int* a, int start, int end)
{
    int mid = (start + end) / 2;
    if (start > end) {
        return NULL;
    }
    else{
        BinaryTreeNode* root = new BinaryTreeNode;
        root->data = a[mid];
        root->left = SortArrToBST(a, start, mid - 1);
        root->right = SortArrToBST(a, mid + 1, end);
        return root;
    }
}
void BSTToUnsortArr (BinaryTreeNode* root, int i, int* a)
{
    if (root)
    {
        a[i] = root->data;
        BSTToUnsortArr(root->left, (2 * i) + 1, a);
        BSTToUnsortArr(root->right, (2 * i) + 2, a);
    }
    else
    {
        a[i] = -999;
    }
}
int findHeight(BinaryTreeNode* n)
{
    if (!n)
    {
        return -1;
    }
    else{
        int L = findHeight(n->left);
        int R = findHeight(n->right);
        if (L > R)
            return (L + 1);
        else
            return (R + 1);
    }
}
BinaryTreeNode* UnsortArrToBST(int index, int* a)
{
    if (a[index] != -999)
    {
        BinaryTreeNode* nn = new BinaryTreeNode;
        nn->data = a[index];
        if (((index * 2) + 2 ) < SIZE)
        {
            nn->left = UnsortArrToBST(((index * 2) + 1), a);
            nn->right = UnsortArrToBST(((index * 2) + 2), a);
        }
        return nn;
    }
    else
    {
        return '\0';
    }
}
void inOrder(BinaryTreeNode* root)
{
    if(root)
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
