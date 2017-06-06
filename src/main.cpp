#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>

#include "UBikeSys.h"
// #include "DataType.h"

using namespace std;

ofstream fileOut;
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
    fileOut.open(argv[3], ifstream::out);
    mapIn.open(argv[2], ifstream::in);
    testCaseIn.open(argv[1], ifstream::in);

    UBikeSys ub;

    // read map
    string s, t;
    int dist;
    while(mapIn >> s >> t >> dist) {
        ub.buildStation(s, t, dist);
    }

    // testCase parser
    string cmd;
    string message;
    while(testCaseIn >> cmd) {
        if (cmd == "NewBike") {
            string bikeClass, license, stationName;
            int mile;
            testCaseIn >> bikeClass >> license >> mile >> stationName;
            ub.newBike(bikeClass, license, mile, stationName);
        }
        else if (cmd == "JunkIt") {
            string license;
            testCaseIn >> license;
            ub.junkIt(license);
        }
        else if (cmd == "Rent") {
            string stationName, bikeClass;
            testCaseIn >> stationName >> bikeClass;
            ub.rent(stationName, bikeClass);
        }
        else if (cmd == "Returns") {
            string stationName, license;
            int mile;
            testCaseIn >> stationName >> license >> mile;
            ub.returns(stationName, license, mile);
        }
        else if (cmd == "Trans") {
            string stationName, license;
            testCaseIn >> stationName >> license;
            ub.trans(stationName, license);
        }
        else if (cmd == "Inquire") {
            string license;
            testCaseIn >> license;
            ub.inquire(license);
        }
        else if (cmd == "StationReport") {
            string stationName;
            testCaseIn >> stationName;
            ub.stationReport(stationName);
        }
        else if (cmd == "UbikeReport") {
        	ub.uBikeReport();
        }
        else if (cmd == "NetSearch") {
            string stationName;
            testCaseIn >> stationName;
            ub.netSearch(stationName);
        }
        else if (cmd == "BReport") {
        	ub.bReport();
        }
        else {
            cout << "Command not found" << endl;
        }

        fileOut << message <<endl;
    }

    fileOut.close();
    mapIn.close();
    testCaseIn.close();

    return 0;
}