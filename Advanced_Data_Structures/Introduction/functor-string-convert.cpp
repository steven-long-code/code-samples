// This is another functor example showing that functors can use context information
#include <iostream>
#include <ctype.h>
using namespace std;
class Convert
{
 public:
    void virtual operator () (char &c) = 0;
    void reset() {}; // does nothing by default
};

class CapitalizeFunctorClass : public Convert
{
    private:
       char lastChar;
    public:
        CapitalizeFunctorClass() {lastChar = ' ';};
        void operator () (char &c)
        {
            if ( isalpha(c) )
            {
              if ( isspace(lastChar) )
                  c = toupper(c);
              else
                  c = tolower(c);
            }
            lastChar = c;
        }
};

class CapitalizeOnlyFirstFunctorClass : public Convert
{
    private:
       bool Converted;
    public:
        CapitalizeOnlyFirstFunctorClass() {Converted = false;};
        void operator () (char &c)
        {
            if ( isalpha(c) )
            {
                if ( !Converted)
                {
                   c = toupper(c);
                   Converted = true;
                } else
                   c = tolower(c);
            }
        }

        void reset() {Converted = false;};
};

void convertString(string &s, Convert& cv)
{
    cv.reset();
    for (int i=0; i < (int)s.length(); i++) {
        cv(s[i]);
    }
}

int main()
{
    CapitalizeFunctorClass  MyCapitalizeFunctor;
    CapitalizeOnlyFirstFunctorClass  MyCapitalizeOnlyFirstFunctor;

    string info = " THIS IS ANOTHER FUNCTOR EXAMPLE SHOWING THAT FUNCTORS CAN USE CONTEXT INFORMATION.";
    cout << info << endl;

    convertString(info, MyCapitalizeFunctor);
    cout << info << endl;

    convertString(info, MyCapitalizeOnlyFirstFunctor);
    cout << info << endl;
}
