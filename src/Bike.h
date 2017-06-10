#ifndef Bike_h
#define Bike_h

#include <string>

using namespace std;

class Bike
{
public:
	// license name
	string license;
	// 0:free, 1:rented
	bool status;
	// total miles
	int mileage;
	// at which station
	string stationName;
	// which type of bike
	string bikeClass;
};


#endif