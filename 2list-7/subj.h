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
	
	public:
	Base(List* list);
	virtual void Input();
	virtual void Print();
	Base* Create(ItemType type, List *list);
	virtual const char* const GetType() = 0;
	bool operator < (const Base &b);
	bool operator > (const Base &b);
};

class Auto : public Base
{
	private:
	char brand[MAX_STRING_LENGTH];
	char color[MAX_STRING_LENGTH];
	
	public:
	Auto(List* list);
	virtual void Print();
	virtual void Input();
	virtual const char* const GetType();
};

class Aircraft : public Base
{
	private:
	int numberOfCrewMembers;
	int numberOfEngines;
	double maxHeight;
	
	public:
	Aircraft(List* list);
	virtual void Print();
	virtual void Input();
	virtual const char* const GetType();
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
	virtual void Print();
	virtual void Input();
	virtual const char* const GetType();
};

class SubjList : public List
{	
	public:
	void PrintTransportList();
	void SortByRangeOfMovement();
	void SortByMaxSpeed();
	void FindByMaxPassengerNumber();
	void FindByMaxWeight();
	void Print(ItemType);
	Base& operator[](const int i);
};
