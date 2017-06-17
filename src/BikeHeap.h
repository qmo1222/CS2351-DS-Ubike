#ifndef Station_h
#define Station_h

#include <vector>
#include <string>
#include "Bike.h"

using namespace std;

class BikeHeap
{
public:
	vector<Bike*> heap;

	void addBike(Bike *bike);
	void junkBike(string license);
	Bike* rentBike();
	vector<Bike*> showBike();
};

#endif