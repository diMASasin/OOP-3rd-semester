#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"subj.h"                        

Base::Base(List* list) : Node(list){}
Auto::Auto(List* list) : Base(list){}
Aircraft::Aircraft(List* list) : Base(list){}
Ship::Ship(List* list) : Base(list){}

void Base::BasePrint()
{		
	printf("Модель: %s\n", model);
	printf("Расход топлива: %lg\n", fuelConsumption);
	printf("Максимальная скорость: %lg\n", maxSpeed);
	printf("Максимальная дальность движения: %lg\n", rangeOfMovement);
	printf("Количество мест: %d\n", maxPassengerNumber);
	printf("Максимальный вес багажа: %lg\n", maxBaggageWeight);
}
  
void Auto::Print()
{	
	Base::BasePrint();
	printf("Бренд: %s\n", brand);
	printf("Цвет: %s\n\n", color);
}
  
void Aircraft::Print()
{	
	Base::BasePrint();
	printf("Количество членов экипажа: %d\n", numberOfCrewMembers);
	printf("Количество двигателей: %d\n", numberOfEngines);
	printf("Максимальная высота: %lg\n\n", maxHeight);
}
  
void Ship::Print()
{
	Base::BasePrint();	
	printf("Количество членов экипажа: %d\n", numberOfCrewMembers);
	printf("Количество двигателей: %d\n", numberOfEngines);
	printf("Название: %s\n", name);
	printf("Порт приписки: %s\n\n", homePort);
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
      		printf("Ошибка!\n");
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
        	printf("Ошибка!\n");
        	break;
    }
}

void Base::BaseInput()
{	
	printf("Модель: ");
	scanf("%s", model);
	printf("Расход топлива: ");
	fuelConsumption = InputDouble();
	printf("Максимальная скорость: ");
	maxSpeed = InputDouble();
	printf("Максимальная дальность движения: ");
	rangeOfMovement = InputDouble();
	printf("Количество мест: ");
	maxPassengerNumber = InputNumber();
	printf("Максимальный вес багажа: ");
	maxBaggageWeight = InputDouble();
}

void Auto::Input()
{
	Base::BaseInput();
	type = (ItemType)1;
	printf("Бренд: ");
	scanf("%s", brand);
	printf("Цвет: ");
	scanf("%s", color);
}
  
void Aircraft::Input()
{
	Base::BaseInput();	
	type = (ItemType)2;
	printf("Количество членов экипажа: ");
	numberOfCrewMembers = InputNumber();
	printf("Количество двигателей: ");
	numberOfEngines = InputDouble();
	printf("Максимальная высота: ");
	maxHeight = InputDouble();
}
  
void Ship::Input()
{
	Base::BaseInput();
	type = (ItemType)3;
	printf("Количество членов экипажа: ");
	numberOfCrewMembers = InputNumber();
	printf("Количество двигателей: ");
	numberOfEngines = InputDouble();
	printf("Название: ");
	scanf("%s", name);
	printf("Порт приписки: ");
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
		printf("Список пуст.\n\n");
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
		printf("Список пуст.\n\n");
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
		printf("Список пуст.\n\n");
		return;
	}
		
	printf("Введите искомое число мест: ");
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
		printf("Список пуст.\n\n");
		return;
	}
		
	printf("Введите искомый максимально допустимый вес: ");
	int num = InputNumber();
	
	Base *i;
	for (i = (Base*)head; i; i = (Base*)i->next)
  	{
  		if(i->maxBaggageWeight == num)
  			i->Print();
  	}
}
