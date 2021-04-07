#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct node
{
    string name;
    node* next;
    node* prev;

};

void traverse(node*& head);
void deleteNode(node*& head, int deleteNum);

int main()
{
    int deleteNum;
    ifstream in;
    in.open("input.txt");
    if (!in)
    {
        cout<<"Error opening file" <<endl;
    }

    string inName;
    node* head = new node;
    head->next = head->prev = '\0';


    while (getline(in,inName))
    {
        node* nn = new node;
        nn->name = inName;
        if (!(head->next))
        {
            nn->next = nn->prev = nn;
            head = nn;
        }
        else
        {
            nn->prev = head;
            nn->next = head->next;
            head->next = nn;
            nn->next->prev = nn;
        }
    }

    traverse(head);

    cout <<"Enter the number of nodes you wish to delete: " ;
    cin >> deleteNum;

    deleteNode(head,deleteNum);
    traverse(head);
}

void traverse(node*& head)
{
    cout<<"traversing..."<<endl;
    int i = 1;

    if (head)
    {
        node* temp = new node;
        temp = head;

        ///first round
        cout<< i++<<": "<<temp->name<<endl;
        temp = temp->next;

        while (temp != head)
        {
            cout<< i++<<": "<<temp->name<<endl;
            temp = temp->next;
        }
    }
    else
    {
        cout<<"empty list in traverse" <<endl;
    }
}

void deleteNode(node*& head, int deleteNum)
{
    node* temp= new node;
    temp = head;
    cout<<"deleting..."<<endl;

    do
    {
        temp = head;
        if (((head->next) == temp) && ((head->prev) == temp))
        {
            head= head->next = head->prev = '\0';
            deleteNum = 0;
        }
        else
        {
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
            delete temp;
            deleteNum--;
        }
    } while(deleteNum > 0);

}
