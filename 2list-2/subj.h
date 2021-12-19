#include"list.h"

enum ObjectTypes
{
	Auto,
	Aircraft,
	Ship
};

typedef struct _Transport Transport;
struct _Transport
{
	Node node;
	char model[];
	char type[];
	double fuel—onsumption;
	double maxSpeed;
	double rangeOfMovement;
	int maxPassengerNumber;
	double maxBaggageWeight;
};

void Input(Transport *transport);
void Print(Transport *transport);
void PrintList(const List list);
void SortBySpeed(List *list);
void SortByRangeOfMovement(List *list);
void SearchByNumberOfSeats(List *list);
void SearchByBaggageWeight(List *list);
int Find(const List list, Transport *transport);
Transport* Create(enum ObjectTypes);
