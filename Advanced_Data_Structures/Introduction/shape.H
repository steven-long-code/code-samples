#ifndef _SHAPE_
#define _SHAPE_

#include <string>
using namespace std;

class Shape
{
  public:
    string  Name;
    Shape (string s);
    virtual double getArea();
    virtual void DisplayArea();
};


#endif // _SHAPE_

