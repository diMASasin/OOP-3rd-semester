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
	void Input();
	void BaseInput();
	void Print();
	void BasePrint();
	Base* Create(ItemType type, List *list);
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
