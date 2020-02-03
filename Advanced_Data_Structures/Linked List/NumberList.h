// Specification file for the NumberList class
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
public:
   // Declare a structure for the list
   struct ListNode
   {
      double value;           // The value in this node
      struct ListNode *next;  // To point to the next node
   };

   ListNode *head;            // List head pointer

public:
   // Constructor
   NumberList()
      { head = NULL; }

   // Destructor
   ~NumberList();

   NumberList(const NumberList& l);

   // Linked list operations
   void appendNode(double);
   void insertNode(double);
   void deleteNode(double);
   void displayList() const;
   void distroyList();
   NumberList& operator=(const NumberList& l);
};
#endif
