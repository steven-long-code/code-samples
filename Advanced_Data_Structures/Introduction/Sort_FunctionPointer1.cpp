#include <iostream>
#include <cstdlib>
using namespace std;

const int ArraySize = 6;
struct Student
{
    string Name;
    double GPA;
};
struct Student StudentArray[ArraySize] = { {"AA",3.0},  {"CC",2.2}, {"BB",3.1},{"DD",1.3},  {"FF",3.5}, {"EE",3.4} };
void DisplayAll(struct Student array[], int Size)
{
    double sum=0;
    int  count = 0;
    for (int i =0; i < Size; i++) {
        auto x = array[i];
        cout << x.Name << "'s GPA = " << x.GPA << endl;
        sum += x.GPA;
        count++;
    }
    cout << "avg= " << sum/count << "\n\n";
}


int sortGPA( const void *first_arg, const void *second_arg )
{
    double first = (*(Student*)first_arg).GPA;
    double second= (*(Student*)second_arg).GPA;
    if ( first < second )
    {
        return -1;
    }
    else if ( first == second )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int sortName( const void *first_arg, const void *second_arg )
{
    string first = (*(Student*)first_arg).Name;
    string second= (*(Student*)second_arg).Name;
    if ( first < second )
    {
        return 1;   // note we reversed the order here
    }
    else if ( first == second )
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int main()
{
    cout << "Original Array:\n";
    DisplayAll(StudentArray, ArraySize);

    qsort( StudentArray, ArraySize , sizeof( Student ), sortGPA );
    cout << "After Sort by GPA:\n";
    DisplayAll(StudentArray, ArraySize);

    qsort( StudentArray, ArraySize , sizeof( Student ), sortName );
    cout << "After Sort by Name:\n";
    DisplayAll(StudentArray, ArraySize);
}
