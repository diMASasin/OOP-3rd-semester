#include <iostream>
#include "list.h"

using namespace std;


    Node::Node(List* list)
    {
	prev = NULL;
	next = NULL;
	this->list = list;
    }
	
    Node::~Node()
    {
	list->Remove(this);
    }

    List::List()
    {
	head = NULL;
	tail = NULL;
    }
	
    List::~List()
    {
	Clear();
    }
	
    List* List::CreateList()
    {
        List* list;
        list = new List();
        list->head = NULL;
        list->tail = NULL;

        return list;
    }

    void List::Add(Node* element)
    {
    	if(!element)
    		return;
    	
        if (head == NULL && tail == NULL) 
		{
            head = element;
            tail = element;
            return;
        }

        tail->next = element;
        element->prev = tail;
        tail = element;
        element->next = NULL;
    }

    void List::Insert(Node* newElement, int index)
    {
    	if(!newElement || index < 0)
    		return;
    	
        Node* item;
        item = GetItem(index);

        if (item) 
		{
            if (item->prev != NULL)
                item->prev->next = newElement;
            else
                head = newElement;
                
            newElement->next = item;
            newElement->prev = item->prev;
            item->prev = newElement;
        }
        else 
		{
            Add(newElement);
        }
    }

    int List::Count()
    {
		Node* currentNode;
        int count = 0;
        currentNode = head;
		
		if(!currentNode)
			return count;
		
        while (currentNode) 
		{
            count++;
            currentNode = currentNode->next;
        }

        return count;
    }

    Node* List::GetItem(int index)
    {
    	if(index < 0)
    		return NULL;
    	
        Node* item;
        int i;

        item = head;

        for (i = 0; i < index; i++)
        {
        	if(!item)
				return NULL;
				        	
        	item = item->next;
		}  

        return item;
    }

    Node* List::Remove(int index)
    {
    	if(index < 0)
    		return NULL;
    	
        Node* item;
        item = GetItem(index);

		Remove(item);
        return item;
    }
    
    Node* List::Remove(Node* item)
    {
        if (!item)
            return NULL;

        if (item->prev != NULL)
            item->prev->next = item->next;
        if (item->next != NULL)
            item->next->prev = item->prev;

        if (item == head)
            head = item->next;
        if (item == tail)
            tail = item->prev;

        return item;
    }

    int List::Delete(int index)
    {
    	if(index < 0)
    		return 0;
    		
        Node* item;

        item = Remove(index);
        if (!item)
            return 0;

        delete item;
        return 1;
    }

    int List::GetIndex(Node* element)
    {
    	if(!element)
    		return -1;
    	
        Node* item;
        item = head;
        int i;

        for (i = 0; item != NULL; i++) {
            if (item == element)
                return i;

            item = item->next;
        }
        return -1;
    }

    void List::Clear()
    {
        while (head)
            Delete(0);
    }
    
    int InputNumber()
	{
		int num;
	
		while(fflush(stdin), !scanf("%d", &num))
			printf("Ошибка ввода, попробуйте еще раз: ");
	
		return num;
	}

	double InputDouble()
	{
		double num;
	
		while(fflush(stdin), !scanf("%lg", &num))
			printf("Ошибка ввода, попробуйте еще раз: ");
	
		return num;
	}
