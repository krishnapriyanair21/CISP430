#include <iostream>

using namespace std;

int SIZE = 5;

int main()
{
    int a[SIZE] = {365, 89, 56, 43, 2};
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
        cout <<"a[j] before: " << a[j] <<endl;
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
        cout <<"a[j] after: " << a[j] <<endl;
    }

    cout <<"array after adding..." <<endl;
    for (i = 0; i < SIZE; i++)
    {
        cout << a[i] << " ";
    }
    cout <<endl;
}
