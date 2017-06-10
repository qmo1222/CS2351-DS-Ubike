#ifndef StationGraph_h
#define StationGraph_h

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Neighbor
{
public:
    string stationName;
    int dist;

    Neighbor();
    ~Neighbor();
};

class Station
{
public:
    string stationName;
    vector<Neighbor> neighbors;

    Station();
    ~Station();
};

class StationGraph
{
public:
    vector<Station> graph;

    void addRoad(string aStation, string bStation, int dist);
    int shortDist(string aStation, string bStation);
};

#endif