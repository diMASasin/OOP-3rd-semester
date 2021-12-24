#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Node Node;

struct _Node
{
	Node* prev;
	Node* next;
};

typedef struct _List
{
	Node* head;
	Node* tail;
} List;

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

List* CreateList()
{
	List* list;
	list = malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	
	return list;
}

void Add(List *list, Node *element)
{
	if(!list || !element)
		return;
	
	if(list->head == NULL && list->tail == NULL)
	{
		list->head = element;
		list->tail = element;
		element->prev = NULL;
		element->next = NULL;
		return;
	}
	
	list->tail->next = element;
	element->prev = list->tail;
	list->tail = element;
	element->next = NULL;	
}

void Insert(List *list, Node *newElement, int index)
{	
	if(!list || !newElement || index < 0)
		return;
	
	Node *item;
	Node *prevItem;
	item = GetItem(list, index);
	
	if(item)
	{
		prevItem = item->prev;
		if(prevItem != NULL)
			prevItem->next = newElement;
		else
			list->head = newElement;
		newElement->next = item;
		newElement->prev = item->prev;
		item->prev = newElement;
	}
	else
	{
		Add(list, newElement);
	}
}

int InputNumber()
{
	int num;
	
	while(fflush(stdin), !scanf("%d", &num))
		printf("Ошибка ввода, попробуйте еще раз: ");
	
	return num;
}

int Count(const List *list)
{
	if(!list)
		return;
	
	Node *currentNode;
	int count = 0;
	
	if(list->head == NULL)
		return count;
	
	currentNode = list->head;
	count++;
	
	while(currentNode->next)
	{
		count++;
		currentNode = currentNode->next;
	}
	
	return count;
}

Node* GetItem(const List *list, int index)
{
	if(!list || index < 0)
		return;
	
	Node *item;
	int i;
	
	if(!list->head)
		return NULL;
	
	item = list->head;
	
	for(i = 0; i < index; i++)
	{
		if(!item)
			return NULL;
		item = item->next;
	}		
	
	return item;
}

Node* Remove(List *list, int index)
{
	if(!list || index < 0)
		return;
		
	Node *item;
	item = GetItem(list, index);
	
	if(!item)
		return NULL;
	
	if(item->prev != NULL)
		item->prev->next = item->next;
	if(item->next != NULL)
		item->next->prev = item->prev;
		
	if(item == list->head)
		list->head = item->next;
	if(item == list->tail)
		list->tail = item->prev;
	
	return item;
}

int Delete(List *list, int index)
{	
	if(!list || index < 0)
		return;
		
	Node *item;
	
	item = Remove(list, index);
	if(!item)
		return 0;
	
	free(item);
	return 1;
}

void PrintItem(const Node *item, int index)
{
	if(item)
		printf("%d\t%p\t%p\t%p\n", index, item, item->prev, item->next);
}

void PrintList(const List *list)
{
	int i;
	Node *item;
	item = list->head;
	
	printf("List: %p Head: %p Tail: %p\n", list, list->head, list->tail);
	printf("#\tp\t\t\tprev\t\t\tnext\n");
	
	for(i = 0; item != NULL; i++)
	{
		PrintItem(item, i);
		item = item->next;
	}
		
	printf("\n");
}

int GetIndex(const List *list, Node *element)
{
	if(!list || !element)
		return;
		
	Node *item;
	item = list->head;
	int i;
	
	for(i = 0; item != NULL; i++)
	{
		if(item == element)
			return i;
			
		item = item->next;
	}
}

void Clear(List *list)
{		
	while(list->head)
		Delete(list, 0);
}

int main()
{
	List *list;
	int nodeCount;
	Node *element;
	int index;
	int key = 15;
	system("chcp 1251 > nul");
	
	list = CreateList();
	
	while(key != 0)
	{
		printf("1. Добавить узел\n2. Вывести список\n3. Размер списка\n4. Вывести узел по индексу\n5. Исключить элемент\n"
		"6. Удалить узел\n7. Получить индекс\n8. Вставить элемент\n9. Очистить список\n0. Выход\n\n> ");
		scanf("%d", &key);				
		system("cls");
		
		switch(key)
		{
			case 1:
				element = malloc(sizeof(Node));
				
				Add(list, element);
				system("cls");
				printf("Узел добавлен в конец списка.\n\n");
				break;
			case 2:				
				PrintList(list);
				system("pause");				
				system("cls");
				break;
			case 3:
				nodeCount = Count(list);
				printf("Количество узлов в списке: %d\n\n", nodeCount);
				break;
			case 4:
				printf("Узел под каким индексом вы хотите получить?\n> ");
				index = InputNumber();
						
				element = GetItem(list, index);
				PrintItem(element, index);
				system("pause");
				system("cls");
				break;
			case 5:
				printf("Узел под каким индексом вы хотите исключить?\n> ");
				index = InputNumber();
				
				Remove(list, index);
				system("cls");
				printf("Узел исключен.\n\n");
				break;
			case 6:
				printf("Узел под каким индексом вы хотите удалить?\n> ");
				index = InputNumber();
				
				Delete(list, index);
				system("cls");
				printf("Узел удален.\n\n");
				break;
			case 7: 
				printf("Индекс узла под каким адресом вы хотите получить?\n> ");
				scanf("%p", &element);
				index = GetIndex(list, element);
				
				printf("Индекс элемента: %d\n\n", index);
				break;
			case 8:
				printf("Под каким индексом будет новый элемент?\n> ");
				nodeCount = Count(list);
				index = InputNumber();
				
				element = malloc(sizeof(Node));
				Insert(list, element, index);
				system("cls");
				printf("Узел добавлен.\n\n");
				break;
			case 9:
				Clear(list);
				system("cls");
				printf("Список очищен.\n\n");
				break;
			case 0:
				break;
			default:
				printf("Ошибка ввода.\n");
				break;
		}
	}
	
	return 0;
}
