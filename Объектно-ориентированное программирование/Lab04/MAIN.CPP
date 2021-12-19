#include <conio.h>
#include <stdio.h>

#include "List.h"

// see main() function at bottom

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
  printf("List: %p\n#\tp\tnext\n", this);
  for (Item * p = First(); p; p = p->Next(), i++)
    printf("%d\t%p\t%p\n", i, p, p->Next());
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
    printf("\n1 Add\n2 Insert\n3 Delete\n4 GetItem\n5 GetIndex\n"
           "6 Count\n7 Clear\n0 Exit\n>>");
    c = getche();
    printf("\n");

    switch (c)
    {
      case '1':
        Add(new Item);
        break;

      case '2':
        printf("Enter position: ");
        scanf("%d", &i);
        Insert(new Item, i);
        break;

      case '3':
        printf("Enter position: ");
        scanf("%d", &i);
        Delete(i);
        break;

      case '4':
        printf("Enter position: ");
        scanf("%d", &i);
        printf("Pointer: %p\n", GetItem(i));
        getch();
        break;

      case '5':
        printf("Enter pointer: ");
        scanf("%p", &p);
        printf("Position: %d\n", GetIndex(p));
        getch();
        break;

      case '6':
        printf("Count: %d", Count());
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
