#include"list.h"

typedef enum _ItemType{None, itAuto, itAircraft, itShip} ItemType;
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
	
	protected:
	ItemType type;
	
	public:
	Base(List* list);
	void Input();
	void BaseInput();
	void Print();
	void BasePrint();
	Base* Create(ItemType type, List *list);
};

class Auto : public Base
{
	private:
	char brand[MAX_STRING_LENGTH];
	char color[MAX_STRING_LENGTH];
	
	public:
	Auto(List* list);
	void Print();
	void Input();
};

class Aircraft : public Base
{
	private:
	int numberOfCrewMembers;
	int numberOfEngines;
	double maxHeight;
	
	public:
	Aircraft(List* list);
	void Print();
	void Input();
};

class Ship : public Base
{
	private:
	int numberOfCrewMembers;
	int numberOfEngines;
	char name[MAX_STRING_LENGTH];
	char homePort[MAX_STRING_LENGTH];
	
	public:
	Ship(List* list);
	void Print();
	void Input();
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
