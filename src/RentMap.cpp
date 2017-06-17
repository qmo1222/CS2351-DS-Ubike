#include "RentMap.h"

// initial station distance
RentMap::RentMap(){
	int i, j;

	for (i=0; i<STATION_NUM; i++) {
		for (j=0; j<STATION_NUM; j++){
			string station1 = STATIONS[i];
			string station2 = STATIONS[j];
			this->distance[station1][station2];
		}
	}
}

// add path
void RentMap::paveRoad(string station1, string station2, int dist){
	this->distance[station1][station2] = dist;
	this->distance[station2][station1] = dist;
}

// calculate shortest path
void RentMap::shortDist(){

}