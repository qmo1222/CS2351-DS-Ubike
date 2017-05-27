#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include "DataType.h"
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

    // read map
    string s, t, dist;
    while(mapIn >> s >> t >> dist) {
        // ...
    }

    // testCase parser
    string cmd;
    string message;
    while(testCaseIn >> cmd) {
        if (cmd == "NewBike") {
            string bikeClass, license, mile, stationName;
            testCaseIn >> bikeClass >> license >> mile >> stationName;
        }
        else if (cmd == "JunkIt") {
            string license;
            testCaseIn >> license;
        }
        else if (cmd == "Rent") {
            string stationName, bikeClass;
            testCaseIn >> stationName >> bikeClass;
        }
        else if (cmd == "Returns") {
            string stationName, license, mile, bikeClass;
            testCaseIn >> stationName >> license >> bikeClass;
        }
        else if (cmd == "Trans") {
            string stationName, license;
            testCaseIn >> stationName >> license;
        }
        else if (cmd == "Inquire") {
            string license;
            testCaseIn >> license;
        }
        else if (cmd == "StationReport") {
            string stationName;
            testCaseIn >> stationName;
        }
        else if (cmd == "UbikeReport") {
        }
        else if (cmd == "NetSearch") {
            string stationName;
            testCaseIn >> stationName;
        }
        else if (cmd == "BReport") {
        }
        else {
            cout << "Command not found" << endl;
        }

        fileOut << message <<endl;
    }

    return 0;
}