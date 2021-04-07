#include <iostream>
#include <fstream>

using namespace std;


void stringCopy(char *A, char *B);
bool stringCompare(char *A, char *B);
void stringConcatenation (char *A, char *B);
int stringPosition(char *A, char B);
int stringLength(char *A);


int main()
{
    ifstream in;
    in.open("input.txt");
    if (!in)
    {
        cout <<"Error opening file" <<endl;
    }

    char a[20],b[20];
    char c;
	in>>a>>b;
	cout << "pre stringCopy: " << a <<endl;
	stringCopy(a,b);
	cout << "post stringCopy: " << a <<endl<<endl;


	in>>a>>b;
	if (stringCompare(a,b))
        cout <<"String compare: " << a <<" " << b <<" are the same." <<endl;
    else
        cout <<"String compare: " << a <<" and " << b <<" are not the same." <<endl;
    cout<<endl;

    in>>a>>b;
    cout <<"String a = " << a << " String b = " << b <<endl;
    stringConcatenation (a,b);
    cout<< "String Concatenation: String a = " << a << " String b = " << b << endl;
    cout<<endl;

    in>>a>>c;
    cout <<"word = " <<a<< " letter= " <<c<<endl;
    int j = stringPosition(a,c);
    if (j != -1)
        cout <<c<< " appears at the " <<j << " index in " <<a<<endl;
    else
        cout<<c << " doesn't appear in " <<a<<endl;
    cout<<endl;

    in>>a;
    cout <<"Before String Length: " <<a<<endl;
    cout <<"string Length is: " <<stringLength(a) <<endl;
    cout <<"After String Length: "<<a<<endl;
    ///the rest of the reads and function calls
	in.close();


    return 0;
}

void stringCopy(char *A, char *B)
{
    int i = 0;
    while (B[i] != NULL)
    {
        A[i] = B[i];
        i++;
    }
    while (A[i] != NULL)
    {
        A[i] = NULL;
        i++;
    }

}
bool stringCompare(char *A, char *B)
{
    int i = 0;
    while (A[i] != NULL)
    {
        while (B[i] != NULL)
        {
            if (A[i] != B[i])
                return false;
            else
                i++;
        }
    }
    if (B[i] != NULL)
        return false;
    else
        return true;
}
void stringConcatenation (char *A, char *B)
{
    int i = 0;
    while (A[i] != NULL)
    {
        i++;
    }
    int j = 0;
    while (B[j] != NULL)
    {
        A[i] = B[j];
        i++;
        j++;
    }
}
int stringPosition(char *A, char B)
{
    int i = 0;
    while (A[i] != NULL)
    {
        i++;

    }
    for (int j = 0; j < i + 1; j++)
    {
        if (A[j] == B)
            return j;
    }
    return -1;
}
int stringLength(char *A)
{
    int i =0;
    while (A[i] != NULL)
    {
        i++;
    }
    char aCopy[i];

    for (int j = 0; j < i; j++)
    {
        aCopy[j] = A[j];
        cout <<aCopy[j];
    }
    for (int j = 0; j < (i+1); j++)
    {
        A[j+1] = aCopy[j];
    }

    A[0] = i + '0';
    return i;
}
