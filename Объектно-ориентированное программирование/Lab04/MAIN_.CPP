#include <conio.h>
#include <stdio.h>
#include <iostream.h>

#include "List.h"

// see main function at bottom

class Test : public List  // example of use of class List
{
public:
  void Print(void);
  void Run(void);
  // for lab #5 at this place:
  //   Sort()
  //   Find()
  //   ...
};


// Method Test::Print() is an example of use
// of List::First() and Item::Next() methods
// for iterative process implementation

void Test::Print(void)
{
  int i = 0;
  cout << "List: " << this << "\n#\tp\tnext\n";
  for (Item * p = First(); p; p = p->Next(), i++)
    cout << i << '\t' << p << '\t' << p->Next() << '\n';
}

void Test::Run(void)
{
  char c;
  int i;
  Item * p;

  do
  {
    clrscr();
    Print();
    cout << "\n1 Add\n2 Insert\n3 Delete\n4 GetItem\n5 GetIndex\n6 Count\n7 Clear\n0 Exit\n>>";
    c = getche();
    cout << '\n';

    switch (c)
    {
      case '1':
        Add(new Item);
        break;

      case '2':
        cout << "Enter position: ";
        cin >> i;
        Insert(new Item, i);
        break;

      case '3':
        cout << "Enter position: ";
        cin >> i;
        Delete(i);
        break;

      case '4':
        cout << "Enter position: ";
        cin >> i;
        cout << "Pointer: " << GetItem(i) << '\n';
        getch();
        break;

      case '5':
        cout << "Enter pointer: ";
        scanf("%p", &p); // cin can't input a pointer :(
        cout << "Position: " << GetIndex(p) << '\n';
        getch();
        break;

      case '6':
        cout << "Count: " << Count() << "\n";
        getch();
        break;

      case '7':
        Clear();
        break;
    }
  }
  while (c != '0');
}

// main() function
void main(void)
{
  Test L;
  L.Run();
  // L.Clear();  // now it's performs by destructor List::~List()
}
// that's all!
