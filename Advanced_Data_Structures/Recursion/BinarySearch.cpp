#include <iostream>
#include <stdlib.h>     // srand, rand
#include <limits.h>     // INT_MAX
#include <algorithm>    // std::sort

#define DEBUG 0

using namespace std;

const int MAX_ARRAY_SIZE = 1600;
int myArray[MAX_ARRAY_SIZE];
int NumberOfCompare = 0;

bool compare(int i1, int i2)
{
  return i1<=i2;
}

void print_array()
{
     cout << "\n ----- Array Content --------\n";
     for (int i=0; i<MAX_ARRAY_SIZE-1; i++)
        cout << myArray[i] << " ";
     cout << endl;
}

// real search function
int binary_search(int Array[], int StartingIndex, int EndingIndex, int Num )
{
    NumberOfCompare++;

    #if DEBUG
    cout << "(" << StartingIndex << "," << EndingIndex << ")";
    #endif

    // base case
    if (StartingIndex > EndingIndex)
        return -1;

    int MiddleIndex = (EndingIndex + StartingIndex) / 2;

    #if DEBUG
    cout << "---- Middle Index = " << MiddleIndex << "  Middle Data = " <<  Array[MiddleIndex]  << endl;
    #endif

    if (Array[MiddleIndex] == Num)
    {
        #if DEBUG
         cout << "Found at:" << MiddleIndex << endl;
        #endif
         return MiddleIndex;
    } else if (Array[MiddleIndex] < Num)
    {
       #if DEBUG
       cout << "R of " << Array[MiddleIndex] << "; ";
       #endif
       return binary_search(myArray, MiddleIndex+1, EndingIndex, Num);
    }
    else
    {
       #if DEBUG
       cout << "L of " << Array[MiddleIndex] << "; ";
       #endif
       return binary_search(myArray, StartingIndex, MiddleIndex-1, Num);
    }


}

// interface function
int binary_search(int Num)
{
    NumberOfCompare = 0;
    return binary_search(myArray, 0, MAX_ARRAY_SIZE-1, Num);
}

int main()
{
     for ( int i=0; i<MAX_ARRAY_SIZE-1; i++)
        myArray[i] = rand() % INT_MAX;

     print_array();

     sort(&myArray[0], &myArray[MAX_ARRAY_SIZE-1]);

     print_array();

     while (true)
     {
        int num;
        cout << "Please enter a number to be searched:";
        cin >> num;

        int index = binary_search(num);
        if (index >= 0)
            cout << "Data found in location " << index << endl;
        else
            cout << "Data not found\n";

        cout << "\n\n ====== Number of compare = " << NumberOfCompare << endl;
     }

}
