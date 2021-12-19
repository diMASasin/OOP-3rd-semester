#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"subj.h"

#define MAX_STRING_LENGTH 25

const char * const TypeName[]= 
            { "(unknown)", "Auto", "Aircraft", "Ship" };

typedef struct _Auto
{
	Node* prev;
	Node* next;
	
	ItemType type;
	char model[MAX_STRING_LENGTH];
	double fuelConsumption;
	double maxSpeed;
	double rangeOfMovement;
	int maxPassengerNumber;
	double maxBaggageWeight;
	
	char brand[MAX_STRING_LENGTH];
	char color[MAX_STRING_LENGTH];
} Auto;

typedef struct _Aircraft
{
	Node* prev;
	Node* next;
	
	ItemType type;
	char model[MAX_STRING_LENGTH];
	double fuelConsumption;
	double maxSpeed;
	double rangeOfMovement;
	int maxPassengerNumber;
	double maxBaggageWeight;
	
	int numberOfCrewMembers;
	int numberOfEngines;
	double maxHeight;

} Aircraft;

typedef struct _Ship
{
	Node* prev;
	Node* next;
	
	ItemType type;
	char model[MAX_STRING_LENGTH];
	double fuelConsumption;
	double maxSpeed;
	double rangeOfMovement;
	int maxPassengerNumber;
	double maxBaggageWeight;
	
	int numberOfCrewMembers;
	int numberOfEngines;
	char name[MAX_STRING_LENGTH];
	char homePort[MAX_STRING_LENGTH];
} Ship;

Base* Create(ItemType type)
{
   Base *p = NULL;
   switch (type)
   {
     	case itAuto:
        	p = malloc(sizeof(Auto));
        	break;
      	case itAircraft:  
      		p = malloc(sizeof(Aircraft));
      		break;
      	case itShip:
      		p = malloc(sizeof(Ship));
      		break;
   }
    
    if (p)
      p->type = type;
    
    return p;
}

void PrintTransportList(const List *l)
{ 
	if(!l || !l->head)
		return;
		
    Node *p;  
    int i = 0;
    for (p = l->head; p; p = p->next)
    {
    	printf("%d. ", i);
    	Print((Base*)p);
    	i++;
	}             
      printf("\n");
}

void PrintTransport(Base *p)
{
	if (!p)
	{
		printf("ERROR: null pointer!\n");
		return;
	}
		
	printf("Модель: %s\n", p->model);
	printf("Расход топлива: %lg\n", p->fuelConsumption);
	printf("Максимальная скорость: %lg\n", p->maxSpeed);
	printf("Максимальная дальность движения: %lg\n", p->rangeOfMovement);
	printf("Количество мест: %d\n", p->maxPassengerNumber);
	printf("Максимальный вес багажа: %lg\n", p->maxBaggageWeight);
}
  
void PrintAuto(Auto *p)
{
	if (!p)
	{
		printf("ERROR: null pointer!\n");
		return;
	}
		
	PrintTransport((Base*)p);
	printf("Бренд: %s\n", p->brand);
	printf("Цвет: %s\n\n", p->color);
}
  
void PrintAircraft(Aircraft *p)
{
	if (!p)
	{
		printf("ERROR: null pointer!\n");
		return;
	}
		
	PrintTransport((Base*)p);
	printf("Количество членов экипажа: %d\n", p->numberOfCrewMembers);
	printf("Количество двигателей: %d\n", p->numberOfEngines);
	printf("Максимальная высота: %lg\n\n", p->maxHeight);
}
  
void PrintShip(Ship *p)
{
	if (!p)
	{
		printf("ERROR: null pointer!\n");
		return;
	}
		
	PrintTransport((Base*)p);
	printf("Количество членов экипажа: %d\n", p->numberOfCrewMembers);
	printf("Количество двигателей: %d\n", p->numberOfEngines);
	printf("Название: %s\n", p->name);
	printf("Порт приписки: %s\n\n", p->homePort);
}

void InputTransport(Base* p)
{
	if (!p)
	{
		printf("ERROR: null pointer!\n");
		return;
	}
		
	printf("Модель: ");
	scanf("%s", p->model);
	printf("Расход топлива: ");
	p->fuelConsumption = InputDouble(NULL);
	printf("Максимальная скорость: ");
	p->maxSpeed = InputDouble();
	printf("Максимальная дальность движения: ");
	p->rangeOfMovement = InputDouble();
	printf("Количество мест: ");
	p->maxPassengerNumber = InputNumber();
	printf("Максимальный вес багажа: ");
	p->maxBaggageWeight = InputDouble();
}

