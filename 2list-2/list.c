#include<stdio.h>
#include<stdlib.h>
#include"list.h"

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
