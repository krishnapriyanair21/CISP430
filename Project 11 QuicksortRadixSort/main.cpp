#include <iostream>
#include <fstream>

using namespace std;
int SIZE = 5;

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

void quickSort (int a[], int start, int end);
int partition (int a[], int first, int last);
void swap(int &a, int &b);
void addFive(int a[]);
void enqueue (queue &que, int value);
int dequeue (queue &que);
void radix(int a[]);
void display(int a[]);

int main()
{
    int a[SIZE] = {0};
    int i = 0;

    ifstream in;
    in.open("input.txt");
    if(!in)
    {
        cout <<"Error opening file" <<endl;
    }
    while (in)
    {
        in >> a[i];
        i++;
    }
    cout <<"arrary is: "<<endl;
    display(a);

    quickSort(a, 0, SIZE - 1);
    cout <<"after quick sort..."<<endl;
    display(a);

    addFive(a);
    radix(a);
    cout <<"after radix sort..."<<endl;
    display(a);

}

void quickSort (int a[], int start, int end)
{
    int pIndex = -1;

    if (start >= end)
        return;

    pIndex = partition(a, start, end);
    quickSort(a, start, pIndex - 1);
    quickSort(a,pIndex + 1 , end);
}
int partition (int a[], int first, int last)
{
    int pivot = last;
    int upper = last - 1;
    int lower = first;

    while (lower <= upper)
    {
        while (a[pivot] <= a[lower] && lower <= upper)
        {
            lower++;
        }
        if (upper < lower)
            break;

        swap (a[pivot], a[lower]);
        pivot = lower;
        lower ++;

        while (a[pivot] >= a[upper] && lower <= upper)
        {
            upper--;
        }
        if (upper < lower)
            break;

        swap(a[pivot], a[upper]);
        pivot = upper;
        upper--;
    }
    return pivot;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void addFive(int a[])
{
    int temp = 0;
    int tempDig = 0;
    int i = 0;

    temp = a[0];
    while (temp > 0)
    {
        temp /= 10;
        i++; ///i is how many digits are in the first number
    }

    for (int j = 1; j < SIZE; j++)
    {
        temp = a[j];
        tempDig = 0;
        while (temp > 0)
        {
            temp /= 10;
            tempDig++;
        }
        while (tempDig != i)
        {
            a[j] = a[j] * 10 + 5;
            tempDig++;
        }
    }

    cout <<"array after adding fives..." <<endl;
    display(a);
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

void radix(int a[])
{
    int MAX = a[0];
    int temp = 0;
    int i = 0;
    int b = 1, c = 10;
    queue q[10];

    while (b <= MAX)
    {
        for (i = 0; i< SIZE; i++)
        {
            temp = (a[i] % c ) / b;
            enqueue(q[temp], a[i]);
        }
        int j = 0;
        for (i = 0; i < 10; i++)
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
}

void display(int a[])
{
    int i = 0;
    for (i = 0; i < SIZE; i++)
    {
        cout << a[i] << " ";
    }
    cout <<endl;
}
