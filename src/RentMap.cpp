#include "RentMap.h"


// initial station this->distance
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
	//fill the unexist path this->distance with 100000
	for(int i=0; i<STATION_NUM; i++){
		for(int j=0; j<STATION_NUM; j++){
			if(this->distance.at(STATIONS[i]).at(STATIONS[j])==0)
                if(i != j) this->distance.at(STATIONS[i]).at(STATIONS[j]) = 100000;	
		}
	}


    for(int k=0; k<STATION_NUM; k++) {
        for(int i=0; i<STATION_NUM; i++) {
            for(int j=0; j<STATION_NUM; j++) {
                if( this->distance.at(STATIONS[i]).at(STATIONS[k]) + this->distance.at(STATIONS[k]).at(STATIONS[j])
                < this->distance.at(STATIONS[i]).at(STATIONS[j]) )
                this->distance.at(STATIONS[i]).at(STATIONS[j])=
                    this->distance.at(STATIONS[i]).at(STATIONS[k]) + this->distance.at(STATIONS[k]).at(STATIONS[j]);
            } 
        }
    }
}