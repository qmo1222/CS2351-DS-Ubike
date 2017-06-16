#ifndef UBikeSys_h
#define UBikeSys_h

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <iomanip>

#include "RentMap.h"
#include "BikeTree.h"
#include "BikeHeap.h"
#include "Bike.h"

using namespace std;

class UBikeSys
{
public:
	ofstream fileOut;

	RentMap price;
	BikeTree bikeOwn;
	map<string, map<string, BikeHeap>> stationInfo;
	map<string, int> net;

	UBikeSys(string fileName);
	// add new bike to company
    void newBike(string bikeClass, string license, int mile, string station);
    // remove bike from company
    void junkIt(string license);
    // rent the bike
    void rent(string station, string bikeClass);
    // return bike
    void returns(string station, string license, int mile);
    // transfer bike to other station
    void trans(string station, string license);
	// inquire certain bike
	void inquire(string license);
	// report certain station
	void stationReport(string station);
	// report all bikes info
	void uBikeReport();
	// report money earn by the station
	void netSearch(string station);
	// print binary search tree
	void bReport();
};

#endif