#include <iostream>

using namespace std;

int sum (int x, int num);
int main()
{
    int num = 10;
    int value = 0;
    cout<<"what would you like to add?" <<endl;
    cin>>value;
    cout <<sum (value, num) << " is the sum" <<endl;
    return 0;
}
int sum (int x, int num)
{
    if (num >= x)
        return ((x%num)/(num/10));
    else
        return ((x%num)/(num/10)) + sum(x, num*10);
}
