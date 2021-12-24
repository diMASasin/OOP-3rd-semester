#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdexcept>
#include"subj.h"                        

class Auto : public Base
{
	private:
	char brand[MAX_STRING_LENGTH];
	char color[MAX_STRING_LENGTH];
	
	public:
	virtual const char* const GetType(){return "Auto";}
		
	virtual void Print()
	{	
		Base::Print();
		printf("�����: %s\n", brand);
		printf("����: %s\n\n", color);
	}
	
	virtual void Input()
	{
		Base::Input();
		printf("�����: ");
		scanf("%s", brand);
		printf("����: ");
		scanf("%s", color);
	}
};

class Aircraft : public Base
{
	private:
	int numberOfCrewMembers;
	int numberOfEngines;
	double maxHeight;
	
	public:
	virtual const char* const GetType(){return "Aircraft";}
	
	virtual void Print()
	{	
		Base::Print();
		printf("���������� ������ �������: %d\n", numberOfCrewMembers);
		printf("���������� ����������: %d\n", numberOfEngines);
		printf("������������ ������: %lg\n\n", maxHeight);
	}
	
	virtual void Input()
	{
		Base::Input();	
		printf("���������� ������ �������: ");
		scanf("%d", &numberOfCrewMembers);
		printf("���������� ����������: ");
		scanf("%d", &numberOfEngines);
		printf("������������ ������: ");
		scanf("%lg", &maxHeight);
	}
};

class Ship : public Base
{
	private:
	int numberOfCrewMembers;
	int numberOfEngines;
	char name[MAX_STRING_LENGTH];
	char homePort[MAX_STRING_LENGTH];
	
	public:
	virtual const char* const GetType(){return "Ship";}
	
	virtual void Print()
	{
		Base::Print();	
		printf("���������� ������ �������: %d\n", numberOfCrewMembers);
		printf("���������� ����������: %d\n", numberOfEngines);
		printf("��������: %s\n", name);
		printf("���� ��������: %s\n\n", homePort);
	}
	
	virtual void Input()
	{
		Base::Input();
		printf("���������� ������ �������: ");
		scanf("%d", &numberOfCrewMembers);
		printf("���������� ����������: ");
		scanf("%d", &numberOfEngines);
		printf("��������: ");
		scanf("%s", name);
		printf("���� ��������: ");
		scanf("%s", homePort);
	}
};

void Base::Print()
{		
	printf("%s:\n", GetType());
	printf("������: %s\n", model);
	printf("������ �������: %lg\n", fuelConsumption);
	printf("������������ ��������: %lg\n", maxSpeed);
	printf("������������ ��������� ��������: %lg\n", rangeOfMovement);
	printf("���������� ����: %d\n", maxPassengerNumber);
	printf("������������ ��� ������: %lg\n", maxBaggageWeight);
} 

Base* Base::Create(ItemType type, List *list)
{
	if(!list)
    	return NULL;
    		
	Base* p;
   switch (type)
   {
     	case itAuto:
        	p = new Auto();
        	break;
      	case itAircraft:  
      		p = new Aircraft();
      		break;
      	case itShip:
      		p = new Ship();
      		break;
      	default:
      		printf("������!\n");
      		return NULL;
   }
    
    return p;
}

void Base::Input()
{	
	printf("������: ");
	scanf("%s", model);
	printf("������ �������: ");
	scanf("%lg", &fuelConsumption);
	printf("������������ ��������: ");
	scanf("%lg", &maxSpeed);
	printf("������������ ��������� ��������: ");
	scanf("%lg", &rangeOfMovement);
	printf("���������� ����: ");
	scanf("%d", &maxPassengerNumber);
	printf("������������ ��� ������: ");
	scanf("%lg", &maxBaggageWeight);
}

void SubjList::PrintTransportList()
{ 	
   	Node *p;  
   	int i = 0;
   	for (p = getHead(); p; p = p->getNext())
   	{
   		printf("%d. ", i);
   		((Base*)p)->Print();
   		i++;
	}             
   	printf("\n");
}

void SubjList::SortByRangeOfMovement()
{
	if(!getHead())
	{
		printf("������ ����.\n\n");
		return;
	}
		
  Base *i, *j; 
  Node *last;
  last = getTail();
  
  for (i = (Base*)getHead(); i->getNext(); i = (Base*)i->getNext())
  {
    for (j = (Base*)getHead(); j->getNext() && (Node*)j != last; j = (Base*)j->getNext())
    {
      if (j->rangeOfMovement > ((Base*)j->getNext())->rangeOfMovement)
      {
      		Node *temp;
      		temp = j->getNext();
      		Remove(j->getNext());
			Insert(temp, GetIndex((Node*)j));
      		if(temp == last)
      			last = (Node*)j;
      		if(j == i)
      			i = (Base*)temp;
      		else if(temp == (Node*)i)
      			i = j;
			j = (Base*)temp;
      }
  	}
  	last = last->getPrev();
  }
}

void SubjList::SortByMaxSpeed()
{
	if(!getHead())
	{
		printf("������ ����.\n\n");
		return;
	}
		
  	int i, j, n; 
  
  	n = Count();
    for (i = 0; i < n - 1; i++) 
        for (j = i + 1; j < n; j++)
        	if ((*this)[i] > (*this)[j])
            	Insert(Remove(j), i);
}

void SubjList::FindByMaxPassengerNumber()
{
	if(!getHead())
	{
		printf("������ ����.\n\n");
		return;
	}
		
	printf("������� ������� ����� ����: ");
	int num;
	scanf("%d", &num);
	
	Base *i;
	for (i = (Base*)getHead(); i; i = (Base*)i->getNext())
  	{
  		if(i->maxPassengerNumber == num)
  			i->Print();
  	}
}

void SubjList::FindByMaxWeight()
{
	if(!getHead())
	{
		printf("������ ����.\n\n");
		return;
	}
	
	int n, i;
	printf("������� ������� ����������� ���������� ���: ");
	double num;
	scanf("%lg", &num);
	
	n = Count();
        for (i = 0; i < n; i++)
        	if((*this)[i] == num)
            	(*this)[i].Print();
}

Base& SubjList::operator[](const int i)
{
	Base *item = (Base*)GetItem(i);
	
	if(!item)
		throw std::out_of_range("in SubjList operator []");
	
	return *item;
}

bool Base::operator < (const Base &b)
{
	return maxSpeed < b.maxSpeed;
}

bool Base::operator > (const Base &b)
{
	return maxSpeed > b.maxSpeed;
}

bool Base::operator == (const int num)
{
	return maxBaggageWeight == num;
}
