#include <iostream>
#include "shape.H"

Shape::Shape(string s)
{
    Name = s;
}

double Shape::getArea()
{
    return 0;   //shape has no arae
}

void Shape::DisplayArea()
{
    std::cout << "The area of " << Name << " is :" << getArea() << " square inches\n";
};
