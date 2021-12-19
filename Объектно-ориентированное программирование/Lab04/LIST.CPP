#include "list.h"

//
// Implementation of some methods of class List
//
// You may listen and writing lections and reading
// your abstracts and thinking and this implementation
// becomes clearly!
//

List::List(void) : head(0), tail(0), count(0)
{
}

Item * List::First(void) const
{
  return head;
}

void List::Add(Item * p)
{
  if (!p || p->owner) // necessary!
    return;

  p->prev = tail;  // it's as usual -
  p->next = 0;     // compare it with lab #2 example
  if (tail)
    tail->next = p;
  else
    head = p;
  tail = p;

  p->owner = this; // necessary! - and for Insert() also,
                   // moreover Remove(Item*p) must do "p->owner=0"
  count++;         // necessary! (see below)
}

void List::Delete(int n)
{
  Item * p = Remove(n); // then Remove(int) calls Remove(Item*) :)
  if (p)
    delete p;
}

int List::Count(void) const
{
  return count;  // don't spend time for watch in list -        :)
}                // Add() & Insert() do "count++" (see above)
                 // and Remove(Item*) do "count--"
