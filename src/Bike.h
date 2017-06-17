#ifndef Bike_h
#define Bike_h

#include <string>

using namespace std;

class Bike
{
public:
	// which type of bike
	string bikeClass;
	// license name
	string license;
	// 0:free, 1:rented
	bool status;
	// total miles
	int mile;
	// at which station
	string station;
};


#endif