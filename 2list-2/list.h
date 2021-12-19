typedef struct _Node Node;
typedef struct _List List;

struct _Node
{
	Node* prev;
	Node* next;
};

struct _List
{
	Node* head;
	Node* tail;
};

void Add(List *list, Node *element);
int Delete(List *list, int index);
int Count(const List *list);
void Insert(List *list, Node *newElement, int index);
Node* GetItem(const List *list, int index);
void Clear(List *list);
Node* Remove(List *list, int index);
int GetIndex(const List *list, Node *element);
void PrintItem(const Node *item, int index);
void PrintList(const List *list);
int InputNumber();
