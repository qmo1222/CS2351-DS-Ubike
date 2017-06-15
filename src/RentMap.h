#ifndef RentMap_h
#define RentMap_h

#include <string>
#include <map>
#include "const.h"

using namespace std;

class RentMap
{
public:
    map<string, map<string, int>> rents;

    RentMap();
    void paveRoad(string aStation, string bStation, int dist);
    void shortDist();
};

#endif