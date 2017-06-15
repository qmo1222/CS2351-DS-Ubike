#include "UBikeSys.h"

UBikeSys::UBikeSys(string fileName){
	this->fileOut.open(fileName, ifstream::out);

	int i, j;

	for (i=0; i<STATION_NUM; i++) {
		for (j=0; j<HEAP_NUM; j++){
			string station = STATIONS[i];
			string bikeClass = HEAPS[j];
			this->stationInfo[station][bikeClass];
		}
	}
}

// add new bike to company
void UBikeSys::newBike(string bikeClass, string license, int mile, string station){
	fileOut << "New bike is received by Station " << station << ".";
	fileOut << endl;
}
// remove bike from company
void UBikeSys::junkIt(string license){
	string station = "Danshui";
	fileOut << "Bike " << license << " is deleted from " << station << ".";
	// fileOut << "Bike " << license << " is now being rented."
	// fileOut << "Bike " << license << " does not belong to our company."
	fileOut << endl;
}
// rent the bike
void UBikeSys::rent(string station, string bikeClass){
	fileOut << "A bike is rented from " << station << ".";
	// fileOut << "No free bike is available."
	fileOut << endl;
}
// fileOut << bike
void UBikeSys::returns(string station, string license, int mile){
	int charge = 0;
	fileOut << "Rental charge for this bike is " << charge;
	fileOut << endl;
}
// transfer bike to other station
void UBikeSys::trans(string station, string license){
	fileOut << "Bike " << license << " is transferred to " << station;
	// fileOut << "Bike " << license << " does not belong to our company.";
	// fileOut << "Bike " << license << "is now being rented.";
	fileOut << endl;
}
// inquire certain bike
void UBikeSys::inquire(string license){
	fileOut << "Bike " << license << " does not belong to our company.";
	// fileOut << setw(15) << "License" << setw(15) << Mileage << ...
	fileOut << endl;
}
// report certain station
void UBikeSys::stationReport(string station){
	fileOut << "stationReport function still making";
	fileOut << endl;
}
// report all bikes info
void UBikeSys::uBikeReport(){
	fileOut << "uBikeReport function still making";
	fileOut << endl;
}
// report money earn by the station
void UBikeSys::netSearch(string station){
	fileOut << "netSearch function still making";
	fileOut << endl;
}
// print binary search tree
void UBikeSys::bReport(){
	fileOut << "bReport function still making";
	fileOut << endl;
}