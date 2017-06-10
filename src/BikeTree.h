#ifndef BikeTree_h
#define BikeTree_h

#include "Bike.h"

using namespace std;

class Node
{
public:
	Bike *bike;
	Node *left, *right;
};

class BikeTree
{
public:
	Node *root = NULL;

	void addBike(Bike *bike);
	void junkBike(string license);
	bool searchBike(string license);
	void deleteTree();
};

#endif