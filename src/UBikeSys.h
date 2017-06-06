#ifndef UBikeSys_h
#define UBikeSys_h

#include <iostream>
#include <string>

#include "StationGraph.h"

using namespace std;

class UBikeSys
{
public:
	// UBikeSys(); // constructor
	StationGraph mrt; // graph

	// build the station graph
	void buildStation(string s, string t, int dist);
	// add new bike to company
    void newBike(string bikeClass, string license, int mile, string stationName);
    // remove bike from company
    void junkIt(string license);
    // rent the bike
    void rent(string stationName, string bikeClass);
    // return bike
    void returns(string stationName, string license, int mile);
    // transfer bike to other stationName
    void trans(string stationName, string license);
	// inquire certain bike
	void inquire(string license);
	// report certain stationName
	void stationReport(string stationName);
	// report all bikes info
	void uBikeReport();
	// report money earn by the stationName
	void netSearch(string stationName);
	// print binary search tree
	void bReport();
};

#endif