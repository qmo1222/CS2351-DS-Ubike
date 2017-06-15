#include "UBikeSys.h"

UBikeSys::UBikeSys(){
	int i, j;

	for (i=0; i<STATION_NUM; i++) {
		for (j=0; j<HEAP_NUM; j++){
			string stationName = STATION_NAMES[i];
			string bikeClass = HEAP_NAMES[j];
			this->stationInfo[stationName][bikeClass];
		}
	}
}

// add new bike to company
void UBikeSys::newBike(string bikeClass, string license, int mile, string stationName){
	cout<<"newBike function still making"<<endl;
}
// remove bike from company
void UBikeSys::junkIt(string license){
	cout<<"junkIt function still making"<<endl;
}
// rent the bike
void UBikeSys::rent(string stationName, string bikeClass){
	cout<<"rent function still making"<<endl;
}
// return bike
void UBikeSys::returns(string stationName, string license, int mile){
	cout<<"returns function still making"<<endl;
}
// transfer bike to other stationName
void UBikeSys::trans(string stationName, string license){
	cout<<"trans function still making"<<endl;
}
// inquire certain bike
void UBikeSys::inquire(string license){
	cout<<"inquire function still making"<<endl;
}
// report certain stationName
void UBikeSys::stationReport(string stationName){
	cout<<"stationReport function still making"<<endl;
}
// report all bikes info
void UBikeSys::uBikeReport(){
	cout<<"uBikeReport function still making"<<endl;
}
// report money earn by the stationName
void UBikeSys::netSearch(string stationName){
	cout<<"netSearch function still making"<<endl;
}
// print binary search tree
void UBikeSys::bReport(){
	cout<<"bReport function still making"<<endl;
}