#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

void Base::BasePrint()
{		
	printf("������: %s\n", model);
	printf("������ �������: %lg\n", fuelConsumption);
	printf("������������ ��������: %lg\n", maxSpeed);
	printf("������������ ��������� ��������: %lg\n", rangeOfMovement);
	printf("���������� ����: %d\n", maxPassengerNumber);
	printf("������������ ��� ������: %lg\n", maxBaggageWeight);
}
  
void Auto::Print()
{	
	Base::BasePrint();
	printf("�����: %s\n", brand);
	printf("����: %s\n\n", color);
}
  
void Aircraft::Print()
{	
	Base::BasePrint();
	printf("���������� ������ �������: %d\n", numberOfCrewMembers);
	printf("���������� ����������: %d\n", numberOfEngines);
	printf("������������ ������: %lg\n\n", maxHeight);
}
  
void Ship::Print()
{
	Base::BasePrint();	
	printf("���������� ������ �������: %d\n", numberOfCrewMembers);
	printf("���������� ����������: %d\n", numberOfEngines);
	printf("��������: %s\n", name);
	printf("���� ��������: %s\n\n", homePort);
}

void Base::Print()
{
	printf("%s:\n", TypeName[(this->type>0 && this->type<=3)?this->type:0]);
    switch (this->type)
    {
    	case itAuto:
          	((Auto*)this)->Print();
          	break;
        case itAircraft:
          	((Aircraft*)this)->Print();
          	break;
        case itShip:
          	((Ship*)this)->Print();
          	break;
    }
}

Base* Base::Create(ItemType type, List *list)
{
	if(!list)
    	return NULL;
    		
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
      		printf("������!\n");
      		return NULL;
   }
    
    p->type = type;
    return p;
}

void Base::Input()
{
	if(!this)
		return;
		
    switch (this->type)
    {
    	case itAuto:
          	((Auto*)this)->Input();
          	break;
        case itAircraft:
          	((Aircraft*)this)->Input();
          	break;
        case itShip:
          	((Ship*)this)->Input();
          	break;
        default:
        	printf("������!\n");
        	break;
    }
}

void Base::BaseInput()
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
	Base::BaseInput();
	type = (ItemType)1;
	printf("�����: ");
	scanf("%s", brand);
	printf("����: ");
	scanf("%s", color);
}
  
void Aircraft::Input()
{
	Base::BaseInput();	
	type = (ItemType)2;
	printf("���������� ������ �������: ");
	numberOfCrewMembers = InputNumber();
	printf("���������� ����������: ");
	numberOfEngines = InputDouble();
	printf("������������ ������: ");
	maxHeight = InputDouble();
}
  
void Ship::Input()
{
	Base::BaseInput();
	type = (ItemType)3;
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
		
  Base *i, *j; 
  Node *last;
  last = tail;
  
  for (i = (Base*)head; i->next; i = (Base*)i->next)
  {
    for (j = (Base*)head; j->next && (Node*)j != last; j = (Base*)j->next)
    {
      if (j->maxSpeed > ((Base*)j->next)->maxSpeed)
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

void SubjList::FindByMaxWight()
{
	if(!head)
	{
		printf("������ ����.\n\n");
		return;
	}
		
	printf("������� ������� ����������� ���������� ���: ");
	int num = InputNumber();
	
	Base *i;
	for (i = (Base*)head; i; i = (Base*)i->next)
  	{
  		if(i->maxBaggageWeight == num)
  			i->Print();
  	}
}
