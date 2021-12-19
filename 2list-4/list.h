class List;

class Node 
{
	friend class List;
	friend class DebugList;
	
private:
    Node* prev;
    Node* next;
    List* list;
    
public:
	Node(List* list);
	~Node();
};

class List
{	
	friend class DebugList;
	
	private:
    Node* head;
    Node* tail;

	public:
	List();
	~List();
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
    void SortBySpeed(List *list);
	void SortByRangeOfMovement(List *list);
	void SearchByNumberOfSeats(List *list);
	void SearchByBaggageWeight(List *list);
};
