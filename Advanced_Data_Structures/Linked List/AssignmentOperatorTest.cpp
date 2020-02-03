// This program demonstrates the deleteNode member function.
#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
   // Define a NumberList object.
   NumberList L1;

   // Build the list with some values.
   L1.appendNode(2.5);
   L1.appendNode(7.9);
   L1.appendNode(12.6);

   // Display the list.
   cout << "Here are the initial values:\n";
   L1.displayList();
   cout << endl;

   NumberList L2, L3;
   NumberList *lp;
   L3 = L2 = L1;
   L1.appendNode(99.9);
   L2.appendNode(66.6);
   lp = &L3;

      // Display the list.
   cout << "Here are the values of the three lists:\n";
   L1.displayList();
   cout << endl;
   L2.displayList();
   cout << endl;
   L3.displayList();
   cout << endl;

   // Self assignment 1
   cout << "Self assignment test 1:\n";
   L1 = L1;
   L1.displayList();
   cout << endl;

      // Self assignment 2
   cout << "Self assignment test 2:\n";
   cout << "before:\n";
   lp->displayList();
   cout << endl;

   cout << "after:\n";
   L3 = *lp;
   L3.displayList();
   cout << endl;
}
