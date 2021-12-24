#include"list.h"

typedef enum _ItemType { None, itAuto, itAircraft, itShip } ItemType;
const char* const TypeName[4] = { "(unknown)", "Auto", "Aircraft", "Ship" };

class Base : public Node
{
	friend class SubjList;

private:
	char model[MAX_STRING_LENGTH];
	double fuelConsumption;
	double maxSpeed;
	double rangeOfMovement;
	int maxPassengerNumber;
	double maxBaggageWeight;

public:
	virtual void Input();
	virtual void Print();
	Base* Create(ItemType type, List* list);
	virtual const char* const GetType() = 0;
};

class SubjList : public List
{
public:
	void PrintTransportList();
	void SortByRangeOfMovement();
	void SortByMaxSpeed();
	void FindByMaxPassengerNumber();
	void FindByMaxWight();
	void Print(ItemType);
};
