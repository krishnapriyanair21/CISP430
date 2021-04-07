#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int SIZE = 10;

void siftUp(int nodeIndex, int* a);
void siftDown(int parent, int* a);
void deleteFront (int* a);
void displayLevel(int* a, int num = 1, int index = 0, int indent = SIZE);

int main()
{
    int temp = 0;
    int j = 0;
    int a[SIZE] = {0};
    ifstream in;
    in.open("input.txt");
    if (!in)
    {
        cout <<"error opening file"<<endl;
    }
    ///insert + sift up
    while (in >> temp)
    {
        a[j] = temp;
        siftUp(j, a);
        j++;
    }

    ///display by level
    cout <<"display array by level \n";
    displayLevel(a);
    cout <<endl;
    ///delete 5 items + sift down
        ///display after each delete by level
    for (int i = 0; i < 5; i ++)
    {
        cout <<"deleting " <<a[0]<<endl;
        cout <<"------------------------" <<endl;
        deleteFront(a);
        siftDown(0, a);
        displayLevel(a);
        cout <<endl;
    }

    in.close();
    return 0;
}
void siftUp(int nodeIndex, int* a)
{
    if (nodeIndex != 0)
    {
        int parent = (nodeIndex - 1) / 2;
        if (a[parent] > a[nodeIndex])
        {
            swap(a[parent], a[nodeIndex]);
            siftUp(parent, a);
        }
    }
}
void siftDown(int parent, int* a)
{
    int left = (2 * parent) + 1;
    int right = (2 * parent) + 2;
    int maxIndex = parent;
    if (left <= SIZE)
   {
       if (left == SIZE)
            maxIndex = left;
        else
        {
            if (a[left] > a[right])
                maxIndex = right;
            else
                maxIndex = left;
        }
        if (a[parent] > a[maxIndex])
        {
            swap(a[parent], a[maxIndex]);
            siftDown(maxIndex, a);
        }
   }

}
void deleteFront (int* a)
{
    SIZE--; ///reduce size of array
    a[0] = a[SIZE]; ///first index gets last element
}

void displayLevel(int* a, int num, int index, int indent)
{
    for (int i = 0; i < num; i++)
    {
        if (index < SIZE) ///checking if out of bounds
        {
            cout <<string(indent, ' ')<< a[index++] <<" ";
        }
    }
    cout <<endl;
    if (index < SIZE) ///if there is more in the array
        displayLevel(a, num * 2, index, indent/2); ///next is 2x nums, same index in a
    else
        return;
}
