#include <iostream>
#include <fstream>

using namespace std;


struct list
{
    string currName;
    list* next;
};


list* ReadFile();
void SplitAndReturn(list* Names);
void Traverse(list* Names);
list* Merge(list* NamesA, list* NamesB);
void add (list** head, string name);


int main()
{
    list* head = ReadFile();
    Traverse(head);
    SplitAndReturn(head);
}

list* ReadFile()
{
    list* head = new list;
    string temp;
    ifstream in;
    in.open("input.txt");
    if (!in)
    {
        cout <<"Error opening file" <<endl;
    }
    in >> temp;
    head->currName = temp;
    head->next = '\0';
    while (in >> temp)
    {
        add(&head, temp);
    }
    return head;
}
void Traverse(list* Names)
{
    cout <<"Traversing..." <<endl;
    while (Names)
    {
        cout <<Names->currName <<endl;
        Names = Names->next;
    }
}
void add (list** head, string name)
{
    list *nn = new list;
    nn->currName = name;
    nn->next = *head;
    *head =nn;
}

void SplitAndReturn(list* Names)
{
    list* list1 = new list;
    list* list2 = new list;
    int count = 0;
    list* temp = Names;

    while (temp)
    {
        count++;
        temp = temp->next;
    }

    temp = Names;
    for (int i = 0; i < count/2; i++)
    {
        add(&list1, temp->currName);
        temp = temp->next;
    }
    cout << "list1: ";
    Traverse(list1);

    for (int i = count/2; i < count; i++)
    {
        add(&list2, temp->currName);
        temp = temp->next;
    }
    cout << "list2: ";
    Traverse(list2);

    list* mergedNames = new list;
    mergedNames = Merge(list1, list2);

    cout<<"Merged Names: ";
    Traverse(mergedNames);
}
list* Merge(list* NamesA, list* NamesB)
{
    list* newNames = new list;
    while (NamesA)
    {
        add(&newNames, NamesA->currName);
        NamesA = NamesA->next;
    }
    while(NamesB)
    {
        add(&newNames, NamesB->currName);
        NamesB = NamesB->next;
    }
    return newNames;
}
