#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>

#include "UBikeSys.h"
// #include "DataType.h"

using namespace std;

ifstream testCaseIn;
ifstream mapIn;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "arguments are incorrect" <<endl;
        return 0;
    }
    // argv[1] -> transaction file
    // argv[2] -> map file
    // argv[3] -> output file
    testCaseIn.open(argv[1], ifstream::in);
    mapIn.open(argv[2], ifstream::in);

    UBikeSys ub(argv[3]);

    // read map
    string s, t;
    int dist;
    while(mapIn >> s >> t >> dist) {
    	// add edges
        ub.price.paveRoad(s, t, dist);
    }
    //calculate shortest path
    ub.price.shortDist();

    // testCase parser
    string cmd;
    string message;
    while(testCaseIn >> cmd) {
        if (cmd == "NewBike") {
            string bikeClass, license, station;
            int mile;
            testCaseIn >> bikeClass >> license >> mile >> station;
            ub.newBike(bikeClass, license, mile, station);
        }
        else if (cmd == "JunkIt") {
            string license;
            testCaseIn >> license;
            ub.junkIt(license);
        }
        else if (cmd == "Rent") {
            string station, bikeClass;
            testCaseIn >> station >> bikeClass;
            ub.rent(station, bikeClass);
        }
        else if (cmd == "Returns") {
            string station, license;
            int mile;
            testCaseIn >> station >> license >> mile;
            ub.returns(station, license, mile);
        }
        else if (cmd == "Trans") {
            string station, license;
            testCaseIn >> station >> license;
            ub.trans(station, license);
        }
        else if (cmd == "Inquire") {
            string license;
            testCaseIn >> license;
            ub.inquire(license);
        }
        else if (cmd == "StationReport") {
            string station;
            testCaseIn >> station;
            ub.stationReport(station);
        }
        else if (cmd == "UbikeReport") {
        	ub.uBikeReport();
        }
        else if (cmd == "NetSearch") {
            string station;
            testCaseIn >> station;
            ub.netSearch(station);
        }
        else if (cmd == "BReport") {
        	ub.bReport();
        }
        else {
            cout << "Command not found" << endl;
        }

    }

    ub.fileOut.close();
    mapIn.close();
    testCaseIn.close();

    return 0;
}