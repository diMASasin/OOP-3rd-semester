#include"list.h"

#define MAX_STRING_LENGTH 25

typedef enum _ItemType{None, itAuto, itAircraft, itShip} ItemType;
            
typedef struct _Base
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
} Base;

void Input(Base *base);
void Print(const Base *base);
void PrintTransportList(const List *l);
void SortBySpeed(List *list);
void SortByRangeOfMovement(List *list);
void FindByMaxPassengerNumber(const List *l);
void FindByMaxWight(const List *l);
Base* Create(ItemType type);
