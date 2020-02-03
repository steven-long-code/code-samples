// This is another functor example showing that functors can use context information
#include <iostream>
#include <ctype.h>
using namespace std;

class Car
{
  private:
    string brand;
    int    year;
  public:
    Car(string _name, int _year);
    ~Car();
};

Car::Car(string _brand, int _year)
{
  cout << _brand << " " << _year << ": " "Constructor called\n";
  brand = _brand; year = _year;
}

Car::~Car()
{
  cout << brand << " " << year << ": " << "Destructor called\n";
}


class SUV : public Car
{
  private:
     bool  fourWheelDrive;
  public:
    SUV(string _name, int _year, bool _fourWheelDrive);
};

SUV::SUV(string _name, int _year, bool _fourWheelDrive) : Car(_name, _year)
{
    fourWheelDrive = _fourWheelDrive;
    cout << "SUV 4 Wheel Drive: "<< fourWheelDrive << " constructor called\n";
}

void f()
{
    //Car mycar1; // wrong
  Car mycar2("Ford", 2011);
  Car mycar3("Honda", 2012);
  SUV mycar4("Land Rover", 1999, true);
  cout << "===In function f()\n";
}
int main()
{
  cout << "---Calling function f()\n";
  f();
  cout << "---Returns from function f()\n";
}
