#include <iostream>
#include <algorithm>    // std::sort
#include <vector>
using namespace std;

struct Student
{
    string Name;
    double GPA;
};

vector<Student> StudentArray = { {"AA",3.0},  {"CC",2.2}, {"BB",3.1},{"DD",1.3},  {"FF",3.5}, {"EE",3.4} };

bool SortByGPA(Student l, Student r)
{
   return l.GPA < r.GPA;
}

bool SortByName(Student l, Student r)
{
   return l.Name > r.Name;
}

void DisplayAll(vector<Student> array)
{
    for (auto x : array)
        cout << x.Name << "'s GPA = " << x.GPA << endl;
}

int main()
{
    cout << "Original Array:\n";
    DisplayAll(StudentArray);

    cout << "After Sort by GPA:\n";
    sort(StudentArray.begin(), StudentArray.end(), SortByGPA);
    DisplayAll(StudentArray);

    cout << "After Sort by Name:\n";
    sort(StudentArray.begin(), StudentArray.end(), SortByName);
    DisplayAll(StudentArray);
}
