#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct node
{
    char op;
    node* next;
};

void push (node*& head, char op);
char pop (node*& head);
int precedence (node*& head, char a);
void enqueue (node*& front, node*& rear, char value);
char dequeue (node*& front, node*& rear);

int main()
{
    char a[20];
    int i = 0;

    node *head = new node;
    head->op = '\0';
    head->next = '\0';

    node *front = new node;
    front->op = '\0';
    front->next = '\0';

    node *rear = new node;
    rear->op = '\0';
    rear->next = '\0';

    ifstream in;
    in.open("input.txt");
    if (!in)
    {
        cout <<"Error opening file" <<endl;
    }
    cout<<"Infix: ";
    while (in>>a[i])
    {
        cout <<a[i];
        if (isdigit(a[i]))
        {
            enqueue(front, rear, a[i]);
        }
        else if (!(head->op))
        {
            push(head,a[i]);
        }
        else if (a[i] == '(')
        {
            push(head, a[i]);
        }
        else if (a[i] == ')')
        {
            while (head->op != '(')
            {
                enqueue(front, rear, pop(head));
            }
            pop(head);
        }
        else
        {
            while (precedence(head,a[i]) <= precedence(head, head->op))
            {
                if (head->op == '\0')
                    break;
                enqueue(front, rear,pop(head));
            }
            if (precedence(head,a[i] > precedence(head, head->op)))  ///does not work lol
            {
                push(head, a[i]);
            }
        }
        i++;
    }
    while(head->op != '\0')
    {
        enqueue(front, rear, pop(head));
    }

    cout<<endl<<endl<<"Postfix: ";
    do
    {
        dequeue(front, rear);
    }while(front!=rear);
    dequeue(front, rear);
    cout<<endl;
}

void push (node*& head, char op)
{
    node *nn = new node;
    nn->op = op;
    nn->next = head;
    head =nn;
}


char pop (node*& head)
{
    node* temp1;
    char tempOp = '!';
    if (head){
        temp1 = head;
        head = head->next;
        tempOp = temp1->op;
        delete temp1;
    }
    return tempOp;
}


int precedence(node*& head, char a)
{
   switch (a)
   {
        case '(':
            return 1;
            break;
        case '+':
        case '-':
            return 2;
            break;
        case '*':
        case '/':
            return 3;
            break;
        case '^':
            return 4;
            break;
        default:
            return 10;
   }
}

void enqueue (node*& front, node*& rear, char value)
{
    node* nn = new node;
    nn->op = value;
    nn->next = '\0';
    if (!(front->op))
    {
        front = rear = nn;
    }
    else
    {
        rear->next = nn;
        rear = nn;
    }
}

char dequeue (node*& front, node*& rear)
{
    node* temp;
    char temp1;
    if (front)
    {
        temp = front;
        front = front->next;
        temp1 = temp->op;
        delete temp;
        if (!front)
        {
            rear = front;
        }
        cout<<temp1;
        return temp1;
    }
    return 15;
}
