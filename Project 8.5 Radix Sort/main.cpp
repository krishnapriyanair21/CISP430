#include <iostream>

using namespace std;

int SIZE = 10;

struct node
{
    int value;
    node* next;
};

struct queue
{
    node* frnt = '\0';
    node* rear = '\0';
};

void enqueue (queue &que, int value);
int dequeue (queue &que);
void reverse(int a[]);

int main()
{
    int a[SIZE] = {29, 35, 7, 59, 750, 290, 57, 23, 77, 98};
    queue q[SIZE];
    int MAX = -1;
    int b = 1, c = 10;
    int temp;
    int j = 0;


    ///find max
    for (int i = 0; i < SIZE; i++)
    {
        if (a[i] > MAX)
            MAX = a[i];
    }

    ///find max digits
    cout<<"Max is " <<MAX <<endl;

    cout<<"Before"<<endl;
    for (int i = 0; i< SIZE; i++)
    {
        cout<<a[i] <<" ";
    }
    cout<<endl;
    while (b <= MAX)
    {
        for (int i = 0; i< SIZE; i++)
        {
            temp = (a[i] % c ) / b;
            enqueue(q[temp], a[i]);
        }
        j = 0;
        for (int i = 0; i < SIZE; i++)
        {
            while (q[i].frnt)
            {
                a[j] = dequeue(q[i]);
                j++;
            }
        }
        b *= 10;
        c *= 10;
    }
    cout<<"Ascending Order"<<endl;
    for (int i = 0; i< SIZE; i++)
    {
        cout<<a[i] <<" ";
    }
    cout<<endl;

    cout <<"Descending Order" <<endl;
    reverse(a);
}

void enqueue (queue &que, int value)
{
    node* nn = new node;
    nn->value = value;
    nn->next = '\0';
    if (que.rear)
    {
        que.rear->next = nn;
        que.rear = nn;
    }
    else
    {
        que.frnt = que.rear = nn;
    }
}

int dequeue (queue &que)
{
    node* temp;
    int temp1;
    if (que.frnt)
    {
        temp = que.frnt;
        que.frnt = que.frnt->next;
        temp1 = temp->value;
        delete temp;
        if (!que.frnt)
        {
            que.rear = que.frnt;
        }
        return temp1;
    }
    return -1;
}
void reverse(int a[])
{
    int temp[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        temp[i] = a[SIZE - i - 1];
    }

    for (int i = 0; i < SIZE; i++)
    {
        cout << temp[i] << " ";
    }
    cout <<endl;
}
