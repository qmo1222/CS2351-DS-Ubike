#ifndef Station_h
#define Station_h

#include <array>
#include <string>
#include "Bike.h"

using namespace std;

class BikeHeap
{
public:
	Bike *heap;

	void addBike(Bike* bike);
	void junkBike(string license);
};

#endif