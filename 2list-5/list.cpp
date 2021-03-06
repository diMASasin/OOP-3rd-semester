#include <iostream>
#include "list.h"

using namespace std;

const string TypeName[4]= 
            { "(unknown)", "Auto", "Aircraft", "Ship" };


	Node::Node()
	{
		prev = NULL;
		next = NULL;
		list = NULL;
	}
	
	Node::~Node()
	{
		if(list)
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
	
	Node* Node::getNext() const
	{
		return next;
	}
	
	Node* Node::getPrev() const
	{
		return prev;
	}
	
	Node* List::getHead() const
	{
		return head;
	}
	
	Node* List::getTail() const
	{
		return tail;
	}
	
	List* Node::IsInList() const
	{
		return list;
	}

    void List::Add(Node* element)
    {
    	if(!element || element->list)
    		return;
    		
    	element->list = this;
    	
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
    	if(!newElement || index < 0 || newElement->list)
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
    		newElement->list = this;
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
        if (!item || item->list != this)
            return NULL;

        if (item->prev != NULL)
            item->prev->next = item->next;
        if (item->next != NULL)
            item->next->prev = item->prev;

        if (item == head)
            head = item->next;
        if (item == tail)
            tail = item->prev;
            
        item->next = NULL;
        item->prev = NULL;
        item->list = NULL;

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

        for (i = 0; item != NULL; i++) 
		{
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
