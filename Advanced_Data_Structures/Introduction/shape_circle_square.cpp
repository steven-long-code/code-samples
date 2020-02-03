#include <iostream>
#include "shape.H"
using namespace std;



class Square : public Shape
{
  private:
    double EdgeLength;
  public:
    Square(string name, double l) : Shape(name) {EdgeLength = l;};
    virtual double getArea() {return EdgeLength*EdgeLength;};
};

class Circle  : public Shape
{
  private:
    double Diameter;
  public:
    Circle(string name, double d) : Shape(name) {Diameter = d;};
    virtual double getArea() {return 3.1415*Diameter*Diameter/4;};
};

void test_shape(Shape s)
{
    cout << "In test_shape() : ";
    s.DisplayArea();
}

void test_shape1(Shape & s)
{
    cout << "In test_shape1() : ";
    s.DisplayArea();
}


int main()
{
   Square s("Square#1", 10);
   Circle c("Circle#1", 8);

   cout << "\nTesting Direct Calls\n\n";
   s.DisplayArea();
   c.DisplayArea();


   cout << "\nTesting Pointers\n\n";
   Shape *S_Pointer;

   S_Pointer = &s;
   S_Pointer->DisplayArea();

   S_Pointer = &c;
   S_Pointer->DisplayArea();



   cout << "\nTesting Pass by Values\n\n";
   test_shape(s);
   test_shape(c);


   cout << "\nTesting Pass by Reference\n\n";
   test_shape1(s);
   test_shape1(c);
}
