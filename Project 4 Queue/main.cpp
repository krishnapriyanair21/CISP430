#include <iostream>
#include <fstream>

using namespace std;


struct node
{
    int value;
    node* next;
};

void enqueue (node*& front, node*& rear, int value);
int dequeue (node*& front, node*& rear);
void traverse(node* front);

int main()
{
    int value = 0;
    node* front = '\0';
    node* rear = '\0';
    int temp = 0;
    ifstream in;
    in.open("input.txt");
    if (!in)
    {
        cout <<"Error opening file" <<endl;
    }
    while (in >> value)
    {
        enqueue(front, rear, value);
    }
    cout <<"All data entered" <<endl;
    traverse(front);
    node *staticRear = rear;
    do
    {
        temp = dequeue(front, rear);
        if (temp > 0)
        {
            enqueue(front, rear, temp);
        }
    }while (front != staticRear);
    temp = dequeue(front, rear);
        if (temp > 0)
        {
            enqueue(front, rear, temp);
        }
    traverse(front);
}

void enqueue (node*& front, node*& rear, int value)
{
    node* nn = new node;
    nn->value = value;
    nn->next = '\0';
    if (!front)
    {
        front = rear = nn;
    }
    else
    {
        rear->next = nn;
        rear = nn;
    }
}

int dequeue (node*& front, node*& rear)
{
    node* temp;
    int temp1;
    if (front)
    {
        temp = front;
        front = front->next;
        temp1 = temp->value;
        delete temp;
        if (!front)
        {
            rear = front;
        }
        return temp1;
    }
    return 15;
}

void traverse(node* front)
{
    cout <<"Traversing...: ";
    while (front)
    {
        cout <<front->value <<" ";
        front = front->next;
    }
    cout<<endl;
}

