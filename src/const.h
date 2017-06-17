#ifndef Table_h
#define Table_h

#include <string>
#include <map>

using namespace std;

const int CLASS_NUM = 4;
const string CLASSES[] = {
	"Electric", "Lady", "Road", "Hybrid"
};
const string RENTED = "Rented";

const int STATION_NUM = 12;
const string STATIONS[] = {
   "Danshui", "Hongshulin", "Beitou", "Shilin",
   "Zhongshan", "Xinpu", "Ximen", "Liuzhangli",
    "Muzha", "Guting", "Gongguan", "Jingmei"
};

const map<string, int> ORIGIN_PRICE = {
	{"Electric", 40},
	{"Lady", 30},
	{"Road", 20},
	{"Hybrid", 25}
};

const map<string, int> DISCOUNT_PRICE = {
	{"Electric", 30},
	{"Lady", 25},
	{"Road", 15},
	{"Hybrid", 20}
};

#endif