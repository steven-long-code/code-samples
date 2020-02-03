#include <iostream>
#include <cmath>
using namespace std;

class Address
{
    string StreetName;
    string StreetNumber;
    string City;
    string Zip;
    string State;
public:
    Address(string StreetNumber="No Address", string StreetName="", string City="", string Zip="", string State="");
    friend ostream& operator<<(ostream& os, const Address& RHS);
};


Address::Address(string StreetNumber, string StreetName, string City, string Zip, string State)
{
    this->StreetName = StreetName;
    this->StreetNumber = StreetNumber;
    this->City = City;
    this->Zip = Zip;
    this->State = State;
}
ostream& operator<<(ostream& os, const Address& RHS)
{
    os <<  RHS.StreetNumber + " " + RHS.StreetName + ", "
         + RHS.City + ", " + RHS.State + " " + RHS.Zip;
    return os;
}


struct PeopleRec
{
    string name;
    Address addr;
    PeopleRec(const string name = "No Name", const Address a = Address("No Address", "", "", "", "") )
      {this->name=name; this->addr = a;}
};


// Associative array

class AssociativeArray
{
  private:
    int arraySize; // dynamic array size
    PeopleRec *data;
  public:
    AssociativeArray( int size = 10);
    PeopleRec& operator[] (const int Index) {return data[Index];}  // access by index
    PeopleRec& operator[] (const string name);                     // access by name
};


AssociativeArray::AssociativeArray(int size)
{
   data = new PeopleRec[size];
   arraySize = size;
}

PeopleRec& AssociativeArray::operator[] (const string name)
{
    int i;
    for (i=0; i< arraySize; i++)
    {
       if (data[i].name == name)
          break;
    }

    if (i<arraySize)
        return data[i];
    else {
        string ErrorMsg = "Cannot find the person : " + name;
        throw ErrorMsg;
    }

}


int main()
{
   Address a1("1600", "Pennsylvania Ave NW", "Washington, D.C", "DC", "20500");
   Address a2("10", "Downing Street", "City of Westminster", "London", "");

   PeopleRec P1("Mike Frank", Address("814", "Rhodes", "Cincinnati", "Ohio", "45221-0030"));
   PeopleRec P2("Barack Obama", a1);
   PeopleRec P3("Michelle Obama", a1);
   PeopleRec P4("David Cameron", a2);

   AssociativeArray A;   // define an array, initial size is default size (10)
   A[0] = P1;
   A[1] = P2;
   A[2] = P3;
   A[3] = P4;

   int i;
   for (i = 0; i < 5; i++)
   {
       cout << i << ": " << A[i].name << ", " << A[i].addr << endl;
   }

   cout << endl;

   try
   {
      cout << "Mike Frank's address is: " << A["Mike Frank"].addr << endl;
      cout << "Barack Obama's address is: " << A["Barack Obama"].addr << endl;
      cout << "Michelle Obama's address is: " << A["Michelle Obama"].addr << endl;
      cout << "Someone's address is: " << A["Someone"].addr << endl;
   }
   catch (const string ErrorMessage)
   {
      cout << "Error: " << ErrorMessage << endl;
   }

}


