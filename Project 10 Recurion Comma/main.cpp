#include <iostream>

using namespace std;

int comma(int value);
int main()
{
    int value = 0;
    cout <<"What is your value?"<<endl;
    cin >>value;
    cout <<"separated: ";
    comma(value);
}
int comma(int value)
{
    int temp = 0;
    if (value < 1000){
        cout <<value;
        return value;
    }
    else{
        comma((value - (value%1000))/1000);
        if ((value % 1000) == 0)
           cout <<",00" <<value %1000;
        else if ((value % 1000) < 100)
           cout <<",0" <<value %1000;
        else
            cout <<","<<value % 1000;
        return value;
    }
}
