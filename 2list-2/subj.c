#include<stdio.h>
#include"subj.h"

struct Auto
{
	Transport transport;
	char brand[];
	char color[];
};

struct Aircraft
{
	Transport transport;
	char name[];
	char homePort[];
};

struct Ship
{
	Transport transport;
	int numberOfCrewMembers;
	int numberOfEngines;
};

void InputAuto(Auto *auto);
void InputAircraft(Aircraft *aircraft);
void InputShip(Ship *ship);
void PrintAuto(Auto *auto);
void PrintAircraft(Aircraft *aircraft);
void PrintShip(Ship *Ship);

void Input(Transport *transport)
{
	scanf("%lg", transport->maxBaggageWeight);
	scanf("%d", transport->maxPassengerNumber);
	scanf("%lg", transport->maxSpeed);
	scanf("%lg", transport->model);
}
