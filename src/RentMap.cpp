#include "RentMap.h"

// initial station rents
RentMap::RentMap(){
	int i, j;

	for (i=0; i<STATION_NUM; i++) {
		for (j=0; j<STATION_NUM; j++){
			string aStation = STATION_NAMES[i];
			string bStation = STATION_NAMES[j];
			this->rents[aStation][bStation];
		}
	}
}

// add path
void RentMap::paveRoad(string aStation, string bStation, int dist){
	this->rents[aStation][bStation] = dist;
	this->rents[bStation][aStation] = dist;
}

// calculate shortest path
void RentMap::shortDist(){

}