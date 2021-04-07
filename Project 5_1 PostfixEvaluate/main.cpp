#include <iostream>
#include <fstream>


using namespace std;

struct node
{
    int value;
    node* next;
};

void push (node*& head, int value);
int pop(node*& head);

int main()
{
    char a[20];
    ifstream in;
    int i = 0;
    int tempA = 0;
    int tempB = 0;
    int result;

    node* head = new node;
    head->next = '\0';
    head->value = '\0';

    in.open("input.txt");
    if(!in)
    {
        cout<< "Error opening file" <<endl;
    }
    while(in>>a[i])
    {
        switch(a[i])
        {
            case '+':
                tempA = pop(head);
                tempB = pop(head);
                result = tempB + tempA;
                push(head,result);
                break;
            case '-':
                tempA = pop(head);
                tempB = pop(head);
                result = tempB - tempA;
                push(head,result);
                break;
            case '*':
                tempA = pop(head);
                tempB = pop(head);
                result = tempB * tempA ;
                push(head,result);
                break;
            case '/':
                tempA = pop(head);
                tempB = pop(head);
                result = (tempB / tempA);
                push(head,result);
                break;
            default:
                push(head, a[i] - '0');
                break;
        }
        i++;
    }
    cout<<"Your answer is: " <<head->value<<endl;
}


void push (node*& head, int value)
{
    node* nn = new node;
    nn->value = value;
    nn->next = head;
    head = nn;
}


int pop(node*& head)
{
    node* temp;
    int temp1 = -20;
    if (head)
    {
        temp= head;
        head = head->next;
        temp1 = temp->value;
        delete temp;
    }
    return temp1;
}
