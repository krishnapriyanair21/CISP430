#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node
{
    string name;
    node* prev;
    node* next;
};

void deleteNode(node*& head, node*& tail, string name);

int main()
{
    ifstream in;
    in.open("input.txt");
    if (!in)
    {
        cout<<"Error opening file" <<endl;
    }

    ofstream out;
    out.open("output.txt");
    if (!out)
    {
        cout <<"Error opening output"<<endl;
    }
    string inName;
    node* head = '\0';
    node* tail = '\0';

    while (in>>inName)
    {
        if (!head)
        {
            node* nn = new node;
            nn->name = inName;
            nn->next  = '\0';
            nn->prev = '\0';
            head = tail = nn;
        }
        else if (inName == "delete")
        {
            in>>inName;
            deleteNode(head, tail, inName);
        }
        else
        {
            node* nn = new node;
            nn->name = inName;
            if ((nn->name) < (head->name))
            {
                nn->next = head;
                nn->prev = '\0';
                head->prev = nn;
                head = nn;
            }
            else if ((nn->name) > (tail->name))
            {
                nn->next= '\0';
                nn->prev = tail;
                tail->next = nn;
                tail = nn;
            }
            else
            {
                node* temp = head->next;
                while (nn->name > temp->name)
                {
                    temp = temp->next;
                }
                nn->next = temp;
                nn->prev = temp->prev;
                temp->prev->next = nn;
                temp->prev = nn;
            }
        }
    }
    node* temp = head;
    while (temp!= tail)
    {
        out << temp->name <<endl;
        temp = temp->next;
    }
    out << tail->name <<endl;
    out <<"======================" <<endl;

    temp = tail;
    while (temp != head)
    {
        out << temp->name<<endl;
        temp = temp->prev;
    }
    out << head->name<<endl;
}

void deleteNode(node*& head, node*& tail,string name)
{
    node* temp = new node;
    temp = head;
    bool found = false;

    while (temp && !found)
    {
        if (temp->name == name)
        {
            found = true;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (found)
    {
        if(temp->prev)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            head = temp->next;
        }
        if(temp->next)
        {
            temp->next->prev = temp->prev;
        }
        else
        {
            tail = temp->prev;
        }
        delete temp;
    }
}
