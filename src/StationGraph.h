#ifndef STATIONGRAPH_H
#define STATIONGRAPH_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

enum StationType {
    Danshui = 0, Hongshulin = 1, Beitou = 2, Shilin = 3,
    Zhongshan = 4, Xinpu = 5, Ximen = 6, Liuzhangli = 7,
    Muzha = 8, Guting = 9, Gongguan = 10, Jingmei = 11
};

class Neighbor
{
public:
    StationType stationName;
    int dist;

    Neighbor();
    ~Neighbor();
};

class Station
{
public:
    StationType stationName;
    vector<Neighbor> neighbors;

    Vertex();
    ~Vertex();
};


class StationGraph
{
public:
    vector<Vertex> graph;
};

#endif