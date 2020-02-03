#include <iostream>
#include <stdlib.h>     // srand, rand
#include <limits.h>     // INT_MAX
#include <time.h>


using namespace std;

int number_of_search = 0;

double  maxValue =  100.0;
const int MAX_ARRAY_SIZE = 32;
double  myArray[MAX_ARRAY_SIZE];

template<class DataType>
DataType FindMax(DataType theArray[],int first, int last)
{
   number_of_search++;

   if (first == last)
      return theArray[first];

   DataType d1, d2;
   int middle = (last + first) / 2;
   d1 = FindMax(theArray,first, middle);
   d2 = FindMax(theArray,middle+1, last);

   return (d1 > d2) ? d1 : d2;
}


void print_array()
{
     cout << "\n ----- Array Content --------\n";
     for (int i=0; i<MAX_ARRAY_SIZE; i++)
        cout << myArray[i] << " ";
     cout << endl;
}


int main()
{
     srand(time(NULL));
     for ( int i=0; i<MAX_ARRAY_SIZE; i++)
        myArray[i] = maxValue * rand() / RAND_MAX;

     print_array();

     cout << "Max value in array = " << FindMax(&myArray[0], 0, MAX_ARRAY_SIZE-1) << endl;
     // cout << "Number of search = " << number_of_search << endl;

}
