#include <iostream>

using namespace std;

struct node
{
    int value;
    node* next;
};

void push (node** head, int value);
node *binary(int num);
int pop (node*& head);
void display(node*& head);
node* hexademical(int num);

int main()
{
    int num = 0;
    cout<<"Enter a number: " <<endl;
    cin >> num;
    cout<<endl<<"Your number: " <<num <<endl;

    node *bin = binary(num);
    cout<<"Number in Binary: ";
    display(bin);

    node *hex = hexademical(num);
    cout <<"Number in Hexadecimal: ";
    display(hex);
    cout<<endl;


}

void push (node*& head, int value)
{
    node *nn = new node;
    nn->value = value;
    nn->next = head;
    head =nn;
}

node *binary(int num)
{
    node *stacks = nullptr;
    do
    {
        push(stacks, num%2);
        num = num/2;
    } while(num != 0);
    return stacks;
}
int pop (node*& head)
{
    node* temp1;
    int value = -1;
    if (head){
        temp1 = head;
        head = head->next;
        value = temp1->value;
        delete temp1;
    }
    return value;
}

void display(node*& head)
{
    int value = -1;
    while(head)
    {
        value = pop(head);
        switch(value)
        {
        case 10:
            cout <<'A';
            break;
        case 11:
            cout<<'B';
            break;
        case 12:
            cout<<'C';
            break;
        case 13:
            cout<<'D';
            break;
        case 14:
            cout<<'E';
            break;
        case 15:
            cout<<'F';
            break;
        default:
            cout << value;
            break;
        }
    }
    cout<<endl;
}
node* hexademical(int num)
{
    node *stacks = nullptr;
    do
    {
        push(stacks, num%16);
        num = num/16;
    } while(num != 0);
    return stacks;
}

