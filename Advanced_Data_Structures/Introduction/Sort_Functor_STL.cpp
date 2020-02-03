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


class MySorterClass
{
    public:
        enum SortField {STUDENT_NAME, STUDENT_GPA};
        enum SortOrder {ASCENDING, DESCENDING};
    private:
        enum SortField _field;
        enum SortOrder _order;
    public:

        void setSortField(SortField f) {_field = f;};
        void setSortOrder(SortOrder o) {_order = o;};
        bool operator () (const Student& lhs, const Student& rhs)
        {
            if (_field == STUDENT_NAME) {
               if (_order == ASCENDING)
                   return lhs.Name < rhs.Name;
               else
                   return lhs.Name > rhs.Name;
            } else {
               if (_order == ASCENDING)
                   return lhs.GPA < rhs.GPA;
               else
                   return lhs.GPA > rhs.GPA;
            }
        }

};

void DisplayAll(vector<Student> array)
{
    for (auto x : array)
        cout << x.Name << "'s GPA = " << x.GPA << endl;
}

int main()
{
    MySorterClass mySorter;

    cout << "Original Array:\n";
    DisplayAll(StudentArray);


    mySorter.setSortField(MySorterClass::STUDENT_GPA);
    mySorter.setSortOrder(MySorterClass::ASCENDING);
    sort(StudentArray.begin(), StudentArray.end(), mySorter);
    cout << "\nAfter Sort by GPA in ascending order:\n";
    DisplayAll(StudentArray);


    mySorter.setSortOrder(MySorterClass::DESCENDING);
    sort(StudentArray.begin(), StudentArray.end(), mySorter);
    cout << "\nAfter Sort by GPA in descending order:\n";
    DisplayAll(StudentArray);


    mySorter.setSortField(MySorterClass::STUDENT_NAME);
    mySorter.setSortOrder(MySorterClass::ASCENDING);
    sort(StudentArray.begin(), StudentArray.end(), mySorter);
    cout << "\nAfter Sort by Name in ascending order:\n";
    DisplayAll(StudentArray);


    mySorter.setSortOrder(MySorterClass::DESCENDING);
    sort(StudentArray.begin(), StudentArray.end(), mySorter);
    cout << "\nAfter Sort by Name in descending order:\n";
    DisplayAll(StudentArray);

}
