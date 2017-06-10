#ifndef Table_h
#define Table_h

#include <string>
#include <map>

using namespace std;

const string HeapNames[] = {
	"Electric", "Lady", "Road", "Hybrid", "Rented"
};

const string StationNames[] = {
   "Danshui", "Hongshulin", "Beitou", "Shilin",
   "Zhongshan", "Xinpu", "Ximen", "Liuzhangli",
    "Muzha", "Guting", "Gongguan", "Jingmei"
};

const map<string, int> originPrice = {
	{"Electric", 40},
	{"Lady", 30},
	{"Road", 20},
	{"Hybrid", 25}
};

const map<string, int> discountPrice = {
	{"Electric", 30},
	{"Lady", 25},
	{"Road", 15},
	{"Hybrid", 20}
};

#endif