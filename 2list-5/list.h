#define NUM_OF_MENU_ELEMENTS 15
#define MAX_STRING_LENGTH 25

class List;

class Node
{
	friend class List;

private:
	Node* prev;
	Node* next;
	List* list;

public:
	Node* getNext() const;
	Node* getPrev() const;
	List* IsInList() const;
	Node();
	~Node();
};

class List
{
private:
	Node* head;
	Node* tail;

public:
	List();
	~List();
	Node* getHead() const;
	Node* getTail() const;
	List* CreateList();
	void Add(Node* element);
	void Insert(Node* newElement, int index);
	int Count();
	Node* GetItem(int index);
	Node* Remove(int index);
	Node* Remove(Node* item);
	int Delete(int index);
	void Print();
	int GetIndex(Node* element);
	void Clear();
};
