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

int main()
{
    ifstream in;
    in.open("input.txt");
    if (!in)
    {
        cout<<"Error opening file" <<endl;
    }

    string inName;
    node* head = new node;
    head->name = '\0';
    node* tail = new node;
    tail->name = '\0';

    while (getline(in,inName))
    {
        if (!(head->name))
        {
            node* nn = new node;
            nn->name = inName;
            nn->next  = '\0';
            nn->prev = '\0';
            head = tail = nn;
        }
        else if (inName == "delete")
        {
            ///delete node
        }
        else
        {
            node* nn = new node;
            nn->name = inName;
            if ((nn->name).length < (head->name).length)
            {
                ///insert first
            }
            else if ((nn->name).length > (tail->name).length)
            {
                ///insert last
            }
        }
    }
}
