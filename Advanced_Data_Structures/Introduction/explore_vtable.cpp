// We will explore the contents/structure of C++ Virtual Method Table
//
#include <iostream>
using namespace std;


class Base
{
public:
    //some data members
    virtual void function1();
    virtual void function2();
};

class D1: public Base
{
public:
    virtual void function1();
};


class D2: public Base
{
public:
    virtual void function2();
};




void Base::function1()
{
   cout << "in Base::function1()\n";
}

void Base::function2()
{
   cout << "in Base::function2()\n";
}


void D1::function1()
{
    cout << "in D1::function1()\n";
}


void D2::function2()
{
    cout << "in D2::function2()\n";
}

typedef void(*Fun)(void);

int main()
{
    int *p;
    Fun pFun;
    Base b;
    D1   d1;
    D2   d2, d3;

    cout << "------------ find out vtable info for object b -------\n";
    p = (int*)(&b);  // get the address of the vptr, which is normally the first element of the object
    cout << "VPTR of b is located at " << p << ",  it's content is " << *p << endl;
    p = (int*)*p;     // get the address of the virtual function table

    cout << "   The address of the 1st virtual function POINTER is " << p << endl;
    pFun = (Fun)*p;
    cout << "      The address of the 1st virtual function is " << *p << endl;
    pFun();


    cout << "The address of the 2nd virtual function POINTER is " << p+1 << endl;
    pFun = (Fun)*(p+1);
    cout << "      The address of the 2nd virtual function is " << *(p+1) << endl;
    pFun();


    cout << "\n------------ find out vtable info for object d1 -------\n";
    p = (int*)(&d1);  // get the address of the vptr, which is normally the first element of the object
    cout << "VPTR of d1 is located at " << p << ",  it's content is " << *p << endl;
    p = (int*)*p;     // get the address of the virtual function table

    cout << "   The address of the 1st virtual function POINTER is " << p << endl;
    pFun = (Fun)*p;
    cout << "      The address of the 1st virtual function is " << *p << endl;
    pFun();


    cout << "The address of the 2nd virtual function POINTER is " << p+1 << endl;
    pFun = (Fun)*(p+1);
    cout << "      The address of the 2nd virtual function is " << *(p+1) << endl;
    pFun();


    cout << "\n------------ find out vtable info for object d2 -------\n";
    p = (int*)(&d2);  // get the address of the vptr, which is normally the first element of the object
    cout << "VPTR of d2 is located at " << p << ",  it's content is " << *p << endl;
    p = (int*)*p;     // get the address of the virtual function table

    cout << "   The address of the 1st virtual function POINTER is " << p << endl;
    pFun = (Fun)*p;
    cout << "      The address of the 1st virtual function is " << *p << endl;
    pFun();


    cout << "The address of the 2nd virtual function POINTER is " << p+1 << endl;
    pFun = (Fun)*(p+1);
    cout << "      The address of the 2nd virtual function is " << *(p+1) << endl;
    pFun();

    cout << "\n------------ find out vtable info for object d2 -------\n";

    p = (int*)(&d3);  // get the address of the vptr, which is normally the first element of the object
    cout << "VPTR of b is located at " << p << ",  it's content is " << *p << endl;
    p = (int*)*p;     // get the address of the virtual function table

    cout << "   The address of the 1st virtual function POINTER is " << p << endl;
    pFun = (Fun)*p;
    cout << "      The address of the 1st virtual function is " << *p << endl;
    pFun();

    cout << "The address of the 2nd virtual function POINTER is " << p+1 << endl;
    pFun = (Fun)*(p+1);
    cout << "      The address of the 2nd virtual function is " << *(p+1) << endl;
    pFun();

    cout << "\n------------ We can also call virtual functions of object d3 this way -------\n";
    pFun = (Fun)*((int*)*(int*)(&d3));
    pFun();
    pFun = (Fun)*((int*)*(int*)(&d3)+1);
    pFun();

}
