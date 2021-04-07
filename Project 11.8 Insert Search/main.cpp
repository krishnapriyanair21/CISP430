#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node
{
    string ListName;
    Node* next = NULL;
};

struct BinaryTreeNode
{
    string name;
    Node* head = NULL;
    BinaryTreeNode* left = NULL;
    BinaryTreeNode* right = NULL;
};

void Insert(BinaryTreeNode *& leaf, string item);
void InsertNode(BinaryTreeNode *& leaf, string item);
int Search(BinaryTreeNode* leaf, string item);
int main()
{
    BinaryTreeNode* root = NULL;
    string temp;
    int x = -5;
    ifstream in;
    in.open("input.txt");
    if (!in)
    {
        cout <<"Error opening file"<<endl;
    }
    while (in >>temp)
    {
        Insert(root, temp);
    }
    cout<<"List complete"<<endl;
    cout <<"Searching for: ";
    cin >>temp;
    x = Search(root, temp);
    if (x == 1)
    {
        cout <<temp << " is in the list" <<endl;
    }
    else if (x == 0)
    {
        cout <<temp<< " is not in the list" <<endl;
    }
    else
    {
        cout <<"There are " <<x <<" "<<temp <<"'s in the list" <<endl;
    }
}

void Insert(BinaryTreeNode *& leaf, string item)
{
    if (!leaf)
    {
        leaf = new BinaryTreeNode;
        leaf->left = NULL;
        leaf->right = NULL;
        leaf->name = item;
    }
    else if (leaf->name > item)
    {
        Insert(leaf->right, item);
    }
    else if (leaf->name < item)
    {
        Insert (leaf->left, item);
    }
    else
    {
        if (item ==leaf->name)
            InsertNode(leaf, item);
    }
}
void InsertNode(BinaryTreeNode *& leaf, string item)
{
    Node* nn = new Node;
    nn->next = leaf->head;
    nn->ListName = item;
    leaf->head = nn;

}

int Search(BinaryTreeNode* leaf, string item)
{
    bool found = false;
    Node* curr = NULL;
    int num = 0;
    while (leaf && !found)
    {
        if (item == leaf->name){
            cout <<"Searched: " <<leaf->name<<endl;
            found = true;
            if (leaf->head != NULL)
            {
                curr = leaf->head;
                num++;
                while(curr)
                {
                    num++;
                    curr = curr->next;
                }
                return num;
            }
        }
        else if (item > leaf->name)
        {
            cout <<"Searched: " <<leaf->name<<endl;
            leaf = leaf->left;
        }
        else if (item < leaf->name)
        {
            cout <<"Searched: " <<leaf->name<<endl;
            leaf = leaf->right;
        }
    }
    if (found)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
