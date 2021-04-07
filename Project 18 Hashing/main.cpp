#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int SIZE = 10;

bool collision(int index, int* a);
void insertArray(int key, int* a, int index);
int moduloDivision(int key);
int doubleHashing(int key);
int quadraticProbing(int previousIndex, int attempt = 1);
int linearProbing(int previousIndex);
int searchArray(int selectVal, int* a);

void displayArray(int* a);
int main()
{
    int a[SIZE] = {0};
    int temp = 0;
    int selectVal = 0;
    ifstream in;
    in.open("input.txt");
    if (!in){
        cout <<"error opening file"<<endl;
    }

    while (in >> temp)
    {
        int insertIndex = -1;
        int collisionCount = 0;
        int quadAttempt = 1;
        cout <<"inserting: " <<temp<<endl;
        insertIndex =  moduloDivision(temp); ///modulo division
        if (collision(insertIndex, a)) {
            ++collisionCount;
            insertIndex = doubleHashing(temp); ///double hashing
            if (collision(insertIndex, a)){
                ++collisionCount;
                if (collision(insertIndex,a)){ ///only continue if still colliding
                    for (int i = 0; i < 3; i++){ ///quadratic probing 3 times
                        insertIndex = quadraticProbing(insertIndex, quadAttempt);
                        if (collision(insertIndex, a)){
                            ++collisionCount;
                            quadAttempt++;
                        }
                        else
                            break; ///if there isn't a collision stop
                    }
                    if (quadAttempt > 3 && collision(insertIndex,a)){ ///done quadratic probing 3 times and still colliding
                         for (int i = 0; i < SIZE; i++){ ///check entire array
                            if (!((collision(insertIndex, a))))  ///if there isn't a collision stop
                                break;
                            insertIndex = linearProbing(insertIndex); ///linear probing
                            ++collisionCount;
                         }
                    }
                }
            }
        }
        insertArray(temp, a, insertIndex);
        cout <<"Number of collisions: " <<collisionCount<<endl;
    }

    ///displayArray(a);

    ///user choice
    cout <<"What value are you searching for: " ;
    cin >> selectVal;
    temp = searchArray(selectVal, a);

    if (temp > -1)
        cout<<selectVal<<" found at index " <<temp<<endl;
    else
        cout <<"not in array"<<endl;

    in.close();
    return 0;
}
void insertArray(int key, int* a, int index) {
    a[index] = key;
}
bool collision(int index, int* a) {
    if (a[index] == 0) ///all elements of the array are preset to zero
        return false;  ///if the element at index is 0 then it has not been replaced
    else
        return true;
}
int moduloDivision(int key) {
    return (key % SIZE);
}
int doubleHashing(int key){
    int secondHash = (key % SIZE); ///find value from modulo division
    return (secondHash - (key % secondHash));
}
int quadraticProbing(int previousIndex, int attempt){
    int i = pow(attempt, 2); ///attempt should increase by one each time
    return ((previousIndex + i) % SIZE);
}
int linearProbing(int previousIndex){
    int next = previousIndex + 1;
    return (next % SIZE);
}
void displayArray(int* a){
    for(int i = 0; i < SIZE; i++)
    {
        cout <<i <<": " <<a[i]<<endl;
    }
}
int searchArray(int selectVal, int* a)
{
    int index = -1;
    int quadAttempt = 1;
    cout <<"searching: " <<selectVal<<endl;
    index =  moduloDivision(selectVal); ///modulo division
    if (a[index] != selectVal) {
        index = doubleHashing(selectVal); ///double hashing
        if (a[index] != selectVal){
            for (int i = 0; i < 3; i++){ ///quadratic probing 3 times
                index = quadraticProbing(index, quadAttempt);
                if (a[index] != selectVal){
                    quadAttempt++;
                }
                else
                    break; ///if found stop
            }
            if (quadAttempt > 3 && (a[index] != selectVal)){ ///done quadratic probing 3 times and still not found
                 for (int i = 0; i < SIZE; i++){ ///check entire array
                    if (a[index] == selectVal)  ///if found stop
                        break;
                    index = linearProbing(index); ///linear probing
                 }
            }
        }
    }
    if (a[index] == selectVal)
        return index;
    else
        return -1;
}

