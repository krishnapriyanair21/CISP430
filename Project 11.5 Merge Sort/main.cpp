#include <iostream>

using namespace std;

int SIZE = 11;
struct node
{
    int value;
    node* next;
};
struct queue
{
    node* front = '\0';
    node* rear = '\0';
};
void split (queue& nums,queue& a,queue&b);
queue merge(queue a, queue b);
queue mergeSort(queue & nums);
void enqueue (queue & nums, int value);
int dequeue (queue &que);


int main()
{
    queue nums;
    int a[SIZE] = {2, 89, 6, 29, 5, 6, 57, 22, 9, 44, 3};
    for (int i = 0; i < SIZE; i++)
    {
        enqueue(nums, a[i]);
    }
    node* curr = nums.front;
    cout <<"before sorting..."<<endl;
    while (curr)
    {
        cout <<curr->value<<" ";
        curr = curr->next;
    }
    cout <<endl;

    nums = mergeSort(nums);

    curr = nums.front;
    cout <<"after sorting..."<<endl;
    while (curr)
    {
        cout <<curr->value<<" ";
        curr = curr->next;
    }

}


queue mergeSort(queue& nums)
{
    if (!(nums.front) ||!(nums.front->next))
    {
        return nums;
    }

    queue a;
    queue b;
    queue c;
    split (nums,a,b);

    a = mergeSort(a);
    b = mergeSort(b);
    c = merge(a,b);

    return c;
}

queue merge(queue a, queue b)
{
    queue nums;
    while (a.front && b.front)
    {
        if (a.front->value < b.front->value)
        {
            enqueue(nums,dequeue(a));
        }
        else
        {
            enqueue(nums, dequeue(b));
        }
    }
    while (a.front)
    {
        enqueue(nums, dequeue(a));
    }
    while (b.front)
    {
        enqueue(nums, dequeue(b));
    }
    return nums;
}

void split (queue& nums,queue& a,queue&b)
{
    node* temp = nums.front;
    int num = 0;
    if (nums.front)
    {
        while (temp)
        {
            temp = temp->next;
            num++;
        }

        for (int i = 0; i< num/2; i++)
        {
            enqueue(a,dequeue(nums));
        }
        while (nums.front)
        {
            enqueue(b, dequeue(nums));
        }
    }
}

void enqueue (queue& que, int value)
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
        que.front = que.rear = nn;
    }
}

int dequeue (queue &que)
{
    node* temp;
    int temp1;
    if (que.front)
    {
        temp = que.front;
        que.front = que.front->next;
        temp1 = temp->value;
        delete temp;
        if (!que.front)
        {
            que.rear = que.front;
        }
        return temp1;
    }
    return -1;
}
