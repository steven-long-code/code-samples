#include <iostream>
#include <stdlib.h>     // srand, rand
#include <limits.h>     // INT_MAX
#include <algorithm>    // std::sort


using namespace std;

double  maxValue =  1000.0;
const int MAX_ARRAY_SIZE = 35;
double  myArray[MAX_ARRAY_SIZE];


bool compare(int i1, int i2)
{
  return i1<=i2;
}



template<class DataType>
void merge(DataType theArray[],int first, int mid, int last)
{
    DataType tempArray[MAX_ARRAY_SIZE];    // temporary array

    // initialize the local indexes to indicate the subarrays
    int first1 = first;       // beginning of first subarray
    int last1  = mid;         // end of first subarray
    int first2 = mid + 1;     // beginning of second subarray
    int last2  = last;        // end of second subarray

    // while both subarrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1;    // next available location in
    // tempArray
    for (; (first1 <= last1) && (first2 <= last2); ++index)
    {
        // Invariant: tempArray[first..index-1] is in order
        if (theArray[first1] < theArray[first2])
        {
            tempArray[index] = theArray[first1];
            ++first1;
        }
        else
        {
            tempArray[index] = theArray[first2];
            ++first2;
        }  // end if
    }  // end for

    // finish off the nonempty subarray

    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index)
        // Invariant: tempArray[first..index-1] is in order
        tempArray[index] = theArray[first1];

    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index)
        // Invariant: tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2];

    // copy the result back into the original array
    for (index = first; index <= last; ++index)
        theArray[index] = tempArray[index];
}  // end merge

template<class DataType>
void MergeSort(DataType theArray[],int first, int last)
{
   if (first >= last)
      return;

   int middle = (last + first) / 2;
   MergeSort(theArray,first, middle);
   MergeSort(theArray,middle+1, last);
   merge(theArray,first,middle,last);
}


template<class DataType>
void MergeSort(DataType theArray[],int ArraySize)
{
   MergeSort(theArray, 0, ArraySize);
}


void print_array()
{
     cout << "\n ----- Array Content --------\n";
     for (int i=0; i<MAX_ARRAY_SIZE-1; i++)
        cout << myArray[i] << " ";
     cout << endl;
}


int main()
{
     for ( int i=0; i<MAX_ARRAY_SIZE-1; i++)
        myArray[i] = maxValue * rand() / RAND_MAX;

     print_array();

     MergeSort(&myArray[0], MAX_ARRAY_SIZE-1);

     print_array();

}
