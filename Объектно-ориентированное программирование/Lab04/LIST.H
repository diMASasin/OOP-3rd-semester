#ifndef _LIST_H_
#define _LIST_H_
  // this directives requires for prevent of
  // repeated include this header in some module

class Item
{
  friend class List;

private:
  // Base set
  Item * prev;
  Item * next;

  // Additional
  List * owner;    // for remove self from list and
                   // for check when item in list
public:
  Item(void);
  ~Item();         // for correct object destruction
                   // with removing it from list
  // Additional
  Item * Next(void) const;  // special for implementation
};                          // of iterations algorithms

class List
{
private:
  // Base set
  Item * head;
  Item * tail;

  // Additional
  int count;     // for quickly count items in list

public:
  List(void);
  ~List();       // kills all of items inself

  // Base set
  void Add(Item * p);
  void Insert(Item * p, int n);
  Item * GetItem(int n) const;
  int GetIndex(const Item * p) const;
  Item * Remove(int n);
  void Delete(int n);
  int Count(void) const;
  void Clear(void);

  // Additional
  Item * Remove(Item * p);   // for illiminate item by pointer
                             // (used in Remove(int) method and
                             // may be used outside)
  Item * First(void) const;   // special for implementation
};                            // of iterative algorithmes

  // finish #ifndef at top
#endif