void InputAuto(Auto *p)
{
	if (!p)
	{
		printf("ERROR: null pointer!\n");
		return;
	}
		
	p->type = 1;
	InputTransport((Base*)p);
	printf("Бренд: ");
	scanf("%s", p->brand);
	printf("Цвет: ");
	scanf("%s", p->color);
}
  
void InputAircraft(Aircraft *p)
{
	if (!p)
	{
		printf("ERROR: null pointer!\n");
		return;
	}
		
	p->type = 2;
	InputTransport((Base*)p);	
	printf("Количество членов экипажа: ");
	p->numberOfCrewMembers = InputNumber();
	printf("Количество двигателей: ");
	p->numberOfEngines = InputDouble();
	printf("Максимальная высота: ");
	p->maxHeight = InputDouble();
}
  
void InputShip(Ship *p)
{
	if (!p)
	{
		printf("ERROR: null pointer!\n");
		return;
	}
		
	p->type = 3;
	InputTransport((Base*)p);
	printf("Количество членов экипажа: ");
	p->numberOfCrewMembers = InputNumber();
	printf("Количество двигателей: ");
	p->numberOfEngines = InputDouble();
	printf("Название: ");
	scanf("%s", p->name);
	printf("Порт приписки: ");
	scanf("%s", p->homePort);
}

void Print(const Base *p)
{
	if (!p)
	{
		printf("ERROR: null pointer!\n");
		return;
	}

	printf("%s:\n", TypeName[(p->type>0 && p->type<=3)?p->type:0]);
    switch (p->type)
    {
    	case itAuto:
          	PrintAuto((Auto*)p);
          	break;
        case itAircraft:
          	PrintAircraft((Aircraft*)p);
          	break;
        case itShip:
          	PrintShip((Ship*)p);
          	break;
    }
}

void Input(Base *p)
{
	if (!p)
	{
		printf("ERROR: null pointer!\n");
		return;
	}

    switch (p->type)
    {
    	case itAuto:
          	InputAuto((Auto*)p);
          	break;
        case itAircraft:
          	InputAircraft((Aircraft*)p);
          	break;
        case itShip:
          	InputShip((Ship*)p);
          	break;
    }
}

int DoMenu(char *s[], int max)
{	
	int i;
    for (i = 1; i <= max; i++)
    	printf("%d. %s\n", i, s[i]);
    printf("> ");
    
    fflush(stdin);
    scanf("%d", &i);
    return i < 1 || i > max ? 0 : i;
}

void SortByRangeOfMovement(List *l)
{
	if(!l->head || !l)
	{
		printf("Список пуст.\n\n");
		return;
	}
		
  Base *i, *j; 
  Node *last;
  last = l->tail;
  
  for (i = (Base*)l->head; i->next; i = (Base*)i->next)
  {
    for (j = (Base*)l->head; j->next && (Node*)j != last; j = (Base*)j->next)
    {
      if (j->rangeOfMovement > ((Base*)j->next)->rangeOfMovement)
      {
      		Node *temp;
      		temp = j->next;
      		Remove(l, GetIndex(l, j->next));
			Insert(l, temp, GetIndex(l, (Node*)j));
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

void SortByMaxSpeed(List *l)
{
	if(!l->head || !l)
	{
		printf("Список пуст.\n\n");
		return;
	}
		
  Base *i, *j; 
  Node *last;
  last = l->tail;
  
  for (i = (Base*)l->head; i->next; i = (Base*)i->next)
  {
    for (j = (Base*)l->head; j->next && (Node*)j != last; j = (Base*)j->next)
    {
      if (j->maxSpeed > ((Base*)j->next)->maxSpeed)
      {
      		Node *temp;
      		temp = j->next;
      		Remove(l, GetIndex(l, j->next));
			Insert(l, temp, GetIndex(l, (Node*)j));
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

void FindByMaxPassengerNumber(const List *l)
{
	if(!l->head || !l)
	{
		printf("Список пуст.\n\n");
		return;
	}
		
	printf("Введите искомое число мест: ");
	int num = InputNumber();
	
	Base *i;
	for (i = (Base*)l->head; i; i = (Base*)i->next)
  	{
  		if(i->maxPassengerNumber == num)
  			Print(i);
  	}
}

void FindByMaxWight(const List *l)
{
	if(!l->head || !l)
	{
		printf("Список пуст.\n\n");
		return;
	}
		
	printf("Введите искомый максимально допустимый вес: ");
	int num = InputNumber();
	
	Base *i;
	for (i = (Base*)l->head; i; i = (Base*)i->next)
  	{
  		if(i->maxBaggageWeight == num)
  			Print(i);
  	}
}
