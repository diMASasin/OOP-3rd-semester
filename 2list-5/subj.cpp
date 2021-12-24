#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"subj.h"                        

class Auto : public Base
{
private:
	char brand[MAX_STRING_LENGTH];
	char color[MAX_STRING_LENGTH];

public:
	void Print()
	{
		Base::BasePrint();
		printf("Бренд: %s\n", brand);
		printf("Цвет: %s\n\n", color);
	}

	void Input()
	{
		Base::BaseInput();
		printf("Бренд: ");
		scanf("%s", brand);
		printf("Цвет: ");
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
	void Print()
	{
		Base::BasePrint();
		printf("Количество членов экипажа: %d\n", numberOfCrewMembers);
		printf("Количество двигателей: %d\n", numberOfEngines);
		printf("Максимальная высота: %lg\n\n", maxHeight);
	}

	void Input()
	{
		Base::BaseInput();
		printf("Количество членов экипажа: ");
		scanf("%d", &numberOfCrewMembers);
		printf("Количество двигателей: ");
		scanf("%d", &numberOfEngines);
		printf("Максимальная высота: ");
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
	void Print()
	{
		Base::BasePrint();
		printf("Количество членов экипажа: %d\n", numberOfCrewMembers);
		printf("Количество двигателей: %d\n", numberOfEngines);
		printf("Название: %s\n", name);
		printf("Порт приписки: %s\n\n", homePort);
	}

	void Input()
	{
		Base::BaseInput();
		printf("Количество членов экипажа: ");
		scanf("%d", &numberOfCrewMembers);
		printf("Количество двигателей: ");
		scanf("%d", &numberOfEngines);
		printf("Название: ");
		scanf("%s", name);
		printf("Порт приписки: ");
		scanf("%s", homePort);
	}
};

void Base::BasePrint()
{
	printf("Модель: %s\n", model);
	printf("Расход топлива: %lg\n", fuelConsumption);
	printf("Максимальная скорость: %lg\n", maxSpeed);
	printf("Максимальная дальность движения: %lg\n", rangeOfMovement);
	printf("Количество мест: %d\n", maxPassengerNumber);
	printf("Максимальный вес багажа: %lg\n", maxBaggageWeight);
}

void Base::Print()
{
	printf("%s:\n", TypeName[(this->type > 0 && this->type <= 3) ? this->type : 0]);
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

Base* Base::Create(ItemType type, List* list)
{
	if (!list)
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
		printf("Ошибка!\n");
		return NULL;
	}

	p->type = type;
	return p;
}

void Base::Input()
{
	if (!this)
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
	scanf("%lg", &fuelConsumption);
	printf("Максимальная скорость: ");
	scanf("%lg", &maxSpeed);
	printf("Максимальная дальность движения: ");
	scanf("%lg", &rangeOfMovement);
	printf("Количество мест: ");
	scanf("%d", &maxPassengerNumber);
	printf("Максимальный вес багажа: ");
	scanf("%lg", &maxBaggageWeight);
}

void SubjList::PrintTransportList()
{
	Node* p;
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
	if (!getHead())
	{
		printf("Список пуст.\n\n");
		return;
	}

	Base* i, * j;
	Node* last;
	last = getTail();

	for (i = (Base*)getHead(); i->getNext(); i = (Base*)i->getNext())
	{
		for (j = (Base*)getHead(); j->getNext() && (Node*)j != last; j = (Base*)j->getNext())
		{
			if (j->rangeOfMovement > ((Base*)j->getNext())->rangeOfMovement)
			{
				Node* temp;
				temp = j->getNext();
				Remove(j->getNext());
				Insert(temp, GetIndex((Node*)j));
				if (temp == last)
					last = (Node*)j;
				if (j == i)
					i = (Base*)temp;
				else if (temp == (Node*)i)
					i = j;
				j = (Base*)temp;
			}
		}
		last = last->getPrev();
	}
}

void SubjList::SortByMaxSpeed()
{
	if (!getHead())
	{
		printf("Список пуст.\n\n");
		return;
	}

	Base* i, * j;
	Node* last;
	last = getTail();

	for (i = (Base*)getHead(); i->getNext(); i = (Base*)i->getNext())
	{
		for (j = (Base*)getHead(); j->getNext() && (Node*)j != last; j = (Base*)j->getNext())
		{
			if (j->maxSpeed > ((Base*)j->getNext())->maxSpeed)
			{
				Node* temp;
				temp = j->getNext();
				Remove(j->getNext());
				Insert(temp, GetIndex((Node*)j));
				if (temp == last)
					last = (Node*)j;
				if (j == i)
					i = (Base*)temp;
				else if (temp == (Node*)i)
					i = j;
				j = (Base*)temp;
			}
		}
		last = last->getPrev();
	}
}

void SubjList::FindByMaxPassengerNumber()
{
	if (!getHead())
	{
		printf("Список пуст.\n\n");
		return;
	}

	printf("Введите искомое число мест: ");
	int num;
	scanf("%d", &num);

	Base* i;
	for (i = (Base*)getHead(); i; i = (Base*)i->getNext())
	{
		if (i->maxPassengerNumber == num)
			i->Print();
	}
}

void SubjList::FindByMaxWight()
{
	if (!getHead())
	{
		printf("Список пуст.\n\n");
		return;
	}

	printf("Введите искомый максимально допустимый вес: ");
	int num;
	scanf("%d", &num);

	Base* i;
	for (i = (Base*)getHead(); i; i = (Base*)i->getNext())
	{
		if (i->maxBaggageWeight == num)
			i->Print();
	}
}
