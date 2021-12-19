#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdexcept>
#include"subj.h"                        

Base::Base(List* list) : Node(list)
{
}

Auto::Auto(List* list) : Base(list)
{	
}

Aircraft::Aircraft(List* list) : Base(list)
{	
}

Ship::Ship(List* list) : Base(list)
{
}

const char* const Auto::GetType()
{
	return "Auto";
}

const char* const Aircraft::GetType()
{
	return "Aircraft";
}

const char* const Ship::GetType()
{
	return "Ship";
}

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
  
void Auto::Print()
{	
	Base::Print();
	printf("�����: %s\n", brand);
	printf("����: %s\n\n", color);
}
  
void Aircraft::Print()
{	
	Base::Print();
	printf("���������� ������ �������: %d\n", numberOfCrewMembers);
	printf("���������� ����������: %d\n", numberOfEngines);
	printf("������������ ������: %lg\n\n", maxHeight);
}
  
void Ship::Print()
{
	Base::Print();	
	printf("���������� ������ �������: %d\n", numberOfCrewMembers);
	printf("���������� ����������: %d\n", numberOfEngines);
	printf("��������: %s\n", name);
	printf("���� ��������: %s\n\n", homePort);
}

Base* Base::Create(ItemType type, List *list)
{
	if(!list)
	{
		printf("������ �� ������.\n");
		system("pause");
		return NULL;
	}
    		
	Base* p;
   switch (type)
   {
     	case itAuto:
        	p = new Auto(list);
        	break;
      	case itAircraft:  
      		p = new Aircraft(list);
      		break;
      	case itShip:
      		p = new Ship(list);
      		break;
      	default:
      		printf("������ ���� ������!\n");
      		system("pause");
      		return NULL;
   }
    return p;
}

void Base::Input()
{	
	printf("������: ");
	scanf("%s", model);
	printf("������ �������: ");
	fuelConsumption = InputDouble();
	printf("������������ ��������: ");
	maxSpeed = InputDouble();
	printf("������������ ��������� ��������: ");
	rangeOfMovement = InputDouble();
	printf("���������� ����: ");
	maxPassengerNumber = InputNumber();
	printf("������������ ��� ������: ");
	maxBaggageWeight = InputDouble();
}

void Auto::Input()
{
	Base::Input();
	printf("�����: ");
	scanf("%s", brand);
	printf("����: ");
	scanf("%s", color);
}
  
void Aircraft::Input()
{
	Base::Input();	
	printf("���������� ������ �������: ");
	numberOfCrewMembers = InputNumber();
	printf("���������� ����������: ");
	numberOfEngines = InputDouble();
	printf("������������ ������: ");
	maxHeight = InputDouble();
}
  
void Ship::Input()
{
	Base::Input();
	printf("���������� ������ �������: ");
	numberOfCrewMembers = InputNumber();
	printf("���������� ����������: ");
	numberOfEngines = InputDouble();
	printf("��������: ");
	scanf("%s", name);
	printf("���� ��������: ");
	scanf("%s", homePort);
}

void SubjList::PrintTransportList()
{ 	
   	Node *p;  
   	int i = 0;
   	for (p = head; p; p = p->next)
   	{
   		printf("%d. ", i);
   		((Base*)p)->Print();
   		i++;
	}             
   	printf("\n");
}

void SubjList::SortByRangeOfMovement()
{
	if(!head)
	{
		printf("������ ����.\n\n");
		return;
	}
		
  Base *i, *j; 
  Node *last;
  last = tail;
  
  for (i = (Base*)head; i->next; i = (Base*)i->next)
  {
    for (j = (Base*)head; j->next && (Node*)j != last; j = (Base*)j->next)
    {
      if (j->rangeOfMovement > ((Base*)j->next)->rangeOfMovement)
      {
      		Node *temp;
      		temp = j->next;
      		Remove(GetIndex(j->next));
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
  	last = last->prev;
  }
}

void SubjList::SortByMaxSpeed()
{
	if(!head)
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
	if(!head)
	{
		printf("������ ����.\n\n");
		return;
	}
		
	printf("������� ������� ����� ����: ");
	int num = InputNumber();
	
	Base *i;
	for (i = (Base*)head; i; i = (Base*)i->next)
  	{
  		if(i->maxPassengerNumber == num)
  			i->Print();
  	}
}

void SubjList::FindByMaxWeight()
{
	if(!head)
	{
		printf("������ ����.\n\n");
		return;
	}
	
	int n, i;
	printf("������� ������� ����������� ���������� ���: ");
	int num = InputNumber();
	
	n = Count();
        for (i = 0; i < n; i++)
        	if((*this)[i].maxBaggageWeight == num)
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

