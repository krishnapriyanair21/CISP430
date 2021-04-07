#include <iostream>

using namespace std;

int ROWS = 5;
int COLS = 4;

int array[5][4] = {{5,3,2,16},{9,8,10,17},{4,7,11,18},{2,5,9,12},{7,9,4,10}};

void reset();
void display();
void bubble();
void selection();
void shell();
void insertion();
int binSearch(int key);

int main()
{
    int key;
    int index = 0;
    ///original array
    cout<<"Original: " <<endl;
    display();

   ///bubble sort 1st column
    bubble();
    cout <<"First column bubble sorted" <<endl;
    display();
    reset();

    ///selection sort 2nd column
    selection();
    cout<<"Second column selection sorted"<<endl;
    display();
    reset();

    ///shell sort 3rd column
    shell();
    cout <<"Third column shell sorted"<<endl;
    display();
    reset();
    ///insertion sort 5th ROW
    insertion();
    cout<<"Fifth ROW insertion sorted"<<endl;
    display();

    ///binary search fifth row
    cout<<"what number are you searching for in the fifth row?"<<endl;
    cin>>key;
    index = binSearch(key);
    if (index == -1)
    {
        cout<<"better luck next time"<<endl;
    }
    else
    {
        cout <<"FOUND!" <<endl;
        for (int i = 0; i < ROWS; i++)
        {
            cout <<array[i][index]<<endl;
        }

    }
}

void reset()
{
     array[0][0] = 5;
     array[0][1] = 3;
     array[0][2] = 2;
     array[0][3] = 16;
     array[1][0] = 9;
     array[1][1] = 8;
     array[1][2] = 10;
     array[1][3] = 17;
     array[2][0] = 4;
     array[2][1] = 7;
     array[2][2] = 11;
     array[2][3] = 18;
     array[3][0] = 2;
     array[3][1] = 5;
     array[3][2] = 9;
     array[3][3] = 12;
     array[4][0] = 7;
     array[4][1] = 9;
     array[4][2] = 4;
     array[4][3] = 10;
}
void display()
{
    for (int i = 0; i < 5; i++) {
           for (int j = 0; j < 4; j++) {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
}
void bubble()
{
    int temp;
    for (int i = ROWS - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[j][0] > array [j+1][0])
            {
                for (int k = 0; k < COLS; k++)
                {
                    temp = array[j][k];
                    array[j][k] = array[j+1][k];
                    array[j+1][k] = temp;
                }
            }
        }
    }
}

void selection()
{
    int temp;
    for (int i = ROWS - 1; i > 0; i--)
    {
        int smallIndex = 0;
        for (int j = 1; j <= i; j++)
        {
            if (array[j][1] < array[smallIndex][1])
            {
                smallIndex = j;
            }
        }

        if (i != smallIndex)
        {

            for (int k = 0; k < COLS; k++)
                {
                    temp = array[i][k];
                    array[i][k] = array[smallIndex][k];
                    array[smallIndex][k] = temp;
                }
        }
    }
}

void shell()
{
    int temp;
    for (int gap = ROWS/2; gap >= 1 ; gap = gap/2)
    {
        for (int i = gap; i < ROWS; i++)
        {
            for (int j = i; j >= gap && (array[j-gap][2] > array[j][2]); j = j - gap)
            {
                for (int k = 0; k < COLS; k++)
                {
                    temp = array[j][k];
                    array[j][k] = array[j-gap][k];
                    array[j-gap][k]  = temp;
                }
            }
        }
    }
}
void insertion()
{
    int temp;
    for (int i = 1; i < COLS ; i++)
    {
        for (int j = i; j > 0 && array[4][j] < array[4][j-1]; j--)
        {
             for (int k = 0; k < ROWS; k++)
                {
                    temp = array[k][j];
                    array[k][j] = array[k][j-1];
                    array[k][j-1]  = temp;
                }
        }
    }
}

int binSearch(int key)
{
    int high = ROWS - 1;
    int low = 0;
    int mid = 0;
    bool found = false;
    int index = -1;

    while (high >= low && !found)
    {
        mid = (high + low) / 2;

        if (array[4][mid] > key)
            high = mid - 1;
        else if (array[4][mid] < key)
            low = mid + 1;
        else
        {
            found = true;
            index = mid;
        }
    }

    return index;
}
