#include <iostream>
#include <cstdlib>
using namespace std;

const int ArraySize = 6;
struct Student
{
    string Name;
    double GPA;
};
struct Student StudentArray[ArraySize] = { {"AA",3.0}, {"BB",3.1}, {"CC",3.2}, {"DD",3.3}, {"EE",3.4}, {"FF",3.5} };

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


void IncreaseGPA(Student &x)
{
    x.GPA += 0.5;
}
void DecreaseGPA(Student &x)
{
    x.GPA -= 0.5;
}
void DoSomethingForAll(struct Student array[], int Size, void (*DoIt)(Student &))
{
    for (int i =0; i < Size; i++)
        (*DoIt)(array[i]);
}
int main()
{
    cout <<"Original Data:\n";
    DisplayAll(StudentArray, ArraySize);

    cout <<"\n After Increase GPA:\n";
    DoSomethingForAll(StudentArray, ArraySize, IncreaseGPA);
    DisplayAll(StudentArray, ArraySize);

    cout <<"\n After Decrease GPA:\n";
    DoSomethingForAll(StudentArray, ArraySize, DecreaseGPA);
    DisplayAll(StudentArray, ArraySize);
}
