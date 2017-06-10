#ifndef StationData_h
#define StationData_h

#include <array>
#include <string>
#include <map>
#include "Bike.h"

using namespace std;

class BikeHeap
{
public:
	Bike *heap;

	void addBike(Bike* bike);
	void junkBike(string license);
};

class StationData
{
public:
	map<string, BikeHeap> bikeClassHeap;
	map<string, int> net;
};

#endif