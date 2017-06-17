#ifndef RentMap_h
#define RentMap_h

#include <string>
#include <map>
#include "const.h"

using namespace std;

class RentMap
{
public:
    map<string, map<string, int>> distance;

    RentMap();
    void paveRoad(string station1, string station2, int dist);
    void shortDist();
};

#endif